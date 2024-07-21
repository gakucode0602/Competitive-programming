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

string maximumOddBinaryNumber(string s) {
	sort(s.rbegin(),s.rend());
	for(int i = s.length() - 1;i >= 0;i--){
		if(s[i] == '1') swap(s[i],s[s.length() - 1]);
	}
	return s;
}

int main(){
	string s = "00111";
	out << maximumOddBinaryNumber(s) << endl;
	return 0;
}