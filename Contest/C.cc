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

// vector<bool> sets;
// int curr = INT_MIN;
// int maxNum = INT_MIN;
// void update(){
// 	if(curr > maxNum){
// 		maxNum = max(curr,maxNum);
// 	}
// }

// void backtracking(string &s,int idx){
// 	if(maxNum > curr){
// 		return;
// 	}
// 	for(int i = idx;i < s.length();i++){
// 		if(sets[i] == false){
// 			sets[i] = true;
// 			s[i] = (s[i] == '9' ? '6' : '9');
// 			curr = stoi(s);
// 			update();
// 			s[i] = (s[i] == '9' ? '6' : '9');
// 			backtracking(s,idx+1);
// 		}
// 	}

// int maximum69Number (int num) {
// 	if(num == 9999) return num;
// 	string s = to_string(num);
// 	sets.resize(s.length(),false);
// 	backtracking(s,0);
// 	return maxNum;
// }



uint32_t reverseBits(uint32_t n) 
{
	uint32_t ans = 0;
	for(int i = 0;i < 32;i++)
	{
		ans <<= 1;
		ans |= (n & 1);
		n >>= 1;
	}
	return ans;
}

int main()
{
	
	return 0;
}