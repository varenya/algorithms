#include <iostream>
#include <queue>
using namespace std;
#define MAX 107
int called[MAX];
int ideal[MAX];

int main()
{
	int N;
	cin >> N;
	queue <int> call;
	queue <int> idea;
	for(int i=0;i<N;i++){
		int temp;
		cin >> temp;
		call.push(temp);

	}
	for(int i=0;i<N;i++){
		int temp;
		cin >> temp;
		idea.push(temp);
	}
	int cost = 0,call_front,idea_front;
	while(!call.empty()){
		call_front = call.front();
		idea_front = idea.front();
		call.pop();
		if(call_front != idea_front){
			call.push(call_front);
		}
		else{
			idea.pop();
		}
		cost++;
	}
	cout << cost << endl;

}
