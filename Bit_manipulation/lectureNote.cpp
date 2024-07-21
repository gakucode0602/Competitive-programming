#include<bits/stdc++.h>
using namespace std;

void printAllSubset(int N,int maximum_mask_require){
	cout << 0;
	for(int mask = 0;mask <= maximum_mask_require;mask++){
		for(int k = 0;k < N;k++){
			if((mask & (1 << k)) != 0){
				cout << k + 1 << " ";
			}
		}
		cout << "\n";
	}
}

void printSubset(vector<int> &v){
	int size = v.size();
	for(int i = 0;i < pow(2,size);i++){
		for(int j = 0;j < size;j++){
			if((i & (1 << j)) != 0){
				cout << v[j] << " ";
			}
		}
		cout << endl;
	}
}



int main(){
	string ans = "";
	ans += to_string(1);
	cout << ans;
	return 0;
}