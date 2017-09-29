/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

[
  ["aa","b"],
  ["a","a","b"]
]

*/

/*

	the first answer,it's too slow!!!

    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        int num = s.size();
        vector<string> stmp;
        string ts;
        for(int i = 0; i < num; i++){//there's a problem. 这里不需要加循环，这样就多做了很多无用功
            if(i == 0){
                if(isa(s)){
                    stmp.push_back(s);
                    result.push_back(stmp);
                    stmp.pop_back();
                }
                continue;    
            }
            for(int len = 1; len <= num  - i; len++){
                ts = s.substr(0,len);
                if(isa(ts)){
                    stmp.push_back(ts);
                    solver(result,stmp, s.substr(len), i-1);
                    stmp.pop_back();
                }
            }
            
        }
        return result;
    }
    
    void solver(vector<vector<string>>& result,vector<string>& stmp,string s, int num){
        if(num == 0){
            if(isa(s)){
                    stmp.push_back(s);
                    result.push_back(stmp);
                    stmp.pop_back();
            }
            return;    
        }
        
        string ts;
        
        for(int len = 1; len <= s.size() - num; len++){
            ts = s.substr(0,len);
            if(isa(ts)){
                stmp.push_back(ts);
                solver(result,stmp, s.substr(len), num-1);
                stmp.pop_back();
            }
        }   
    }
    bool isa(string& str){
        if(str.empty())
            return true;
        int low = 0, high = str.size()-1;
        while(low < high){
            if(str[low++] != str[high--])
                return false;
        }
        return true;
    }  
*/

/*

	improvement;

    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        int num = s.size();
        vector<string> stmp;
        
        vector<vector<bool>> dp(s.size(),vector<bool>(s.size(),false));
        for(int i = 0; i < s.size(); i++){
            for(int j = 1; j <= s.size() - i; j++){
                string t = s.substr(i,j);
                dp[i][i+j-1] = isa(t);
            }
        }
        
        solver(result,stmp, s, dp,0);

        return result;
    }
    
    void solver(vector<vector<string>>& result,vector<string>& stmp,string& s, vector<vector<bool>>& dp,int start){
        if(start == s.size()){
            result.push_back(stmp);
            return;    
        }
        
        for(int len = 1; len <= ss.size() - start; len++){
            if(dp[start][start+len-1]){
                stmp.push_back(s.substr(start,len));
                solver(result,stmp, s,dp,start+len);
                stmp.pop_back();
            }
        }   
    }
    bool isa(string& str){
        if(str.empty())
            return true;
        int low = 0, high = str.size()-1;
        while(low < high){
            if(str[low++] != str[high--])
                return false;
        }
        return true;
    }  
*/