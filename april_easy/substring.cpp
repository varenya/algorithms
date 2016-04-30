// Iterative C++ program to check if a string is subsequence of another string
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
const int MAX = 1e5 + 7;
char sorted_str[MAX];
 
// Returns true if str1[] is a subsequence of str2[]. m is
// length of str1 and n is length of str2
bool isSubSequence(string str1, string str2)
{
	int j = 0; // For index of str1 (or subsequence

	// Traverse str2 and str1, and compare current character 
	// of str2 with first unmatched char of str1, if matched 
	// then move ahead in str1
	int n = str1.size();
	int m = str2.size();
       	int length = str2.copy(sorted_str,m,0);
	sorted_str[length] = '\0';
	//cout << "SORTED STR " << sorted_str << endl;
	//cout << "LENGTH " << length << endl;
	string sorted_string(sorted_str);
	sort(sorted_string.begin(),sorted_string.end());
	//cout << "sorted string " << sorted_string << endl;
	// cout << "str1 " << str1 << endl;
	//cout << "str2 " << str2 << endl;
	for (int i=0; i<m && j<n ; i++){
		if ( !binary_search(sorted_string.begin(),sorted_string.end(),str1[j]) )
		{
		//	cout << "Not Found! " << endl;
			return false;
		}
		if (str1[j] == str2[i]){
			j++;
		}
	}

	// If all characters of str1 were found in str2
	//cout << "j " << j << endl;
	//cout << "n " << n << endl;
	return (j==n);
}
 
// Driver program to test methods of graph class
int main()
{
    string str1,str2;
    cin >> str1;
    int Q;
    cin >> Q;
    while(Q--){
	    cin >> str2;
	    isSubSequence(str2, str1)? cout << "Yes" :  cout << "No";
	    cout << endl;
    }
    return 0;
}
