#include <iostream>
#define ll long long
using namespace std;
#define MAX 1000007
ll arr[MAX];
ll sum[MAX];
void printArray(ll arr[],int N);

int main(){

	int T;
	cin >> T;
	while(T--){

		ll N,X;
		cin >> N >> X;
		//cout << N << " " << X << endl;
		ll temp = 0;
		for(int i=0;i<N;i++){
			cin >> arr[i];
		}

		for(int i=0;i<N+1;i++)
		{

			sum[i] = temp;
			temp += arr[i];
		}
		//printArray(arr,N);
		//printArray(sum,N+1);
		ll i=0,j=1;
		ll diff;
		bool foundSum = false;
		while(i < N+1 && j < N+1){
			diff = sum[j]-sum[i];
			if(i != j &&  diff == X ){
				foundSum = true;
				break;
			}
			else if (diff < X)
				j++;
			else
				i++;

		}
		if (foundSum)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;


	}
}

void printArray(ll arr[],int N)
{
	for(int i=0;i<N;i++)
		cout << arr[i] << " ";
	cout << endl;
}

