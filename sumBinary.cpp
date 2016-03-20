#include <iostream>
using namespace std;

void printArray(int arr[],int n){
  for(int i=0;i<n;i++)
        cout << arr[i] << " ";
  cout << endl;
}

 void sumBinary(int a[],int b[],int n){

   int carry = 0;
   int sum[n+1];
   int i;
   for (i = n-1; i >= 0; i--){
     sum[i+1] = carry ^ a[i] ^ b[i];
     carry = ((a[i] & b[i]) | (a[i] & carry) | (b[i] & carry));
    //  cout << "carry " << carry << endl;
   }

   sum[i+1] = carry;
   printArray(sum,n+1);

 }

int main(void){
  int a[] = {1,1};
  int b[] = {1,1};
  int n = sizeof(a)/sizeof(a[0]);
  // cout << n << endl;
  sumBinary(a,b,n);
}
