#include <iostream>

using namespace std;

int linearSearch(int arr[],int key,int n){
  int ans = -1;
  for(int i=0;i<n;i++){
    if(arr[i] == key){
      ans = i;
      break;
    }
  }
  return ans;
}

int main(void){

	int a[] = {6,2,1,3,5,5};
	int n = sizeof(a)/sizeof(a[0]);
  std::cout << "Found element in :" << std::endl;
  std::cout << linearSearch(a,5,n)<< std::endl;
}
