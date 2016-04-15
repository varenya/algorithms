#include <iostream>
#include <vector>
#define ll long long


using namespace std;
#define eps 1e-9
ll eval_function(ll x);
const ll MAX = 1000000;

ll a,b,c,d,k;

ll binary_search(ll low,ll high){


  ll mid,ans=0;
  while(low < high){
	 // cout << low << " " << high << " " << mid << endl;
   mid = low + (high-low+1)/2;

          if(eval_function(mid) <= k){
                low = mid;
          }
          else{
                high = mid-1;
          }

  }

  return low;

}



ll eval_function(ll t)
{
   double T = t;
   double tmp =  a*T*T*T + b*T*T + c*T + d;
   if(tmp + eps > 1e18 )
   return k+1;
   return a*t*t*t + b*t*t + c*t + d;
}
int main(void){

        int T;
        cin >> T;
        while(T--) {

                cin >> a >> b >> c >> d >> k;
                cout << binary_search(0,MAX) << endl;

        }

}
