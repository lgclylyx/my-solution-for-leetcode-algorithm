/*
Given a list of unique words, find all pairs of distinct indices (i, j) in the given list, so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome.

Example 1:
Given words = ["bat", "tab", "cat"]
Return [[0, 1], [1, 0]]
The palindromes are ["battab", "tabbat"]

Example 2:
Given words = ["abcd", "dcba", "lls", "s", "sssll"]
Return [[0, 1], [1, 0], [3, 2], [2, 4]]
The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]
*/

/*
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string,int> map;
        vector<vector<int>>  res;
        
        for(int i = 0; i < words.size(); i++){//将字符串的逆序排列作为键值，则如果left==key，则left|right|candi；如果right == key，则candi|left|right
            string key = words[i];
            reverse(key.begin(),key.end());
            map[key] = i;
        }
        
        if(map.find("")!=map.end()){
             for(int i = 0; i < words.size(); i++){
                 if(i == map[""]) continue;
                 if(ispalindrome(words[i])) res.push_back({map[""], i}); 
             }
         }
        
        for(int i = 0; i < words.size(); i++){
            int len = words[i].size();
            for(int j = 0; j < len; j++){
                string left = words[i].substr(0,j);
                string right = words[i].substr(j,len - j);
                if(map.find(left) != map.end() && ispalindrome(right) && i != map[left])
                    res.push_back({i,map[left]});
                if(map.find(right) != map.end() && ispalindrome(left) && i != map[right])
                    res.push_back({map[right],i});
            }
        }
        return res;
    }
    bool ispalindrome(string& str){
        int i = 0, j = str.size() - 1;
        while(i < j){
            if(str[i++] != str[j--])
                return false;
        }
        return true;
    }
*/
