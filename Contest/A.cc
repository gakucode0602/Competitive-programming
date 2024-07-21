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
every letter of the alphabet -> it appears both in uppercase and lowercase
*/

/*
- Divided the string to 2 sets
- A function to check if it is actually nice and longer than the last string
*/

int myfunc(int x,int y){
    return x - abs(y);
}

int sum(int x,int y){
    return x + abs(y);
}

bool check(string s)
{
    for(int i=0;i<s.size();i++) {
        char c = s[i];
        if(c<=90) c += 32;
        else c -= 32;
        if(s.find(c)==string::npos) return false;
    }
    return true;
}

string longestNiceSubstring(string s) {
    string ans = "";
    for(int i = 0;i < s.length();i++)
    {
        string res = "";
        res += s[i];
        for(int j = i + 1;j < s.length();j++){
            res += s[j];
            if(check(res) == true && res.length() > ans.length())
            {
                ans = res;
            }
        }
    }
    return ans;
}

int main()
{
    iOS;
    string s = "YazaAay";
    out << longestNiceSubstring(s) << el;
	return 0;
}