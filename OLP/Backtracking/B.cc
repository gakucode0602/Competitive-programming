#include<bits/stdc++.h>
using namespace std;

#define out std::cout
#define in std::cin
#define end std::endl
#define ll long long
#define pb push_back
#define PB pop_back
#define For(i,a,b) for(int (i) = (a);(i) < (b);(i)++)
#define rof(i,a,b) for(int (i) = (a);(i) > (b);(i)--)
#define ite(i,c) for(auto &(i) : c)
#define iOS ios_base::sync_with_stdio(false)
#define MOD 1000000007
#define vt vector

int n = 30;
vt<int> state;
vt<vt<int>> res;
int sum = 0;

void output(){
	ite(x,state){
		out << x << " ";
	}
	out << end;
}

void backtracking(int idx){
	if(sum > n){
		return;
	}
	For(i,1,n+1)
	{
		if(sum + i <= n && (state.empty() || i >= state.back())){
			state.pb(i);
			sum += i;
			if(sum == n){
				output();
			}
			else backtracking(idx + 1);
			state.PB();
			sum -= i;
		}
	}
}

int main(){
	backtracking(0);
	return 0;
}