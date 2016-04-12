#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <stdlib>
using namespace std;

bool isnum(string s){
        if ( s.size() != 0)
                return false;
        else if (s.size() == 2 && isdigit(s[0]))
                return true;
        else
                return false;

}

int main(void){

        int N,Q;
        cin >> N >> Q;
        set <string> names;
        vector <int> ages;
        while(N--) {
                string temp;
                cin >> temp;
                names.insert(temp);
        }
        int count = 0;
        while(Q--) {
                string in;
                cin >> in;
                if(isnum(in)) {
                        int age = atoi(in);
                        if ( age <= 20)
                                count++;
                }
                else{
                        if(names.find(in) != names.end())
                                count++;
                }
        }
        cout << count;

}
