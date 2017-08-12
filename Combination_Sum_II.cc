/*
 Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:

	All numbers (including target) will be positive integers.
	The solution set must not contain duplicate combinations.

For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8,
A solution set is:

[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
*/

/*

	使用回溯算法，相当于在树中进行DFS搜索。

	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>> result;
		vector<int> t;
		sort(candidates.begin(),candidates.end());
		solver(result,t,candidates,target,0);
		return result;
	}
	void solver(vector<vector<int>>& result,vector<int>& t,vector<int>& candidates,int target,int index){
		if(0 == target){
			result.push_back(t);
			return;
		}
		int k = -1;
		for(int i = index; i < candidates.size() && target >= candidates[i]; i++){
			if(k!=candidates[i]){//跳过重复的情况，这是有两种情况，一是成功找到一个组合，如果后面的元素重复了，则是重复的组合，则跳过。如果是未找到合适的组合，则重复的元素必定也是不符合的，也跳过。
								//重复元素作为树根的情况也跳过。
				t.push_back(candidates[i]);
				solver(result,t,candidates,target-candidates[i],i+1);
				k = t.back();
				t.pop_back();
			}
		}
	}
*/