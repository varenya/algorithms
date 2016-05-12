#include <iostream>
using namespace std;
class test {
	char *ptr;
	test() { prt = new char[SIZE];}
	~test() {           
		try {
			free prt;
		}
		catch(..){
			throw exception;
		}
	}
};
int main(void){
	unsigned char a=25;
	a= ~a;
	signed char b=25;
	b= ~b;
	test = new test();
	cout<<(int)a<<" "<<(int)b<<endl;
}
