/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity. 
*/

/*

	hash;对于一个连续的串，从其中的任意一个元素向上和向下遍历都能够遍历整个串。

    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int max = 1;
        unordered_set<int> us(nums.begin(),nums.end()); 
        
        while(!us.empty()){
            auto itr = us.begin();
            int tmax = 1;
            int temp = *itr;
            while(true){
                temp++;
                if(us.find(temp) != us.end()){
                    tmax++;
                    us.erase(temp);
                }else
                    break;
            }
            temp = *itr;
            while(true){
                temp--;
                if(us.find(temp) != us.end()){
                    tmax++;
                    us.erase(temp);
                }else
                    break;
            }
            us.erase(*itr);
            if(tmax > max)
                max = tmax;
        }
        return max;
    }

*/