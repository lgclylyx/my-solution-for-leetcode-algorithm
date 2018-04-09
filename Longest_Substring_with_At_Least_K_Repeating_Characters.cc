/*
Find the length of the longest substring T of a given string (consists of lowercase letters only) such that every character in T appears no less than k times.

Example 1:

Input:
s = "aaabb", k = 3

Output:
3

The longest substring is "aaa", as 'a' is repeated 3 times.

Example 2:

Input:
s = "ababbc", k = 2

Output:
5

The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
*/

    首先，得到一个[left,right)区间，其中的所有元素在上一层整个区间中是满足限定条件k的，然后
    判断在这个小区间中，是否同样满足条件，如果是，则该区间是一个合法的候选区间，否则，就将区间
    再此划分，直到不可能满足条件。划分的条件是在某段小区间内，其元素在大区间中是满足条件的。
    int longestSubstring(string s, int k) {
        int hash[26] = {0};
        int res = 0;
        unordered_set<char> filter;
        for(auto c : s)
            hash[c - 'a']++;
        
        for(int i = 0; i < 26; i++)
            if(hash[i] > 0 && hash[i] < k)
                filter.insert(i + 'a');
        
        if(filter.empty())
            return s.size();
        
        if(s.size() == filter.size())
            return 0;
        
        int left = 0, right = 0;
        
        while(left < s.size() && right < s.size()){
            while(left < s.size() && filter.find(s[left]) != filter.end())
                left++;
            right = left + 1;
            while(right < s.size() && filter.find(s[right]) == filter.end())
                right++;
            res = max(res, longestSubstring(s.substr(left,right-left),k));
            left = right;
        }
        return res;
    }
