/*
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Return 0 if the array contains less than 2 elements.

You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
*/

/*

	基数排序

    int maximumGap(vector<int>& nums) {
        
        if (nums.size() < 2)
            return 0;
        
        // m is the maximal number in nums
        int m = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            m = max(m, nums[i]);
        }
        
        int exp = 1;    // 1, 10, 100, 1000 ...
        int R = 10;     // 10 digits

        vector<int> temp(nums.size(), 0);
    
        while (m/exp > 0) {   // Go through all digits from LSB to MSB
            vector<int> count(R, 0);
        
            for (int i = 0; i < nums.size(); i++) {
                count[(nums[i] / exp) % 10]++;
            }

            for (int i = 1; i < count.size(); i++) {
                count[i] += count[i - 1]; //确定每一个数在数组中的坐标
            }

            for (int i = nums.size() - 1; i >= 0; i--) {
                temp[--count[(nums[i] / exp) % 10]] = nums[i];
            }

            for (int i = 0; i < nums.size(); i++) {
                nums[i] = temp[i];
            }
            exp *= 10;
        }
    
        int maxGap = 0;
        for (int i = 1; i < temp.size(); i++) {
            maxGap = max(maxGap, temp[i] - temp[i - 1]);
        }

        return maxGap;
        
    }
*/