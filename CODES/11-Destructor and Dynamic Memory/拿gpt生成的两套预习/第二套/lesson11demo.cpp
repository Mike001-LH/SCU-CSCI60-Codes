// lesson11_demo.cpp
// A self-contained tutorial program for "Destructor & Dynamic Memory" (+ Rule of Three)
// Sections:
//   lesson1: destructor basics
//   lesson2: copy constructor (deep copy)
//   lesson3: copy assignment operator (deep copy, self-assignment, chaining)
//   lesson4: pass-by-value & return-by-value (when copy-ctor/destructor run)
//   lesson5: shallow copy trap (explained with #if 0 block to avoid crash)
//   lesson6: orphaned memory vs dangling pointer (and why set pointer to nullptr)
//
// Build: g++ -std=c++17 -O0 -g lesson11_demo.cpp -o lesson11_demo
// Run:   ./lesson11_demo

//中文翻译:
// lesson11_demo.cpp
// "析构函数与动态内存"（以及三法则）的自包含教程程序
// 部分：
//   lesson1: 析构函数基础
//   lesson2: 拷贝构造函数（深拷贝）
//   lesson3: 拷贝赋值运算符（深拷贝，自我赋值，链式赋值）
//   lesson4: 按值传递与按值返回（拷贝构造函数/析构函数的运行时机）
//   lesson5: 浅拷贝陷阱（用#if 0块解释以避免崩溃）
//   lesson6: 孤立内存与悬空指针（以及为何将指针设为nullptr）

#include <iostream>// for cout, endl
#include <cstddef>// for size_t
#include <utility>// for std::move (not used here, but often relevant in Rule of Five)

using std::cout;
using std::endl;

// A teaching class that owns a dynamic int array.//一个拥有动态整数数组的教学类。
// Focus: correct heap management + verbose logs.// 重点：正确的堆内存管理 + 详细日志。
class DynArray {
public:
    // ---- Rule of Three members ----
	//Rule of Three member指的是：析构函数（destructor）、拷贝构造函数（copy constructor）和拷贝赋值运算符（copy assignment operator）。当一个类管理动态内存或其他资源时，遵循三法则是非常重要的，以确保资源的正确分配和释放，避免内存泄漏和悬空指针等问题。
    
	// Default constructor: create an empty array
    DynArray() : size_(0), data_(nullptr) {}//这是默认构造函数，0参，将size设为0，data设为nullptr

    // Copy constructor: deep copy
    //Copy constructor的写法为：ClassName(const ClassName& other)
	//其中ClassName是类名，other是要拷贝的已有对象的常量引用。
	//作用是创建一个新对象，并将已有对象的内容深拷贝到新对象中，确保两个对象拥有独立的动态内存空间，从而避免共享内存带来的问题。
	//实现逻辑在于：创建一个新的动态数组，并逐个复制已有对象的元素到新数组中，确保新对象拥有独立的内存空间，避免把地址给复制过去。
	DynArray(const DynArray& other) : size_(other.size_), data_(nullptr) {
    //other是要拷贝的已有对象的常量引用，size_(other.size_), data_(nullptr)是初始化列表，将新对象的size_设置为other对象的size_，data_初始化为nullptr
		if (size_ > 0) {//如果size_大于0，表示有动态数组需要拷贝
			data_ = new int[size_];//在堆上分配新的动态数组内存
            for (size_t i = 0; i < size_; ++i) data_[i] = other.data_[i];
        }
        else {//如果size_为0，表示没有动态数组，data_保持为nullptr
			data_ = nullptr;
        }
    }

