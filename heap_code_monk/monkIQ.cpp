#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>
#include <utility>
#define mk make_pair
#define ll long long
using namespace std;


struct course {
	ll number;
	vector <ll> applied;
	ll z;
};

struct cmp
{
	bool operator() (const course& a, const course& b)
	{
		if (a.z == b.z){
			//cout << endl;
			//cout << "Inside equal!!!" << endl;
			//cout << " a number " << a.number << " b number " << b.number << endl;
			return a.number > b.number;
		}

		return a.z > b.z;
	}
};

ll zcalculate(course a){
	if( a.applied.size() == 1)
		return a.applied[0];
	else{
		int index = a.applied.size();
		return index * (a.applied[index-1] + a.applied[index-2]);
	}
}

void printVector( vector <course> q){
	for(int i=0;i<q.size();i++){
		cout << " number " << q[i].number << " z " << q[i].z ;
	}
}


int main(void){

	ll C,N,P;
	cin >> C >> P >> N;
	priority_queue < course , vector<course>, cmp> courses;
	vector <course> q;
	vector <ll> Y;
	for(ll i=1;i<=C;i++){
		course temp;
		temp.number = i;
		temp.z = 0;
		q.push_back(temp);
	}
	ll i;
	for(i=1;i<=N;i++){
		ll temp;
		cin >> temp;
		q[i-1].z = temp;
		q[i-1].applied.push_back(temp);
		courses.push(q[i-1]);
	}
	//cout << "i C" << endl;
	//cout << i << C << endl;
	while(i<=C){
		/*
		cout << "inside while loop !!"<< endl;
		cout << q[i-1].number << endl;
		cout << q[i-1].z << endl;
		*/
		courses.push(q[i-1]);
		i++;
	}
	//cout << "Vector " << endl;
	//printVector(q);
	//cout << endl;
	for(ll i=1;i<=P;i++){
		ll temp;
		cin >> temp;
		course new_course = courses.top();
		courses.pop();
		cout << new_course.number << " ";
		//cout << endl;
		//cout << "z :" << new_course.z;
		//cout << endl;
		new_course.applied.push_back(temp);
		ll new_z = zcalculate(new_course);
		new_course.z = new_z;
		courses.push(new_course);
	}

	cout << endl;
}
