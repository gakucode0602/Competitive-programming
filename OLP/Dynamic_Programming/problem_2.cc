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
Có n cuộc họp, cuộc họp i bắt đầu lúc Ai và kết thúc lúc Bi 
và chỉ có 1 phòng họp duy nhất. 
Do đó, hai cuộc họp không thể bố trí trong các khoảng thời gian 
họp giao nhau. Yêu cầu bố trí phòng họp sao cho có thể diễn ra 
nhiều cuộc họp nhất.
*/

vt<pair<int,int>> a = {
	{11,13},{7,9},{9,10},{10,11},
	{8,9},{13,15},{13,14},{14,16}
};
int n = (int)a.size();
vt<int> L(n + 2);
vt<int> T(n + 2);

void process(){
	L[n + 1] = 1;
	rof(i,n,-1){
		int jmax = n + 1;
		For(j,i + 1,n + 1){
			if(a[i].second <= a[j].first and L[j] > L[jmax]){
				jmax = j;
			}
		}
		L[i] = L[jmax] + 1;
		T[i] = jmax;
	}
}


void output(){
	int i = 0;
	while(i != n + 1){
		if(i != 0){
			out << a[i].first << " - " << a[i].second << el; 
		}
		i = T[i];
	}
}

int main(){
	sort(a.begin(),a.end(),[](auto x,auto y) {return x.second < y.second;});

	a.pb({24,24});
	a.insert(a.begin(),{0,0});
	process();
	output();

	return 0;
}