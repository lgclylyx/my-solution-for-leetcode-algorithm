/*
question : 3sum

Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]

*/

/*

	对于a+b+c=0,可以看作找到-a-b = c,所以先将数组排序，然后在依次遍历所有情况O(n^2logn)


    int BinarySearch(int key, int left, vector<int>& a){
        int right = a.size() - 1 ;
        while (left <= right) {
            int middle = left + (right - left) / 2;
            if (a[middle] < key) {
                left = middle + 1;
            } else if (a[middle] > key) {
                right = middle - 1;
            } else {
                return middle;
            }
        }
        return -1;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size() <= 2)
            return result;
        
        sort(nums.begin(),nums.end());//排序
        
        for(int i = 0; i < nums.size(); i++){
            
            for(int j = i+1; j < nums.size() ; j++){
                int k = 0;
                if((k=BinarySearch(-nums[i]-nums[j],j+1,nums)) != -1){
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    result.push_back(temp);
                }
                while(j+1 < nums.size() && nums[j] == nums[j+1])//跳过重复情况
                    j++;
            }
            while(i+1 < nums.size() && nums[i] == nums[i+1])//跳过重复情况
                i++;
        }
        
        return result;
    }
*/