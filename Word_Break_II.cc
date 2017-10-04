/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. You may assume the dictionary does not contain duplicate words.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].

UPDATE (2017/1/4):
The wordDict parameter had been changed to a list of strings (instead of a set of strings). Please reload the code definition to get the latest changes. 
*/

/*

	ugly code. the first solution.先利用一个动态规划的算法判断是否有可以分段。然后再利用一个深度优先遍历，来遍历所有的情况。使用的一个
	direct向量来记录从位置i开始，是否能够组成一个正确的分段。当不能使，后续的遍历来到位置i时就不用继续下去了，避免了重复失败的情况。该算法
	只是保存了失败的情况，对于成功的情况还是要进行遍历，所以可以继续改进，加上成功的情况。

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<int,queue<string>> us;
        vector<bool> direct(s.size(),true);
        vector<string> result;
        string temp = "";
        if(!wordBreak1(s,wordDict))
            return result;
        for(auto c : wordDict){
            int pos = 0;
            while(true){
                int tpos = s.find(c,pos);
                if(tpos != string::npos)
                    us[tpos].push(c);
                else
                    break;
                pos = tpos + 1;
            }
        }
        solver(direct,result,temp,us,0,s.size());
        return result;
    }
    bool solver(vector<bool>& direct,vector<string>& result,string temp,unordered_map<int,queue<string>>& us, int pos,int len){
        if(pos == len){
            temp.pop_back();
            result.push_back(temp);
            return true;
        }
        queue<string> t;
        if(us.find(pos) != us.end())
            t = us[pos];
        else
            direct[pos] = false;
        while(!t.empty()){
            bool flag;
            flag = solver(direct,result,temp + t.front() + " ",us,pos+t.front().size(),len);
            t.pop();
        }
        return true;
    }
    bool wordBreak1(string s, vector<string>& wordDict) {
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

/*

	DFS,进行深度优先遍历，并在遍历的图中，保存中间的状态，即保存s[i,end]的分段情况，当下次在处理这一段的时候，就可以直接返回；即
	同时保存了成功和失败的情况。

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,vector<string>> um;
        return solver(s,wordDict,um);
    }
    vector<string> solver(string s, vector<string>& wordDict, unordered_map<string,vector<string>>& um){
        if(um.find(s) != um.end())
            return um[s];
        
        vector<string> res;
        
        if(s.size() == 0){
            res.push_back("");
            return res;
        }
        for(auto c : wordDict){
            string t = s.substr(0,c.size());
            if(t == c){
                vector<string> tres = solver(s.substr(c.size()),wordDict,um);
                for(auto d : tres){
                    res.push_back(c + (d.empty()?"" : " ") + d);
                }
            }
        }
        um[s] = res;
        return res;
    }
*/