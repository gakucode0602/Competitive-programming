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

int  n,k;
vector<vector<int>> a;
vector<int> state;
vector<bool> d; 
int total = 0;

vector<int> best;
int totalBest = INT_MAX;
int start = 0;

void update(){
	int x = a[state[k - 1]][start];
	if(x > 0 && total + x < totalBest){
		totalBest = total + x;
		best = state;
	}
}

void process(int idx){
	if(total > totalBest){
		return;
	}
	For(i,0,n){
		if(d[i] == false && a[state[idx - 1]][i] > 0){
			state[idx] = i;
			d[i] = true;
			total += a[state[idx - 1]][i];
			if(idx == k - 1){
				update();
			}
			else process(idx + 1);
			d[i] = false;
			total -= a[state[idx - 1]][i];
		}
	}
}

void output(){
	out << totalBest << endl;
	ite(i,best){
		out << i + 1 << " ";
	}
	out << endl;
}

int main(){
	iOS;
	
	return 0;
}
