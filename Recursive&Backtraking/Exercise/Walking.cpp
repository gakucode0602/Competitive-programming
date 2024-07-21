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
#define M 999999
int n,k;
int sum = 0;
vector<int> path,bestPath;
int matrix[M][M];

// tim min nho nhat co 


int getSum(vector<int> v){
    int sum = 0;
    ite(i,v){
        sum += i;
    }
    return sum;
}

void genPath(int curRow){
    int lastIdx = (path.empty() ? 2 : path.back());
    if(path.size() == k){
        if(matrix[lastIdx][1] != 0){
            bestPath.clear();
            sum+=matrix[lastIdx][1];
            ite(i,path) bestPath.pb(i);
            return;
        }
    }
    For(curCol,lastIdx,n+1){
        if(curCol == curRow) continue;
        if(curCol == 1 && path.size() != k-1) continue;
        path.pb(curCol);
        sum+=matrix[curRow][curCol];
        if(bestPath.empty() || getSum(path) > getSum(bestPath)){
            genPath(curRow + 1);
        }
        path.PB();
        sum-=matrix[curRow][curCol];
    }    
}

int main(){
    iOS;
    in >> n >> k;
    For(i,1,n + 1){
        For(j,1,n + 1){
            in >> matrix[i][j];
        }
    }
    path.pb(1);
    genPath(1);
    int lastIdx = bestPath[bestPath.size() - 1];
    out << sum + matrix[lastIdx][1] << end;
    ite(i,bestPath) out << i << " ";
    out << endl;
    return 0;
}