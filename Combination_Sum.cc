/*
 Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:

    All numbers (including target) will be positive integers.
    The solution set must not contain duplicate combinations.

For example, given candidate set [2, 3, 6, 7] and target 7,
A solution set is:

[
  [7],
  [2, 2, 3]
]
*/
/*

	使用回溯算法，相当于在一个二叉树中进行DFS遍历，直到找到合适的组合，程序会在以candidates中每个元素为树根，而树根及其后面的元素为后继的情况的树中遍历

    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> result;
        vector<int> t;
        sort(candidates.begin(),candidates.end());//排序
        solver(result,t,candidates,target,0);//从candidates的第一个元素为根的树中进行迭代
        return result;
    }
    
    void solver(vector<vector<int>>& result,vector<int>& t,vector<int> &candidates,int target,int index){
        if(0 == target){
            result.push_back(t);
            return;
        }
        
        for(int i = index; i < candidates.size() && target >= candidates[i]; i++){//会将很多子树prune，并不会遍历每种情况
            t.push_back(candidates[i]);
            solver(result,t,candidates,target-candidates[i],i);
            t.pop_back();
        }
    }
*/