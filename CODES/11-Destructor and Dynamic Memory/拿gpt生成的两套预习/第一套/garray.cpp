// garray.cpp
// Lesson 10 预习实现：insert、operator<<、~GArray、拷贝构造、operator=

#include "garray.h"

// —— insert：新建更大数组 -> 拷贝旧数据 -> 追加新值 -> 释放旧数组 -> 接管新数组
void GArray::insert(int val) {
    int* temp = new int[size_ + 1];          // 1) 分配更大一格的新数组
    for (size_t i = 0; i < size_; ++i) {     // 2) 拷贝旧数据
        temp[i] = data_[i];
    }
    temp[size_] = val;                        // 3) 末尾追加
    ++size_;                                  // 4) 尺寸自增
    delete[] data_;                          // 5) 释放旧数组（nullptr 安全）
    data_ = temp;                             // 6) 指向新数组
}

// —— 输出：先打印底层数组地址，再打印所有元素
ostream& operator<<(ostream& out, const GArray& a) {
    out << "(" << a.address() << ") ";
    for (size_t i = 0; i < a.length(); ++i) out << a[i] << " ";
    return out;
}

// —— 析构：释放堆数组，避免 orphaned memory / leak
GArray::~GArray() {
    cout << "[~GArray] free heap array at " << data_ << "\n";
    delete[] data_;
    data_ = nullptr; // 置空，防悬垂
}

// —— 拷贝构造：深拷贝 other 的数据，获得独立所有权
GArray::GArray(const GArray& other)
    : size_(other.size_), data_(nullptr)
{
    if (size_ > 0) {
        data_ = new int[size_];
        for (size_t i = 0; i < size_; ++i) data_[i] = other.data_[i];
    }
    cout << "[Copy Ctor] from " << other.address()
        << " -> " << data_ << " (size=" << size_ << ")\n";
}

// —— 赋值：自赋值防御；先分配并拷贝新资源，成功后替换老资源；返回 *this 便于链式
GArray& GArray::operator=(const GArray& rhs) {
    if (this == &rhs) return *this; // 自赋值：直接返回

    // 1) 先准备新资源（避免“先删后分配”导致自我破坏）
    int* newData = nullptr;
    if (rhs.size_ > 0) {
        newData = new int[rhs.size_];
        for (size_t i = 0; i < rhs.size_; ++i) newData[i] = rhs.data_[i];
    }

    // 2) 成功后 commit：替换旧资源
    cout << "[operator=] copy from " << rhs.address()
        << " -> " << newData << " (size=" << rhs.size_ << ")\n";
    delete[] data_;
    data_ = newData;
    size_ = rhs.size_;

    return *this; // 支持 a = b = c;
}
