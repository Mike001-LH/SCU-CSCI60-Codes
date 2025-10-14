#include "strbag.h"

// ============================================================
// �� ���캯����Constructors��
// ============================================================

// Ĭ�Ϲ��캯��������һ���մ���
StrBag::StrBag() : size_(0) {}

// �������Ĺ��캯�������ַ��������ʼ������
// ʹ�á����캯��ί�С��ȵ���Ĭ�Ϲ��죬���������
StrBag::StrBag(string a[], size_t n) : StrBag() {
    for (size_t i = 0; i < n && size_ < CAPACITY; ++i)
        insert(a[i]);
}

// ============================================================
// �� ��������Accessors / Getters��
// ============================================================

// ���ص�ǰ�����ַ�������
size_t StrBag::size() const {
    return size_;
}

// �±���������������ͨ�� b[i] ��ȡ�ַ���
string StrBag::operator[](size_t index) const {
    return data_[index];
}

// ͳ�� val ���ֵĴ���
size_t StrBag::count(const string& val) const {
    size_t cnt = 0;
    for (size_t i = 0; i < size_; ++i)
        if (data_[i] == val)
            ++cnt;
    return cnt;
}

// ============================================================
// �� �޸�����Mutators / Setters��
// ============================================================

// ������в������ַ���
void StrBag::insert(const string& val) {
    if (size_ < CAPACITY)            // ������δ��
        data_[size_++] = val;        // �����ַ�������������
}

// ɾ��һ��ƥ���ַ�����ֻɾ��һ����
bool StrBag::erase_one(const string& val) {
    for (size_t i = 0; i < size_; ++i) {
        if (data_[i] == val) {
            // �� i λ�ÿ�ʼ���Ѻ���Ԫ������ǰ��
            for (size_t j = i; j + 1 < size_; ++j)
                data_[j] = data_[j + 1];
            --size_;  // ������һ
            return true;
        }
    }
    return false; // û�ҵ�
}

// ɾ������ƥ����ַ���
size_t StrBag::erase(const string& val) {
    size_t removed = 0;
    size_t write = 0;
    for (size_t read = 0; read < size_; ++read) {
        if (data_[read] == val)
            ++removed;            // ����ƥ��ģ���ɾ����
        else
            data_[write++] = data_[read];  // д�ر���Ԫ��
    }
    size_ = write;
    return removed;
}

// ============================================================
// �� ��������أ�Operator Overloading��
// ============================================================

// += ��������� rhs ������Ԫ��׷�ӵ���ǰ����
StrBag& StrBag::operator+=(const StrBag& rhs) {
    for (size_t i = 0; i < rhs.size() && size_ < CAPACITY; ++i)
        insert(rhs[i]);
    return *this; // ��������������֧����ʽ����
}

// ============================================================
// �� �ǳ�Ա������Non-Member Operators��
// ============================================================

// + ��������ϲ����� StrBag�������¶���
StrBag operator+(const StrBag& lhs, const StrBag& rhs) {
    StrBag sum(lhs);   // �ȸ����������
    sum += rhs;        // ��׷���Ҳ�����
    return sum;        // �����¶���
}

// << ���������ӡ StrBag ����
ostream& operator<<(ostream& o, const StrBag& b) {
    for (size_t i = 0; i < b.size(); ++i)
        o << b[i] << " ";  // �ո�ָ����
    return o;
}
