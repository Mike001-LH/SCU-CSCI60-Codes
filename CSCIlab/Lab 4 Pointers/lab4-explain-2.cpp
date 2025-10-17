#include <iostream>
using namespace std;

int main(){

  int n1=53, n2=72;
  int *p1=&n1, *p2=&n2;
  double n4=6.3, *p4=&n4;
  //which of the following do or don't compile?  Why or why not?
  n4 = n1;//Step 1//step 1 can compile because int and double can exchange
  //OK (int -> double, widening conversion). 整型提升为 double，不丢信息。

  n1 = n4;//Step 2//step 2 can compile because double and int can exchange
  //OK 但有风险L:Warning (double -> int, narrowing conversion). 浮点型转为整型，可能丢信息。例如这里的小数部分会被截断。

  p1 = p4;//Step 3//ERROR (int* <- double*). 底层指针类型不同，不能隐式赋值。//不同类型的指针不能互相赋值
  //step 3 does not compile because int* and double* are different types, cannot convert between them.

  p2 = &p1;//Step 4//step 4 ERROR (int** <- int*). 指针级别不同，不能隐式赋值。//不同级别的指针不能互相赋值
  //这里把指针本身的地址赋给了另一个指针，类型不匹配。

  p4 = &n1;//Step 5//step 5 ERROR, does not compile because *p4 is double, while n1 is int
  //ERROR (double* <- int*). 指针指向类型不同，不能隐式赋值。//不同类型的指针不能互相赋值

  &n1 = &n2;//Step 6//step 6 ERROR, does not compile, you can't change address of int or double variables//变量地址是固定的。
  //这种写法本身就不合法，不能给一个地址赋值。

  *p1 = *p2;//Step 7//step 7 can comepile, it equals to n1=n2
  //OK. Both are int. 赋值的是两个 int 变量的值，类型匹配。
  
  return 0;
}

/*Memory diagram：
p4   [ &n4( 6.3 ─────> 53 ) ]   // Step 1 影响的是 n4 的值，p4 指向不变
n4   [  6.3 ─────> 53 ]         // Step 1

p2   [ &n2( 72  ─────> 72 ) ]   // 始终指向 n2，值保持 72
n2   [  72  ─────> 72 ]         // Step 5/6 都没生效，此处不变

p1   [ &n1( 53  ─────> 72 ) ]   // 指向始终是 n1（Step 3/6 都报错没改成别的）
n1   [  53  ─────> 53  ─────> 72 ]
          ↑ Step 2      ↑ Step 7
*/