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
vector<int> subset;
int total = 0;
void sumSubSet(){
    int sum = 0;
    ite(i,subset){
        sum = sum ^ i;
    }
    total += sum;
}
int s;
void genSubSet(int pos,vector<int> v){
    if(pos == v.size()){
        sumSubSet();
        return;
    }
    else{
        subset.pb(v[pos]);
        genSubSet(pos + 1,v);
        subset.PB();
        genSubSet(pos + 1,v);
    }
}

int main(){
    s = 3;
    vector<int> v = {1,3};
    genSubSet(0,v);
    out << total << end;
    return 0;

}