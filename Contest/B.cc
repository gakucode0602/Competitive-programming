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

int smallest = INT_MAX;

bool check(string s,string res)
{
	for(int i = 0;i < s.length();i++)
	{
		if((s[i] == 'D' && int(res[i]) < int(res[i + 1])) || (s[i] == 'I' && int(res[i]) > int(res[i + 1]))){
			return false;
		}
	}
	return true;
}

void update(string s,string &res)
{
	if(check(s,res) && stoi(res) < smallest){
		smallest = stoi(res);
	}
}

void solve(string s,string &res,int i,int n)
{
	if(stoi(res) > smallest) return;
	if(res.length() == n)
	{
		update(s,res);
	}
	for(int j = i;j < res.length();j++){
		swap(res[i],res[j]);
		solve(s,res,i+1,n);
		swap(res[i],res[j]);
	}

}

string smallestNumber(string s) {
	vector<bool>(s.length(),false);
	string res = "";
	for(int i = 0;i <= s.length();i++){
		res += to_string(i + 1);
	}
	solve(s,res,0,res.length());
	return to_string(smallest);
}

int main(){
	string s = "IIIDIDDD";
	out << smallestNumber("IIIDIDDD") << el;
	return 0;
}