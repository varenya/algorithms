#include <iostream>
#include <set>
#define ll long long
using namespace std;



int main(void){

            int Q;
            multiset <ll> A;
            cin >> Q;
            while(Q--){

                      ll first,second;
                      cin >> first;
                      if(first == 1){
                            cin >> second;
                            A.insert(second);
                      }
                      else if(first == 2){
                            cin >> second;
                            multiset <ll>::iterator it;
                            it = A.find(second);
                            if(it!=A.end()){
                                A.erase(it);
                            }
                            else{
                              cout << -1 << endl;
                            }
                      }
                      else if(first == 4){
                                multiset <ll>::iterator it;
                                if(!A.empty()){
                                    it = A.begin();
                                    cout << *it << endl;
                                }
                                else{
                                    cout << -1 << endl;
                                }
                      }
                      else if(first == 3){
                                multiset <ll>::reverse_iterator it;
                                if(!A.empty()){
                                    it = A.rbegin();
                                    cout << *it << endl;
                                }
                                else{
                                    cout << -1 << endl;
                                }
                      }
            }
}
