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
#define SIZE 8

vt<int> state(SIZE);
vt<vt<int>> v(SIZE,vt<int>(SIZE));
int total = 0;

vt<int> best(SIZE);
int totalBest = INT_MIN;

bool canPutQueen(int i,int j)
{
	For(k,0,i){
		if(state[k] == j || abs(i - k) == abs(j - state[k]))
		{
			return false;
		}
	}
	return true;
}

void initData(){
	ifstream fin("queen.inp");
	ite(i,v){
		ite(j,i){
			fin >> j;
		}
	}
	fin.close();
}

void output(){
	ite(i,best){
		out << i << " ";
	}
	out << end << totalBest << end;
}


/*
Duyệt qua từng cột của hàng idx .
Chọn ra cột có trọng số lớn nhất . Nếu không trả về -
*/
int chooseBest(int row){
	int max = INT_MIN;
	int jMax = -1;

	For(col,0,SIZE)
	{
		if(canPutQueen(row,col) == true && v[row][col] > max)
		{
			max = v[row][col];
			jMax = col;
		}
	}
	return jMax;
}

// Kiểm tra tổng hiện có
// Nếu có tổng lớn hơn thì cập nhật lại totalBest
void update(){
	if(total > totalBest)
	{
		totalBest = total;
		best = state;
	}
}

void process(int idx)
{
	int i = chooseBest(idx);
	if(i == -1) { return; }
	state[idx] = i;
	total += v[idx][i];
	if(idx == SIZE - 1)
	{
		update();
	}
	else process(idx + 1);
	total -= v[idx][i];
}

int main(){
	initData();
	process(0);
	output();
	return 0;
}