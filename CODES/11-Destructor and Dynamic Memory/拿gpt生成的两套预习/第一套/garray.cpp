// garray.cpp
// Lesson 10 Ԥϰʵ�֣�insert��operator<<��~GArray���������졢operator=

#include "garray.h"

// ���� insert���½��������� -> ���������� -> ׷����ֵ -> �ͷž����� -> �ӹ�������
void GArray::insert(int val) {
    int* temp = new int[size_ + 1];          // 1) �������һ���������
    for (size_t i = 0; i < size_; ++i) {     // 2) ����������
        temp[i] = data_[i];
    }
    temp[size_] = val;                        // 3) ĩβ׷��
    ++size_;                                  // 4) �ߴ�����
    delete[] data_;                          // 5) �ͷž����飨nullptr ��ȫ��
    data_ = temp;                             // 6) ָ��������
}

// ���� ������ȴ�ӡ�ײ������ַ���ٴ�ӡ����Ԫ��
ostream& operator<<(ostream& out, const GArray& a) {
    out << "(" << a.address() << ") ";
    for (size_t i = 0; i < a.length(); ++i) out << a[i] << " ";
    return out;
}

// ���� �������ͷŶ����飬���� orphaned memory / leak
GArray::~GArray() {
    cout << "[~GArray] free heap array at " << data_ << "\n";
    delete[] data_;
    data_ = nullptr; // �ÿգ�������
}

// ���� �������죺��� other �����ݣ���ö�������Ȩ
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

// ���� ��ֵ���Ը�ֵ�������ȷ��䲢��������Դ���ɹ����滻����Դ������ *this ������ʽ
GArray& GArray::operator=(const GArray& rhs) {
    if (this == &rhs) return *this; // �Ը�ֵ��ֱ�ӷ���

    // 1) ��׼������Դ�����⡰��ɾ����䡱���������ƻ���
    int* newData = nullptr;
    if (rhs.size_ > 0) {
        newData = new int[rhs.size_];
        for (size_t i = 0; i < rhs.size_; ++i) newData[i] = rhs.data_[i];
    }

    // 2) �ɹ��� commit���滻����Դ
    cout << "[operator=] copy from " << rhs.address()
        << " -> " << newData << " (size=" << rhs.size_ << ")\n";
    delete[] data_;
    data_ = newData;
    size_ = rhs.size_;

    return *this; // ֧�� a = b = c;
}
