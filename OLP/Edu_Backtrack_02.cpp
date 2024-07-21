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

int n,k;
vector<int> a;
vector<bool> d;

vector<vector<int>> delta;
vector<int>state;

void back_track(int idx){
	if(idx == 0){
		delta.pb(state);
	}
	For(i,0,a.size()){
		if(d[i] == false && idx <= k){
			state[i] = --idx;
			d[i] = true;
			back_track(idx + 1);
			idx++;
			state[i] = 0;
			d[i] = false;
			back_track(idx + 1);
		}
	}
}

int main(){
	iOS;
	in >> n >> k;
	For(i,0,n){
		int x;
		in >> x;
		a.pb(x);
	}
	state.resize(n,0);
	d.resize(n,false);
	delta.resize(n,vector<int>(n));
	back_track(2);
	ite(x,delta){
		ite(y,x){
			out << y << " ";
		}
		out << end;
	}
	return 0;
}