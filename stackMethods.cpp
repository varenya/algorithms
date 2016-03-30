#include <iostream>
#include <stack>

using namespace std;


int main(){
	stack <int> s;
	for(int i=1;i<5;i++){
		s.push(i);
	}

	cout << "Size of Stack " << s.size() << endl;

	for(int i=1;i<5;i++){
		cout << s.top() << endl;
		s.pop();
	}
	if(s.empty())
		cout << "Stack is empty" << endl;
	else
		cout << "Stack is not empty" << endl;
}
