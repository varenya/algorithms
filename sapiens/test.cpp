#include <iostream>
using namespace std;
class complex{
      double re;
      double im;
 public:
     complex() : re(0), im(0) {}
     complex(double n) { re=n, im=n;};
     complex(int m, int n) { re=m, im=n;}
     void print() { cout<<re; cout<<im;}
};
void main(){
     complex c3;
     dobule i=5;
     c3=i;
     c3,print();
}
