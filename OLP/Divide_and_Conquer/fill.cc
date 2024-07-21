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

int k = 3;
int n = 1 << k;

vt<vt<int>> a(n,vt<int>(n));
int steps = 0;

void flooring(int x,int y,int d)
{
	steps++;
	if(d != 1)
	{
		a[x][y] = steps;
	}
	if(d != 2){
		a[x][y + 1] = steps;
	}
	if(d != 3){
		a[x + 1][y + 1] = steps;
	}
	if(d != 4){
		a[x + 1][y] = steps;
	}
}

void process(int n,int x,int y,int d)
{
	if(n == 2){
		flooring(x,y,d);
	}
	else{
		int p = n/2;
		switch(d){
			case 1 :
			{
				process(p,x,y + p,4);
				process(p,x + p,y + p,1);
				process(p,x + p,y,2);
				process(p,x + p/2,y + p/2,1);
				break;
			}
			case 2:
			{
				process(p,x,y,3);
				process(p,x + p,y + p,1);
				process(p,x + p,y,2);
				process(p,x + p / 2,y + p/2,2);
				break;
			}
			case 3:
			{
				process(p,x,y,3);
				process(p,x,y + p,4);
				process(p,x + p,y,2);
				process(p,x + p / 2,y + p/2,3);
				break;
			}
			case 4:
			{
				process(p,x,y,3);
				process(p,x,y + p,4);
				process(p,x + p,y + p,1);
				process(p,x + p / 2,y + p/2,4);
				break;
			}
	}
	}
}

int main(){
	process(n,0,0,2);
	ite(i,a){
		ite(j,i){
			out << j << "\t";
		}
		out << el;
	}
	return 0;
}