    // Copy assignment: deep copy + self-assignment guard + chaining
    // 赋值运算：深拷贝 + 自赋值防御 + 链式返回
	//这里的rhs和lhs用人话说就是传入的右侧对象和左侧对象//左侧对象是被赋值的对象，右侧对象是赋值给左侧对象的另一个对象
	DynArray& operator=(const DynArray& rhs) {//这是拷贝赋值运算符的定义，rhs是右侧对象的常量引用
        if (this == &rhs) return *this;            // 自赋值保护
		//this是当前对象的指针，&rhs是rhs对象的地址，如果两者相等，说明是自赋值，直接返回当前对象的引用，不做任何操作//当前对象是被赋值的对象，rhs是赋值给当前对象的另一个对象
        int* newData = nullptr;                    // 1) 准备新资源
		//先创建一个新的指针newData，初始化为nullptr，准备接管新资源
		if (rhs.size_ > 0) {//如果rhs对象的size_大于0，表示有动态数组需要拷贝
			newData = new int[rhs.size_];//在堆上分配新的动态数组内存（rhs.size_是因为rhs作为传入的值，不属于类内，需要）
			for (size_t i = 0; i < rhs.size_; ++i) newData[i] = rhs.data_[i];//逐个复制rhs对象的动态数组内容到新数组中
        }
        delete[] data_;                            // 2) 释放旧资源
        data_ = newData;                           // 3) 接管新资源
		size_ = rhs.size_;//更新size_为传入的rhs对象的size_
        return *this;                              // 4) 支持 a = b = c;
    }

    // 析构：释放堆数组，置空指针防悬垂
    ~DynArray() {
		delete[] data_;//释放data_指向的动态数组内存，防止内存泄漏
		data_ = nullptr;//将data_指针设置为nullptr，防止悬空指针问题
		size_ = 0;//将size_设为0，表示数组已被销毁
    }

    // 在尾部插入：新建更大数组 -> 拷贝旧数据 -> 追加 -> 释放旧数组 -> 接管新数组
    void push_back(int v) {
        int* temp = new int[size_ + 1];
        for (size_t i = 0; i < size_; ++i) temp[i] = data_[i];
        temp[size_] = v;
        delete[] data_;
        data_ = temp;
        ++size_;
    }

    // 只读接口
    size_t size() const { return size_; }
    const int* data() const { return data_; }
    int operator[](size_t i) const { return data_[i]; }

    // 简单打印：显示地址与内容（便于观察是否共享内存）
    void print(const char* name) const {
        cout << name << ": (" << data_ << ") ";
        for (size_t i = 0; i < size_; ++i) cout << data_[i] << " ";
        cout << endl;
    }

private:
    size_t size_;
    int* data_;
};

// lesson4 用：按值传参/返回（可能触发拷贝构造；是否省略取决于优化）
DynArray passByValueAndReturn(DynArray x) {
    x.push_back(999);
    return x;
}

// ─────────────────────────────────────────────────────────────────────────────
// lesson1: destructor basics
// 目标：对象离开作用域自动调用析构，释放堆内存；指针置空防悬垂。
void lesson1_destructor_basics() {
    cout << "\n=== lesson1: destructor basics ===\n";
    {
        DynArray a;
        a.push_back(1);
        a.push_back(2);
        a.print("a");
        // 这里离开作用域时，a 析构自动释放堆数组
    }
    cout << "done lesson1\n";
}

// ─────────────────────────────────────────────────────────────────────────────
// lesson2: copy constructor (deep copy)
// 目标：新对象用旧对象初始化时进行深拷贝；修改其中一个不影响另一个。
void lesson2_copy_constructor() {
    cout << "\n=== lesson2: copy constructor (deep copy) ===\n";
    DynArray a;
    a.push_back(10);
    a.push_back(20);
    a.print("a");

    DynArray b(a);  // 调用拷贝构造（深拷贝）
    b.print("b(after copy)");
    b.push_back(30);

    a.print("a(unchanged)");
    b.print("b(+30 only)");
    cout << "done lesson2\n";
}

