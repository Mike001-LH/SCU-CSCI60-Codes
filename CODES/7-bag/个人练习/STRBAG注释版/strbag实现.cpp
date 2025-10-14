#include "strbag.h"

// ============================================================
// ① 构造函数（Constructors）
// ============================================================

// 默认构造函数：创建一个空袋子
StrBag::StrBag() : size_(0) {}

// 带参数的构造函数：用字符串数组初始化袋子
// 使用“构造函数委托”先调用默认构造，再逐个插入
StrBag::StrBag(string a[], size_t n) : StrBag() {
    for (size_t i = 0; i < n && size_ < CAPACITY; ++i)
        insert(a[i]);
}

// ============================================================
// ② 访问器（Accessors / Getters）
// ============================================================

// 返回当前袋中字符串数量
size_t StrBag::size() const {
    return size_;
}

// 下标访问运算符：允许通过 b[i] 读取字符串
string StrBag::operator[](size_t index) const {
    return data_[index];
}

// 统计 val 出现的次数
size_t StrBag::count(const string& val) const {
    size_t cnt = 0;
    for (size_t i = 0; i < size_; ++i)
        if (data_[i] == val)
            ++cnt;
    return cnt;
}

// ============================================================
// ③ 修改器（Mutators / Setters）
// ============================================================

// 向袋子中插入新字符串
void StrBag::insert(const string& val) {
    if (size_ < CAPACITY)            // 若袋子未满
        data_[size_++] = val;        // 插入字符串并自增计数
}

// 删除一个匹配字符串（只删第一个）
bool StrBag::erase_one(const string& val) {
    for (size_t i = 0; i < size_; ++i) {
        if (data_[i] == val) {
            // 从 i 位置开始，把后面元素依次前移
            for (size_t j = i; j + 1 < size_; ++j)
                data_[j] = data_[j + 1];
            --size_;  // 数量减一
            return true;
        }
    }
    return false; // 没找到
}

// 删除所有匹配的字符串
size_t StrBag::erase(const string& val) {
    size_t removed = 0;
    size_t write = 0;
    for (size_t read = 0; read < size_; ++read) {
        if (data_[read] == val)
            ++removed;            // 跳过匹配的（即删除）
        else
            data_[write++] = data_[read];  // 写回保留元素
    }
    size_ = write;
    return removed;
}

// ============================================================
// ④ 运算符重载（Operator Overloading）
// ============================================================

// += 运算符：将 rhs 的所有元素追加到当前对象
StrBag& StrBag::operator+=(const StrBag& rhs) {
    for (size_t i = 0; i < rhs.size() && size_ < CAPACITY; ++i)
        insert(rhs[i]);
    return *this; // 返回自身引用以支持链式调用
}

// ============================================================
// ⑤ 非成员函数（Non-Member Operators）
// ============================================================

// + 运算符：合并两个 StrBag，返回新对象
StrBag operator+(const StrBag& lhs, const StrBag& rhs) {
    StrBag sum(lhs);   // 先复制左操作数
    sum += rhs;        // 再追加右操作数
    return sum;        // 返回新对象
}

// << 运算符：打印 StrBag 内容
ostream& operator<<(ostream& o, const StrBag& b) {
    for (size_t i = 0; i < b.size(); ++i)
        o << b[i] << " ";  // 空格分隔输出
    return o;
}
