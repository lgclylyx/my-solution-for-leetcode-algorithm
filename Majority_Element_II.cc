/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.
*/

/*

	boyer_moore algorithm.对于n/3的情况，符合条件的元素的数目可能是0,1,2.所以设置两个候选和计数器。

    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int cand1 = 0,cand2 = 1,count1 = 0,count2 = 0;
        for(auto c : nums){
            if(cand1 == c)
                count1++;
            else if(cand2 == c)
                count2++;
            else if(count1 == 0){
                cand1 = c;
                count1++;
            }else if(count2 == 0){
                cand2 = c;
                count2++;
            }else{
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        for(auto c : nums){
            if(cand1 == c)
                count1++;
            if(cand2 == c)
                count2++;
        }
        if(count1 > (nums.size() / 3))
            res.push_back(cand1);
        if(count2 > (nums.size() / 3))
            res.push_back(cand2);
        return res;
    }
*/