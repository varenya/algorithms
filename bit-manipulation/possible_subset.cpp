#include <iostream>
#include <vector>
using namespace std;
void Convert(int val);

void possibleSubsets(char A[], int N)
{
	for(int i = 0;i < (1 << N); ++i)
	{
		for(int j = 0;j < N;++j){
			if(i & (1 << j))
				cout << A[j] << " ";
		}
		cout << endl;
	}
}

void Convert(int val)
{
	int mask = 1 << (sizeof(int) * 8 - 1);

	for(int i = 0; i < sizeof(int) * 8; i++)
	{
		if( (val & mask) == 0 )
			cout << '0' ;
		else
			cout << '1' ;

		mask  >>= 1;
	}
	cout << endl ;
}



int main(void){
	char arr[] = {'a','b','c'};
	possibleSubsets(arr,3);
}
