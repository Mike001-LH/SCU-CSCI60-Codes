
#include <fstream>//Note - -for ifstream
#include <iostream>
#include <cstdlib>//Note - for exit
using namespace std;
int main( )
{

    ifstream in_stream;//1:  Declare stream variable
    in_stream.open("infile.txt");//2:  Connect stream variable to file
    if(in_stream.fail())//3:  Check to make sure the connection was successful
    {
        cout<< "Input file opening failed.  \n";
        exit(1);
    }
    //4:  do stuff!
    int n;
    while(in_stream>>n){
        cout<<n<<endl;
    }
    in_stream.close( );//5:  Close connection


 return 0;
}
