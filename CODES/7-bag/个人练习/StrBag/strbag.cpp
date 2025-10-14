#include "strbag.h"

// ===================== �������� =====================

// TODO[����ʵ��]��Ĭ�Ϲ��� ���� �� size_ ��ʼ��Ϊ 0
StrBag::StrBag() : size_(0) {}

// TODO[����ʵ��]�������鹹�� ���� ʹ�á����캯��ί�С���Ĭ�Ϲ��죻����� insert
StrBag::StrBag(string a[], size_t n) : StrBag() {
    // ��ʾ��for (size_t i=0; i<n && size_ < CAPACITY; ++i) insert(a[i]);
    for (size_t i = 0; i < n && size_ < CAPACITY; ++i) {
        insert(a[i]);
    }
}

// TODO[������]��size() �� operator[] ����ͷ�ļ�����������ɲ��ظ�ʵ��

// ===================== �޸���/��ѯ =====================

// TODO[����ʵ��]��insert
// ������δ����д�� data_[size_] �� size_++����������ֱ�ӷ��أ���������ʾ��
/// void StrBag::insert(const string& val) { ... }
void StrBag::insert(const string& val) {
    if (size_ < CAPACITY) {
        data_[size_++] = val;
    }
}

// TODO[����ʵ��]��count
// ���󣺱��� 0..size_-1������ val �ͼ��������ؼ���
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

// TODO[����ʵ��]��erase_one
// ����ֻɾ������һ�γ��֡��� val�����ҵ�λ�� pos���� [pos+1..size_-1] ͳһǰ�ƣ�size_--������ true
// ���Ҳ������� false
// ע��ǰ��ѭ��д����for (size_t i=pos; i+1<size_; ++i) data_[i]=data_[i+1];
/// bool StrBag::erase_one(const string& val) { ... }
bool StrBag::erase_one(const string& val) {
    for (size_t i = 0; i < size_; ++i) {
        if (data_[i] == val) {
            // �ҵ���һ�γ��ֵ�λ�� i
            for (size_t j = i; j + 1 < size_; ++j) {
                data_[j] = data_[j + 1]; // ǰ��
            }
            --size_; // ��С��С
            return true; // �ɹ�ɾ��
        }
    }
    return false; // δ�ҵ�
}

// TODO[����ʵ��]��erase
// ���� A��while(erase_one(val)) ++removed;    // ��
// ���� B��˫ָ�뵥����д������Ч����read д�� write��ֻ����������ֵ��
/*
size_t StrBag::erase(const string& val) {
    size_t removed = 0;
    // д�� B ��ʾ��
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
            ++removed; // ����ɾ����Ԫ��
        } else {
            data_[write++] = data_[read]; // ����Ԫ�أ�д�� write λ��
        }
    }
    size_ = write; // ���´�С
    return removed; // ����ɾ������
}

// ===================== ��������� =====================

// TODO[����ʵ��]����Ա +=
// ���󣺰� rhs ����ʵ�������� insert �� *this���������ﵽ CAPACITY ��ֹͣ������ *this
/// StrBag& StrBag::operator+=(const StrBag& rhs) { ... }
StrBag& StrBag::operator+=(const StrBag& rhs) {
    for (size_t i = 0; i < rhs.size() && size_ < CAPACITY; ++i) {
        insert(rhs[i]);
    }
    return *this;
}

// TODO[����ʵ��]���ǳ�Ա +
// ���󣺷���һ���¶���������Ϊ lhs ��� rhs���ɽ��� += ʵ�֣�
StrBag operator+(const StrBag& lhs, const StrBag& rhs) {
    StrBag sum(lhs); // ��Ҫ�ɿ�����Ĭ�Ͽ������ã�
    sum += rhs;
    return sum;
}


// TODO[����ʵ��]���ǳ�Ա <<
// ������� b ����ʵ���ݣ�[0..b.size()-1]����ÿ�����һ���ո񣻷����������֧����ʽ
ostream& operator<<(ostream& o, const StrBag& b) {
    for (size_t i = 0; i < b.size(); ++i) o << b[i] << " ";
    return o;
}

