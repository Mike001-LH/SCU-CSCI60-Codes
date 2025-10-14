/*
  helloworld.cpp
  A simple program that outputs text for HW1 Part A.

  I know where this file lives on my computer:
    D:\Sublime Text\CODES\hw1\helloworld.cpp
  I compiled and ran it from the command line to confirm there are no errors:
    g++ helloworld.cpp -std=c++11 -o helloworld
	./helloworld.exe


  Name: Rentian (Mike) Dong
  Date: 2025-09-24
  Outside resources used: none.
*/
#include <iostream>
using namespace std;

int main() {
	cout << "My name is Rentian Dong, you can also call me Mike. " 
		 << "My hometown is China. "
		 << "I like to play billiards when I'm free. " 
		 << endl;
	cout << "I used to learn a little Python basics, some Java basics and learned some C++ by reading some books. " 
		 << "My strengths are persistence and careful note-taking; " 
		 << "my weaknesses are limited practice with tools like g++ and debugging. "
		 << "In order to learn CSCI 60 well, I will attend every class, spend a lot of time in note-taking, "
		 << "Write detailed comments for the code and use AI to help me explain some complex knowledge in c++"
		 << endl;
}

/*output from my terminal
lenovo@LAPTOP-5TV5FB1B /cygdrive/d/Sublime Text/CODES/hw1
$ cd /cygdrive/d/Sublime\ Text/CODES/hw1

lenovo@LAPTOP-5TV5FB1B /cygdrive/d/Sublime Text/CODES/hw1
$ g++ helloworld.cpp -std=c++11 -o helloworld

lenovo@LAPTOP-5TV5FB1B /cygdrive/d/Sublime Text/CODES/hw1
$ ./helloworld.exe
My name is Rentian Dong, you can also call me Mike. My hometown is China. I like to play billiards when I'm free.
I used to learn a little Python basics, some Java basics and learned some C++ by reading some books. My strengths are persistence and careful note-taking; my weaknesses are limited practice with tools like g++ and debugging. In order to learn CSCI 60 well, I will attend every class, spend a lot of time in note-taking, Write detailed comments for the code and use AI to help me explain some complex knowledge in c++

*/