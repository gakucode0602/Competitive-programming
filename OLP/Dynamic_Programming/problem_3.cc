#include<bits/stdc++.h>
using namespace std;

#define out std::cout
#define in std::cin
#define el std::endl
#define ll long long
#define pb push_back
#define PB pop_back
#define For(i,a,b) for(int (i) = (a);(i) < (b);(i)++)
#define rof(i,a,b) for(int (i) = (a);(i) > (b);(i)--)
#define ite(i,c) for(auto &(i) : c) 
#define iOS ios_base::sync_with_stdio(false)
#define vt vector

/*
Cho hai dãy số a và b lần lượt có m và n phần tử (1 ≤ m, n ≤ 100). Hãy tìm dãy con chung dài nhất của hai dãy a và b. Chú ý dãy con là các phần tử trong dãy chỉ cần đảm bảo đúng trật tự nó trong dãy, không nhất thiết phải liên tiếp nhau, chẳng hạn dãy con a = {3, 1, 5, 6, 8, 2} và b = {1, 2, 4, 3, 6, 8} thì dãy con chung dài nhất là {3, 6, 8}.
*/

vt<int> a = {3, 1, 5, 6, 8, 2};
vt<int> b = {1, 2, 4, 3, 6, 8};

vt<vt<int>> L(a.size() + 1,vt<int>(b.size() + 1,0));

void process(){
	for(int i = 1;i <= a.size();i++){
		for(int j = 1;j <= b.size();j++){
			if(a[i - 1] == b[j - 1]){
				L[i][j] = L[i - 1][j - 1] + 1;
			}
			else{
				L[i][j] = max(L[i - 1][j],L[i][j - 1]);
			}
		}
	}
}

void output(){
	int i = (int)a.size();
	int j = (int)b.size();
	out << L[i][j] << el;
	vt<int> result;
	while(i > 0 and j > 0){
		if(a[i - 1] == b[j - 1]){
			result.pb(a[i - 1]);
			i--;
			j--;
		}
		else if(L[i - 1][j] > L[i][j - 1]){
			i--;
		}
		else j--;
	}
	for(auto x = result.rbegin();x != result.rend();x++){
		out << *x << "\t";
	}
	out << el;
}
int main(){
	process();
	output();
	return 0;
}