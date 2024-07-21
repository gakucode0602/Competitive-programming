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
Cho mảng nguyên a gồm n phần tử, tìm hai chỉ số i và j 
trong a sao cho a[j] – a[i] là lớn nhất trong số các chỉ
số i, j thoả 0 ≤ i ≤ j ≤ n. Chẳng hạn, dãy số {4, 5, 3, 2, 8, 9} 
thì sự khác nhau lớn nhất là 7.
*/

vt<int> a = {1,5,3,2,8,9};

void process(int left,int right,int &min,int &max,int &maxDiff)
{
	if(left == right)
	{
		min = max = a[left];
		maxDiff = 0;
	}
	else
	{
		int middle = (left + right) / 2;
		int min1,max1,maxDiff1;
		process(left,middle,min1,max1,maxDiff1);
		int min2,max2,maxDiff2;
		process(middle + 1,right,min2,max2,maxDiff2); 

		min = (min1 < min2) ? min1 : min2;
		max = (max1 > max2) ? max1 :max2;
		maxDiff = max - min;
	}
}


int main(){
	int min,max,maxDiff;
	process(0,(int)a.size() - 1,min,max,maxDiff);
	out << maxDiff << el;
	out << min << " " << max << el;
	return 0;
}