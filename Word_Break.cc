/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words. You may assume the dictionary does not contain duplicate words.
For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".

UPDATE (2017/1/4):
The wordDict parameter had been changed to a list of strings (instead of a set of strings). Please reload the code definition to get the latest changes. 
*/

/*

	将问题看做是在图中的遍历，图的节点是s中的分段位置，边是字典中的元素。然后对图进行广度优先遍历，
	要对访问过的节点进行标记，不然会出现大量重复访问的情况。

    bool wordBreak(string s, vector<string>& wordDict) {
        priority_queue<int> pq;
        unordered_set<string> us;
        unordered_set<int> visited;
        for(auto c : wordDict){
            us.insert(c);
            if(c.size() <= s.size() && us.find(s.substr(0,c.size())) != us.end()){
                pq.push(c.size());
                if(c.size() == s.size())
                    return true;
            }
        }
        while(!pq.empty()){
            int pos = pq.top();
            pq.pop();
            if(visited.find(pos) == visited.end()){
                visited.insert(pos);
                for(int j=pos; j<s.size(); j++){
                    string word(s, pos, j-pos+1);
                    if(us.find(word) != us.end()){
                        pq.push(j+1);
                        if(j+1 == s.size())
                            return true;
                    }
                }
            }
        }
        return false;
    }
*/

/*

    DP algorithm. 动态规划算法的关键点在雨如何设置状态和状态间的递推关系。
    dp[i]代表s[0,i-1]是否能够正确的分段。dp[i]为true的条件是d[j]为true，且
    s[j,i]能够在字典中找到一个正确的分段。

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> us;
        vector<bool> dp(s.size() + 1,false);
        dp[0] = true;
        for(auto c : wordDict)
            us.insert(c);
        
        for(int i = 1; i <= s.size(); i++){
            for(int j = 0; j < i; j++){
                if(dp[j] && us.find(s.substr(j,i-j)) != us.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
*/