#include <iostream>
using namespace std;

int main(){

  int n1=53, n2=72;
  int *p1=&n1, *p2=&n2;
  double n4=6.3, *p4=&n4;
  //which of the following do or don't compile?  Why or why not?
  n4 = n1;//Step 1//step 1 can compile because int and double can exchange
  //OK (int -> double, widening conversion). ��������Ϊ double��������Ϣ��

  n1 = n4;//Step 2//step 2 can compile because double and int can exchange
  //OK ���з���L:Warning (double -> int, narrowing conversion). ������תΪ���ͣ����ܶ���Ϣ�����������С�����ֻᱻ�ضϡ�

  p1 = p4;//Step 3//ERROR (int* <- double*). �ײ�ָ�����Ͳ�ͬ��������ʽ��ֵ��//��ͬ���͵�ָ�벻�ܻ��ำֵ
  //step 3 does not compile because int* and double* are different types, cannot convert between them.

  p2 = &p1;//Step 4//step 4 ERROR (int** <- int*). ָ�뼶��ͬ��������ʽ��ֵ��//��ͬ�����ָ�벻�ܻ��ำֵ
  //�����ָ�뱾��ĵ�ַ��������һ��ָ�룬���Ͳ�ƥ�䡣

  p4 = &n1;//Step 5//step 5 ERROR, does not compile because *p4 is double, while n1 is int
  //ERROR (double* <- int*). ָ��ָ�����Ͳ�ͬ��������ʽ��ֵ��//��ͬ���͵�ָ�벻�ܻ��ำֵ

  &n1 = &n2;//Step 6//step 6 ERROR, does not compile, you can't change address of int or double variables//������ַ�ǹ̶��ġ�
  //����д������Ͳ��Ϸ������ܸ�һ����ַ��ֵ��

  *p1 = *p2;//Step 7//step 7 can comepile, it equals to n1=n2
  //OK. Both are int. ��ֵ�������� int ������ֵ������ƥ�䡣
  
  return 0;
}

/*Memory diagram��
p4   [ &n4( 6.3 ����������> 53 ) ]   // Step 1 Ӱ����� n4 ��ֵ��p4 ָ�򲻱�
n4   [  6.3 ����������> 53 ]         // Step 1

p2   [ &n2( 72  ����������> 72 ) ]   // ʼ��ָ�� n2��ֵ���� 72
n2   [  72  ����������> 72 ]         // Step 5/6 ��û��Ч���˴�����

p1   [ &n1( 53  ����������> 72 ) ]   // ָ��ʼ���� n1��Step 3/6 ������û�ĳɱ�ģ�
n1   [  53  ����������> 53  ����������> 72 ]
          �� Step 2      �� Step 7
*/