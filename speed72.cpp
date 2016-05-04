#include <bits/stdc++.h>

using namespace std;

int arr [100000 + 10];

int main()
{
	int t , n ,  m , k, ans;

	cin >> t;

	while(t--){

		cin >> n >> arr[0];

		ans = 1;

		for(int i = 1; i < n; i++){

			cin >> arr[i];
			if(arr[i] <= arr[i - 1]) ans++;     // increase the number of cars with Maximum Moving Speed
			else arr[i] = arr[i - 1];           // update the limit for following cars

		}

		cout << ans << "\n";
	}

	return 0;
}
