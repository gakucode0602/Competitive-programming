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
#define MOD 1000000007
#define vt vector

int main(){
	iOS;
	int n,x;
	in >> n >> x;
	vt<int>price(n),page(n);
	for(int &v : price) in >> v;
	for(int &v : page) in >> v;
	vt<vt<int>> dp(n + 1,vt<int>(x+1,0));
	for(int i = 1;i <= n;i++){
		for(int j = 0;j <= x;j++){
			dp[i][j] = dp[i-1][j];
			int left = j - price[i - 1];
			if(left >= 0){
				dp[i][j] = max(dp[i][j],dp[i - 1][left] + page[i - 1]);
			}
		}
	}
	out << dp[n][x] << el;
}