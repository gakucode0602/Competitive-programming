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
int N;
vt<int> heights;

int solve(int N,vt<int> heights){
	vt<int> dp(N,INT_MAX);
	dp[0] = 0;
	For(i,0,N){
		dp[i + 1] = min(dp[i + 1],dp[i] + abs(heights[i] - heights[i + 1]));
		if(i + 2 < N)
		{
			dp[i + 2] = min(dp[i + 2],dp[i] + abs(heights[i] - heights[i + 2]));
		}
	}
	return dp[N - 1];
}

int main(){
	in >> N;
	for(int i = 0;i < N;i++){
		int x;
		in >> x;
		heights.pb(x);
	}
	out << solve(N,heights);
	return 0;
}