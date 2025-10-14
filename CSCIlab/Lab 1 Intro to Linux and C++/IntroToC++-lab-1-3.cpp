#include <iostream>
using namespace std;

bool is_even(int n){
  bool result = n%2==0;
  return result;
}

int num_evens(int a[], int s){
  int result = 0;
  for(int i=0; i<s; i++){
    if(is_even(a[i]))
      result++;
  }
  return result;
}
void fill(int a[], int s, int value){
  for(int i=0; i<s; i++){
    a[i]=value;
  }
  value = 55;
}

int main(){
  int arr[] = {11, 4, 2, 8, 33, 32, 61, 97};
  int n = num_evens(arr, 8);

  cout<<n<<endl;
  cout<<"Enter numbers, or -1 when done"<<endl;
  int in, i=0;
  cin>>in;
  while(in != -1 && i<8){  arr[i]=in; cin>>in; i=i+1;}
  string guess[] = {"Shweta", "June", "Yu Yang", "Jason", "Miguel", "Sorya",
                  "Susan", "Rohan"};
  double winnings = 12.79;
  n=num_evens(arr, i);
  if(n==i){
    cout<<"All!"<<endl;
    winnings =winnings+3.12;
  }
  else if(n==0){
    cout <<"None!"<<endl;
    winnings += 4.33;
  }else{cout<<"no extra winnings"<<endl;}
  cout<<"Winner: "<<guess[i]<<" wins "<<winnings<<endl;
  
  return 0;
}
