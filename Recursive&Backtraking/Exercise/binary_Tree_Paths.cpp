#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<string> solution;
string s = "";

void backTracking(TreeNode* root){
	if(root == nullptr) return;
	if(root->left or root->right){
		s += (to_string(root->val) + "->");
	}
	else
	{
		s += to_string(root->val);
		solution.push_back(s);
	}
	backTracking(root->left);
	backTracking(root->right);
}

vector<string> Path(TreeNode* root){
	backTracking(root);
	return solution;
}


void process(vector<string> solution){
	for(auto s : solution){
		cout << s << endl;
	}
}



int main(){

	return 0;
}