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

/*
Cho n vật, mỗi vật có trọng lượng wi và giá trị vi. 
Một chiếc ba lô có khả năng chứa tối đa (theo trọng lượng) là k.
Chọn các vật thể như thế nào để tổng giá trị của chúng là lớn nhất
và tổng trọng lượng không vượt quá k.
*/

vt<pair<int,int>> a = 
{
	{2,3},{4,9},{3,8},{3,6}
};

int n = 4;
int k = 5;

vt<vt<int>> L(n + 1,vt<int>(k + 1,0));

void process()
{
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= k;j++){
			L[i][j] = L[i - 1][j];

			int wi = a[i - 1].first;
			int vi = a[i - 1].second;
			if(j >= wi && L[i][j] < L[i - 1][j - wi] + vi)
			{
				L[i][j] = L[i - 1][j - wi] + vi;
			}
		}
	}
}

void output(){
	out << "Tong gia tri lon nhat " << L[n][k] << el;
	int i = n;
	int j = k;
	while(i > 0 && j > 0){
		int wi = a[i - 1].first;
		int vi = a[i - 1].second;

		int x = L[i - 1][j];
		int y = L[i - 1][j - wi] + vi;
		if(y > x){
			if(L[i][j] >= y)
			{
				j = j - wi;
				out << wi << " - " << vi << el;
			}
		}
		i--;
	}
}

int main()
{
	process();
	output();
	return 0;
}