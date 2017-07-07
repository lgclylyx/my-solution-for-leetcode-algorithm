/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

*/

/*

	O(n^2)


    int threeSumClosest(vector<int>& nums, int target) {
        
        int distance = INT_MAX;
        int result = 0;
        
        sort(nums.begin(),nums.end());//排序
        
        for(int i = 0; i < nums.size(); i++){
            
            int front = i + 1;
            int back = nums.size() - 1;
            
            while (front < back) {
                int sum = nums[front] + nums[back] + nums[i];
                int tempdistance = abs(target - sum);
                
                if(tempdistance < distance){
                    distance = tempdistance;
                    result = sum;
                }
                
                if(0 == distance)
                    break;
                
                if (sum < target){
                    front++;
                    int a = nums[front-1];
                    while (front < back && nums[front] == a) front++;
                }else{
                    back--;
                    int b = nums[back+1];
                    while (front < back && nums[back] == b) back--;
                }
            }

            if(0 == distance)
                break;
            
            while (i + 1 < nums.size() && nums[i + 1] == nums[i])
                i++;

        }
        
        return result;
    }



*/