#include <bits/stdc++.h>

using namespace std;

stack < long long > first;
stack < long long > last;

long long forwardStore[100000 + 10];
long long backwardStore[100000 + 10];
long long arr [100000 + 10];

long long mod = 1e9 + 7;

int main()
{

    ios::sync_with_stdio(false);cin.tie(0);     // decrease the time of cin, cout

    int t, n , k;

    cin >> t;

    while(t--){

        cin >> n;

        while(!first.empty()) first.pop();      // clear stacks in every test case
        while(!last.empty()) last.pop();

        for(int i = 1; i <= n; i++) cin >> arr[i];

        backwardStore[1] = 0;                   // first vehicle doesn't have a previous one
        first.push(1);                          // first vehicle has an index (1)

        for(int i = 2; i <= n; i++){

            while(!first.empty() && arr[i] > arr[first.top()])      // pop all less height vehicles
                first.pop();

            if(!first.empty()) backwardStore[i] = i - first.top();      // this driver can see backward up to first.top()
            else backwardStore[i] = i - 1;                         // this is the highest vehicle until now

            first.push(i);                                          // push vehicles indexes
        }

        forwardStore[n] = 0;                                        //last vehicle doesn't have a follower vehicle
        last.push(n);

        for(int i = n - 1; i >= 1; i--){

            while(!last.empty() && arr[i] > arr[last.top()]) last.pop();

            if(!last.empty()) forwardStore[i] = last.top() - i;
            else forwardStore[i] = n - i;

            last.push(i);
        }

        long long maxi = -1;        // initialize the maximum SIGHT
        int index = -1;

	//for(int i=1;i<=n;i++){
		//cout << "height : " << arr[i] << " left : " << backwardStore[i] << " right : " <<  forwardStore[i] << endl;
	//}

        for(int i = 1; i <= n; i++){

            long long sum = backwardStore[i] + forwardStore[i];

            sum = ( (sum % mod) *  (i) ) % mod;

            if(sum > maxi){                 // update maximum and index of the driver who have the maximum SIGHT until now

                maxi = sum;
                index = i;
            }
        }

        cout << index << "\n";
    }

    return 0;
}
