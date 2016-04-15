#include <iostream>
using namespace std;
int main(void){
        int N;
        cin >> N;
	int size = N;
        int sum = 0;
        while(N--) {
                int temp;
                cin >> temp;
                sum += temp;
        }

	int edges = sum/2;
        if (edges == (size-1) )
                cout << "Yes" << endl;
        else
                cout << "No" << endl;
}
