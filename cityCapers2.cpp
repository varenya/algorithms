#include <iostream>
#include <cstring>
#include <set>
#include <vector>
#include <algorithm>
#include <climits>
#include <utility>
#define MAX 100007
#define ll long long
int arr[MAX];
int size[MAX];
using namespace std;
struct cmp
{
	bool operator() (const pair<int, int>& a, const pair<int, int>& b)
	{
		return a.second < b.second;
	}
};

void printVector(multiset < pair<int,int> , cmp> input);

multiset < pair<int,int> , cmp > sizes;


void initialize(int N){
	for(int i=1;i<=N;i++){
		arr[i] = i;
		size[i] = 1;
		sizes.insert(make_pair(i,1));
	}
}


int root(int i){

	if (root[i] != i)
				root[i] = root(root[i]);
	return root[i];

}

bool find(int A,int B){
	return root(A) == root(B);
}

void swap(int a,int b){
	int temp = size[a];
	size[a] = size[b];
	size[b] = temp;
}

void union_set(int N,int A,int B){

	int root_A = root(A);
	int root_B = root(B);
	if ( root_A == root_B )
		return;
	if ( size[root_B] > size[root_A] )
		swap(root_A,root_B);

	/*cout << "Before Union " << endl;
	printVector(sizes);
	cout << endl;


	cout << root_A << " " << size[root_A] << endl;
	cout << root_B << " " << size[root_B] << endl;

	cout << endl;
	*/

	sizes.erase(sizes.find(make_pair(root_A,size[root_A])));
	sizes.erase(sizes.find(make_pair(root_B,size[root_B])));

	//cout << "Union " << endl;
	//printVector(sizes);
	//cout << "After union" << endl;

	//cout << "here 1!" << endl;
	size[root_A] += size[root_B];
	arr[root_B] = root_A;

	sizes.insert(make_pair(root_A,size[root_A]));

}

void printArray(int N){
	for(int i=0;i<N;i++)
		cout << arr[i] << " ";
	cout << endl;
}
void printVector(multiset < pair<int,int> , cmp> input){
	multiset < pair<int,int> , cmp> :: iterator it;
	for(it = input.begin();it!=input.end();it++)
		cout << it->first << " " << it->second << " ";
	cout << endl;
}

ll getSetDifference(){
	ll mindiff = 0;
	multiset< pair<int,int> >::iterator it;
	for(it = sizes.begin();it!=sizes.end();it++)
		mindiff = min( mindiff, ((it+1)->second - it->second) );
	return mindiff;
}

int getDifference(int N){

	ll diff = 0;
	ll min_item=LONG_MAX,max_item=LONG_MIN;
	vector <ll> unique;
	for(int i=1;i<=N;i++){

		ll count = 0;
		for(int j=1;j<=N;j++){
			if(root(j) == i)
				count ++;
		}
		if (count){
			if(count > max_item)
				max_item = count;
			if(count < min_item)
				min_item = count;
		}
	}
	diff = max_item - min_item;
	return diff;
}



int main(void){

	memset(arr,0,sizeof arr);
	int N,Q;
	cin >> N >> Q;
	initialize(N);
	while(Q--){
		int i,j;
		cin >> i >> j;
		//cout << i << j << endl;
		union_set(N,i,j);
		cout << getSetDifference() << endl;
	}
//	printArray(N);



}
