#include <iostream>
#include <set>
using namespace std;

int main(void)
{
        int T;
	cin >> T;
        while(T--) {
                int N;
                set <int> cities;
		cin >> N;
                while(N--) {
                        int x,y;
                        cin >> x >> y;
                        cities.insert(x);
                        cities.insert(y);
                }
                cout << cities.size() << endl;
        }
}
