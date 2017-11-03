/*
Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

Therefore, return the max sliding window as [3,3,5,5,6,7].

Note:
You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for non-empty array.

Follow up:
Could you solve it in linear time?
*/

/*

	最直接的解法，对每个窗口独立求其最大值。这种方法最坏情况下O(n^2),最好O(n)。还可以使用
	一个最大堆来解决，O(nlogk)

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if(nums.empty())
            return res;
        int maxpos = 0;
        int max = nums[0];
        int leftpos = 1;
        for(int i = 0; i < k; i++){
            if(nums[i] >= max){
                maxpos = i;
                max = nums[i];
            }
        }
        res.push_back(max);
        
        for(int i = k; i < nums.size(); i++){
            if(leftpos <= maxpos){
                if(nums[i] >= max){
                    max = nums[i];
                    maxpos = i;
                }
            }else{
                max = nums[i];
                maxpos = i;
                for(int j = leftpos; j < i; j++){
                    if(nums[j] >= max){
                          maxpos = j;
                          max = nums[j];
                    }
                }
            }
            res.push_back(max);
            leftpos++;
        }
        return res;
    }
*/

/*

	改进。能够稳定使用O(n)解决。使用一个deque，即双向队列，在双向队列中，
	按照大小和位置进行排序，将值越大，位置越靠后的排在前面。对于一个新进入
	的，将比其小的都弹出。使其尽可能的前移

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if(nums.empty())
            return res;
        deque<int> que;
        for(int i = 0; i < nums.size(); i++){
            if(!que.empty() && que.front() == i-k)
                que.pop_front();
            while(!que.empty() && nums[que.back()] <= nums[i])
                que.pop_back();
            que.push_back(i);
            if(i >= k-1)
                res.push_back(nums[que.front()]);
        }
        return res;
    }
*/