// ─────────────────────────────────────────────────────────────────────────────
// lesson3: copy assignment operator
// 目标：已存在对象被赋值时深拷贝；自赋值不破坏；链式赋值按右到左进行。
void lesson3_assignment_operator() {
    cout << "\n=== lesson3: operator= (deep copy, self-assign, chaining) ===\n";
    DynArray a; a.push_back(1); a.push_back(2);
    DynArray b; b.push_back(7); b.push_back(7); b.push_back(7);
    DynArray c; c.push_back(42);

    a.print("a"); b.print("b"); c.print("c");

    b = a;     // 深拷贝赋值
    a.print("a"); b.print("b(after = a)");

    b = b;     // 自赋值：应当什么也不发生
    b.print("b(self-assign)");

    c = b = a; // 链式赋值：先 b = a; 再 c = b;
    a.print("a"); b.print("b"); c.print("c(after chain)");
    cout << "done lesson3\n";
}

// ─────────────────────────────────────────────────────────────────────────────
// lesson4: pass-by-value & return-by-value
// 目标：按值传参/返回可能触发拷贝构造；返回值优化可能省略临时拷贝。
void lesson4_pass_and_return() {
    cout << "\n=== lesson4: pass-by-value & return-by-value ===\n";
    DynArray a; a.push_back(5); a.push_back(6);
    a.print("a(before)");
    DynArray d = passByValueAndReturn(a);
    d.print("d(returned)");
    cout << "done lesson4\n";
}

// ─────────────────────────────────────────────────────────────────────────────
// lesson5: shallow copy trap（概念说明；禁用代码避免崩溃）
#if 0
class Shallow {
public:
    Shallow(size_t n) : n_(n), p_(n ? new int[n] : nullptr) {}
    // ❌ 未定义拷贝构造与赋值 → 编译器做“浅拷贝”（仅复制指针值）
    ~Shallow() { delete[] p_; }
private:
    size_t n_;
    int* p_;
};

void lesson5_shallow_copy_trap() {
    Shallow s1(3);
    Shallow s2 = s1; // s2.p_ == s1.p_，两个析构器都会 delete[] 同一块内存 → 崩溃
}
#endif

void lesson5_explain_only() {
    cout << "\n=== lesson5: shallow copy trap (explain only) ===\n";
    cout << "If a class owns heap memory but lacks copy-ctor/operator=,\n"
        "the compiler does a shallow copy (copy the pointer value only).\n"
        "Two objects then share the same heap block; both destructors delete it → double free.\n";
    cout << "Rule of Three: define destructor, copy-ctor, and copy assignment when owning resources.\n";
    cout << "done lesson5\n";
}

// ─────────────────────────────────────────────────────────────────────────────
// lesson6: orphaned memory vs dangling pointer
// 目标：区分“孤儿内存”（泄漏）与“悬空指针”（已释放但仍指向旧地址）。
void lesson6_orphan_vs_dangling() {
    cout << "\n=== lesson6: orphaned memory vs dangling pointer ===\n";
    // Orphaned memory（泄漏）：丢失最后一个指针前没有 delete[]
    {
        int* p = new int[2] {1, 2};
        // 错误示范：直接把指针丢掉（置空）而不 delete[]，导致泄漏
        p = nullptr;
    }
    // Dangling pointer（悬空）：delete[] 后指针仍保存旧地址
    {
        int* q = new int[2] {3, 4};
        delete[] q;    // 已释放
        // 这里 q 仍然是旧地址 → 悬空。修复：置 nullptr
        q = nullptr;
    }
    cout << "done lesson6\n";
}

// ─────────────────────────────────────────────────────────────────────────────
int main() {
    cout << "===== Destructor & Dynamic Memory (Rule of Three) — No Logging =====\n";
    lesson1_destructor_basics();
    lesson2_copy_constructor();
    lesson3_assignment_operator();
    lesson4_pass_and_return();
    lesson5_explain_only();
    lesson6_orphan_vs_dangling();
    cout << "\n[END]\n";
    return 0;
}