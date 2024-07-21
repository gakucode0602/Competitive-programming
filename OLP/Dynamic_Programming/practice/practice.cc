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

int main()
{
	int n;
	in >> n;
	vt<int> dp(n + 1,1e9);
	dp[0] = 0;
	for(int i = 0;i <= n;i++){
		for(char c : to_string(i)){
			dp[i] = min(dp[i],dp[i - (c - '0')] + 1);
		}
	}
	out << dp[n] << el;
	return 0;
}