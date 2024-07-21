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

int F(int n)
{
	if(n == 0 || n == 1){
		return 1;
	}
	return F(n - 1) + F(n - 2); 
}

int fibo(int n){
	vt<int> F(n + 1);
	F[0] = F[1] = 1;
	For(i,2,n + 1){
		F[i] = F[i - 1] + F[i - 2];
	}
	return F[n];
}


// Tạo 1 bảng
// Công thức truy hồi của bài toán
int main(){
	out << fibo(5) << el;
	return 0;
}