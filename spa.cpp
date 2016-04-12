#include <iostream>
#include <vector>
#include <set>
#include <map>
#define ll long long
using namespace std;

map <char,int> freq;
map <char,int> weight;

void initialize(){

        for(char i='a'; i<='z'; i++) {
                freq[i] = 0;
        }
}

int main(void)
{
        int T;
        cin >> T;
        while(T--) {
                initialize();
                string s;
                cin >> s;
                float result;
                for(char i='a'; i<='z'; i++) {
                        int temp;
                        cin >> temp;
                        weight[i] = temp;
                }
                for(i=0; i<s.size(); i++) {
                        freq[s[i]] += 1;
                }

                ll prod = 1;
                ll tw = 0;
                for(int =0; i<s.size(); i++) {
                        prod = prod * (freq[s[i]]*weight[s[i]]);
                        tw += weight[s[i]];
                }
                ll tl = s.size();
                result = (10 * prod) / tl * tw;
                cout << result << endl;
        }
}
