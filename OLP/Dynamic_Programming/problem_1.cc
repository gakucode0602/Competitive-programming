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

vt<int> a = { 20, 1, 9, 8, 15, 10, 11 };
int n = (int)a.size();
vt<int> L(n + 2);
vt<int> T(n + 2);
void process(){
	L[n + 1] = 1;
	for(int i = n;i >= 0;i--)
	{
		int jmax = n + 1;
		for(int j = i + 1;j < n + 1;j++){
			if(a[j] > a[i] && L[j] > L[jmax])
			{
				jmax = j;
			}
		}
		L[i] = L[jmax] + 1;
		T[i] = jmax;
	}
}

void output()
{
	int i = 0;
	while(i != n + 1){
		if(i != 0){
			out << a[i] << " : " << T[i] << el;
		}
		i = T[i];
	}
	out << el;
}

int main(){
	a.pb(INT_MAX);
	a.insert(a.begin(),INT_MIN);
	process();
	for(int i = 0;i <= n + 1;i++){
		out << L[i] << "\t";
	}
	for(auto x : T){
		out << x << " ";
	}
	out << el;
	output();
}