#include <iostream>
using namespace std;

int main(){
  //Draw the memory picture for the code below, up until the next comment
  int * p1, n1=53, *p2, n2=72, *p3;
  
  //Step 1:  Draw a picture of the memory at this point
  p1 = &n1;
  //Step 2:  Draw a picture of the memory at this point
  p2 = &n2;
  //Step 3:  Draw a picture of the memory at this point
  p3 = p1;
  //Step 4:  Draw a picture of the memory at this point
  *p3 = 35;
  //Step 5:  Draw a picture of the memory at this point
  n2 = 21;
  //Step 6:  Draw a picture of the memory at this point
  p1=&n2;
  //Step 7:  Draw a picture of the memory at this point
  //Write down what will be printed by the line of code below
  cout<<"n1= "<<n1<<", n2= "<<n2<<", *p1= "<<*p1<<", *p2= "<<*p2<<", *p3= "<<*p3<<endl;

  return 0;
}

/*Memory diagram：
p3  [ &n1( 53 ─────> 35 ) ]     // Step 3 初始与 p1 同指向 n1，Step 4 n1 值被改为 35
p2  [ &n2( 72 ─────> 21 ) ]     // Step 2 指向 n2，Step 5 n2 变 21
n2  [  72 ─────> 21 ]           // Step 5
p1  [ &n1( 53 ─────> 35 ) ─────> &n2( 21 ) ] // Step 1→6：先指 n1 后改指 n2
n1  [  53 ─────> 35 ]           // Step 4
*/