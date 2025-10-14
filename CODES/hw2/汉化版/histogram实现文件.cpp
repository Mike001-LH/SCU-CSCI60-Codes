// CSCI 60 作业2 实现文件 —— Histogram 类的成员函数实现
// 本文件实现所有接口函数；请勿更改函数名与参数
// 作者：你的名字  日期：2025/10/8

#include "histogram.h"

// step1: 无参构造函数 —— 初始化所有频率为 0
Histogram::Histogram() {
    for (size_t i = 0; i <= MAX; ++i) {
        counts[i] = 0; // 把所有元素清零
    }
}

// step2: 1参构造 —— 从文件读取整数并计数
Histogram::Histogram(string filename) {
    // 初始化
    for (size_t i = 0; i <= MAX; ++i) counts[i] = 0;

    ifstream fin(filename); // 打开文件
    int val;
    while (fin >> val) {
        // 确保读到的值在合法范围内
        if (val >= 0 && val <= (int)MAX) {
            counts[val]++; // 把该值出现次数+1
        }
        // 否则跳过该数
    }
    fin.close(); // 关闭文件
}

// step3: 基础统计函数实现
size_t Histogram::size() const {
    size_t total = 0;
    for (size_t i = 0; i <= MAX; ++i)
        total += counts[i]; // 所有频率相加得到总数
    return total;
}

// step3.2: min() —— 找到第一个出现次数>0的值
size_t Histogram::min() const {
    for (size_t i = 0; i <= MAX; ++i)
        if (counts[i] > 0) return i;
    return MAX + 1; // 空直方图返回特殊标志
}

// step3.3: max() —— 从大到小找第一个出现次数>0的值
size_t Histogram::max() const {
    for (int i = (int)MAX; i >= 0; --i)
        if (counts[i] > 0) return (size_t)i;
    return MAX + 1;
}

// step4: mode() —— 找出现次数最多的值
size_t Histogram::mode() const {
    size_t best = 0, value = 0;
    for (size_t i = 0; i <= MAX; ++i) {
        if (counts[i] > best) {
            best = counts[i];
            value = i;
        }
    }
    return value;
}

// step5: median() —— 求中位数（奇偶分开处理）
size_t Histogram::median() const {
    size_t total = size();
    if (total == 0) return MAX + 1;

    if (total % 2 == 1) {
        // 奇数个数据
        size_t mid = total / 2;
        size_t cum = 0;
        for (size_t i = 0; i <= MAX; ++i) {
            cum += counts[i];
            if (cum > mid) return i;
        }
    } else {
        // 偶数个数据
        size_t left = total / 2 - 1;
        size_t right = total / 2;
        size_t cum = 0, a = 0, b = 0;
        for (size_t i = 0; i <= MAX; ++i) {
            cum += counts[i];
            if (cum > left && a == 0) a = i;
            if (cum > right) { b = i; break; }
        }
        return (a + b) / 2;
    }
    return MAX + 1; // 理论不会到这，但防止警告
}

// step6: mean() —— 平均值 = 加权和 / 总数
double Histogram::mean() const {
    size_t total = size();
    if (total == 0) return 0.0;

    double sum = 0.0;
    for (size_t i = 0; i <= MAX; ++i)
        sum += i * counts[i];
    return sum / total;
}

// step7: variance() —— 方差 = 平方差平均
double Histogram::variance() const {
    size_t total = size();
    if (total == 0) return 0.0;

    double mu = mean();
    double sumSq = 0.0;
    for (size_t i = 0; i <= MAX; ++i)
        sumSq += (i - mu) * (i - mu) * counts[i];
    return sumSq / total;
}

// step8.1: 重载 += —— 合并两个直方图
void Histogram::operator +=(const Histogram& rhs) {
    for (size_t i = 0; i <= MAX; ++i)
        counts[i] += rhs.counts[i]; // 对应项相加
}

// step8.2: 重载 [] —— 访问指定值的出现次数
size_t Histogram::operator [](size_t val) const {
    if (val > MAX) return 0;
    return counts[val];
}

// step8.3: 重载 << —— 打印整个直方图
ostream& operator<<(ostream& out, const Histogram& h) {
    for (size_t i = 0; i <= Histogram::MAX; ++i) {
        if (h[i] > 0) {
            out << i << ": ";
            for (size_t j = 0; j < h[i]; ++j)
                out << '*';
            out << endl;
        }
    }
    return out; // 支持链式输出 cout << h1 << h2;
}
