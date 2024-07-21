#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int>& sets, vector<vector<int>>& res, int i)
{
	if (i == sets.size() - 1) {
		res.push_back(sets);
		return;
	}
	for (int j = i; j <= sets.size() - 1; j++) {
		swap(sets[i], sets[j]);
		solve(sets, res, i + 1);
		swap(sets[i], sets[j]);
	}
}

/*
index: 0 1 2
sets : 1 2 3
res : [[1 2 3],[1,3,2]]
path : 1 3
i | j
0 | 0 1 2
*/

vector<vector<int>> permutations(vector<int>& nums) {
	vector<vector<int>> res;
	solve(nums, res, 0);
	return res;
}

int main() {
	vector<int> nums = { 1,2,3 };
	for (auto x : permutations(nums)) {
		for (auto y : x) {
			cout << y << " ";
		}
		cout << endl;
	}
	return 0;
}