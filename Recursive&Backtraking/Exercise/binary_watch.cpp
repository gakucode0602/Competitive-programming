#include<bits/stdc++.h>
using namespace std;

// vector<int> hour = {1,2,4,8};
// vector<int> minute = {1,2,4,8,16,32};
// vector<string> res;

// void solve(int hr,int min,int i,int n){
// 	// base case
// 	if(n == 0){
// 		res.push_back(to_string(hr) + ((min < 10) ? ":0" : ":") + to_string(min));
// 		return;
// 	}
// 	for(int j = i;j < hour.size() + minute.size();j++){
// 		if(j < hour.size()){
// 			hr += hour[j];
// 			if(hr < 12){
// 				solve(hr,min,j+1,n-1);
// 			}
// 			hr-=hour[j];
// 		}
// 		else{
// 			min += minute[j - hour.size()];
// 			if(min < 60){
// 				solve(hr,min,j+1,n-1);
// 			}
// 			min-=minute[j - hour.size()];
// 		}
// 	}
// }

// vector<string> readBinaryWatch(int turnedOn) {
// 	solve(0,0,0,turnedOn);
// 	return res;        
// }

vector<int> hour = {1,2,4,8};
vector<int> minute = {1,2,4,8,16,32};
vector<string> res;


void backtracking(int idx){
	
}
int main(){
	for(string s : readBinaryWatch(1)){
		cout << s << endl;
	}
	return 0;
}