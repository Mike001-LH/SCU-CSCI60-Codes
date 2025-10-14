#include "strbag.h"

// ===================== 基础功能 =====================

// TODO[必须实现]：默认构造 —— 把 size_ 初始化为 0
StrBag::StrBag() : size_(0) {}

// TODO[必须实现]：带数组构造 —— 使用“构造函数委托”到默认构造；再逐个 insert
StrBag::StrBag(string a[], size_t n) : StrBag() {
    // 提示：for (size_t i=0; i<n && size_ < CAPACITY; ++i) insert(a[i]);
    for (size_t i = 0; i < n && size_ < CAPACITY; ++i) {
        insert(a[i]);
    }
}

// TODO[已内联]：size() 与 operator[] 已在头文件内联，这里可不重复实现

// ===================== 修改器/查询 =====================

// TODO[必须实现]：insert
// 需求：若未满，写入 data_[size_] 后 size_++；若已满，直接返回（或可输出提示）
/// void StrBag::insert(const string& val) { ... }
void StrBag::insert(const string& val) {
    if (size_ < CAPACITY) {
        data_[size_++] = val;
    }
}

// TODO[必须实现]：count
// 需求：遍历 0..size_-1，等于 val 就计数；返回计数
/// size_t StrBag::count(const string& val) const { ... }
size_t StrBag::count(const string& val) const {
    size_t cnt = 0;
    for (size_t i = 0; i < size_; ++i) {
        if (data_[i] == val) {
            ++cnt;
        }
    }
    return cnt;
}

// TODO[必须实现]：erase_one
// 需求：只删除“第一次出现”的 val：先找到位置 pos；将 [pos+1..size_-1] 统一前移；size_--；返回 true
// 若找不到返回 false
// 注意前移循环写法：for (size_t i=pos; i+1<size_; ++i) data_[i]=data_[i+1];
/// bool StrBag::erase_one(const string& val) { ... }
bool StrBag::erase_one(const string& val) {
    for (size_t i = 0; i < size_; ++i) {
        if (data_[i] == val) {
            // 找到第一次出现的位置 i
            for (size_t j = i; j + 1 < size_; ++j) {
                data_[j] = data_[j + 1]; // 前移
            }
            --size_; // 减小大小
            return true; // 成功删除
        }
    }
    return false; // 未找到
}

// TODO[必须实现]：erase
// 做法 A：while(erase_one(val)) ++removed;    // 简单
// 做法 B：双指针单趟重写（更高效）：read 写到 write，只拷贝“保留值”
/*
size_t StrBag::erase(const string& val) {
    size_t removed = 0;
    // 写法 B 提示：
    // size_t write = 0;
    // for (size_t read=0; read<size_; ++read) {
    //     if (data_[read] == val) ++removed; else data_[write++] = data_[read];
    // }
    // size_ = write;
    // return removed;
}
*/
size_t StrBag::erase(const string& val) {
    size_t removed = 0;
    size_t write = 0;
    for (size_t read = 0; read < size_; ++read) {
        if (data_[read] == val) {
            ++removed; // 计数删除的元素
        } else {
            data_[write++] = data_[read]; // 保留元素，写入 write 位置
        }
    }
    size_ = write; // 更新大小
    return removed; // 返回删除数量
}

// ===================== 运算符重载 =====================

// TODO[必须实现]：成员 +=
// 需求：把 rhs 的真实内容依次 insert 到 *this；若容量达到 CAPACITY 就停止；返回 *this
/// StrBag& StrBag::operator+=(const StrBag& rhs) { ... }
StrBag& StrBag::operator+=(const StrBag& rhs) {
    for (size_t i = 0; i < rhs.size() && size_ < CAPACITY; ++i) {
        insert(rhs[i]);
    }
    return *this;
}

// TODO[必须实现]：非成员 +
// 需求：返回一个新对象，其内容为 lhs 后接 rhs（可借助 += 实现）
StrBag operator+(const StrBag& lhs, const StrBag& rhs) {
    StrBag sum(lhs); // 需要可拷贝（默认拷贝够用）
    sum += rhs;
    return sum;
}


// TODO[必须实现]：非成员 <<
// 需求：输出 b 的真实内容（[0..b.size()-1]），每个后跟一个空格；返回输出流以支持链式
ostream& operator<<(ostream& o, const StrBag& b) {
    for (size_t i = 0; i < b.size(); ++i) o << b[i] << " ";
    return o;
}

