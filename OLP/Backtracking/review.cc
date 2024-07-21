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




// vt<bool> d(3,false);

// void process(vt<int> &sets,vt<vt<int>> &res,vt<int> &p){
// 	if(p.size() == sets.size()){
// 		res.pb(p);
// 		return;
// 	}
// 	For(i,0,sets.size()){
// 		if(d[i] == false){
// 			d[i] = true;
// 			p.pb(sets[i]);
// 			process(sets,res,p);
// 			d[i] = false;
// 			p.PB();
// 		}
// 	}
// }

// void process2(vt<int> &nums,vt<vt<int>> &res,int i,int n){
// 	if(i == n - 1){
// 		res.pb(nums);
// 		return;
// 	}
// 	For(j,i,n){
// 		swap(nums[j],nums[i]);
// 		process2(nums,res,i+1,n);
// 		swap(nums[j],nums[i]);
// 	}
// }

// int n = 2;
// int k = 3;
// vt<int> sets = {1,2};

// void backtracking(vt<vt<int>> &res,vt<int> &p,int idx){
// 	if(p.size() == k){
// 		res.pb(p);
// 		return;
// 	}
// 	For(i,0,sets.size()){
// 		p.pb(sets[i]);
// 		backtracking(res,p,idx+1);
// 		p.PB();
// 	}
// }

// int n = 5;
// int k = 3;
// vt<int> sets = {1,2,3,4,5};
// vt<bool> d(n,false);

// void output(vt<vt<int>> res){
// 	ite(i,res){
// 		ite(j,i){
// 			out << j << " ";
// 		}
// 		out << endl;
// 	}
// }

// void backtracking(vt<vt<int>> &res,vt<int> &p,int idx){
// 	if(p.size() == k){
// 		res.pb(p);
// 		return;
// 	}
// 	For(i,idx,n){
// 		if(p.empty() || sets[i] > p.back()){
// 			p.pb(sets[i]);
// 			backtracking(res,p,idx+1);// int n1 = 2;
// 			p.PB();
// 		}
// 	}
// }

#define SIZE 8
vt<int> state(SIZE,0); // 

bool canPutQueen(int i,int j){
	For(k,0,i) // Chay vong lap tu dong 0 den dong i hien tai
	{
		if(state[k] == j || abs(i - k) == abs(j - state[k])){
			return false;
		}
		// Kiem tra xem j co trung cot voi k khong
		// k : cot chay tu 0 den dong i hien tai
		// j : cot dang xet
	}
	return true;
}

/*
   1 2 3 4 5
1    
2    0   0   k
3      0     i
4
5
*/

/*
 idx : hang
 i : cot
*/
void backtracking(int idx)
{
	For(i,0,SIZE){
		if(canPutQueen(idx,i)) // Kiem tra lieu co the dat quan hau tai dong idx cot j duoc khong ?
		{
			state[idx] = i; // Tai dong idx , cot i co the duoc dat quan hau
			if(idx == SIZE - 1)
			{
				output();
			}
			else backtracking(idx + 1);
		}
	}
}


int main(){
	vt<vt<int>> res;
	vt<int> p;
	
	backtrackin
	g(res,p,0);
	output(res);
	return 0;
}