#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> res;
vector<int> resV;
void solve(vector<vector<int>> &g,vector<vector<int>>&res,vector<int> &path,int cur){
	path.push_back(cur);
	if(cur == g.size() - 1){
		res.push_back(path);
	}
	else{
		for(auto it : g[cur]){
			solve(g,res,path,it);
		}
	}
	path.pop_back();
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
	vector<vector<int>> paths;
	vector<int> path;
	solve(graph,paths,path,0);
	return paths;
}



int main(){
	vector<vector<int>> graph = {{1,2},{3},{3},{}};
	for(auto x : allPathsSourceTarget(graph)){
		for(auto y : x){
			cout << y << " ";
		}
		cout << endl;
	}
	return 0;
}