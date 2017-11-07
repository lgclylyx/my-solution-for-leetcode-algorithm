/*
Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. 
You must make sure your result is the smallest in lexicographical order among all possible results.

Example:

Given "bcabc"
Return "abc"

Given "cbacdcbc"
Return "acdb" 
*/

/*

	使用两个hash table保存串中的每种字符的数量和输出中是否已经存在
	某个字符。如果在输出中已经存在了某个字符，就直接跳过。否则，将
	对尾的大于该字符且在后续未处理的串中还存在的字符弹出。即保持最
	小的逻辑顺序。

    string removeDuplicateLetters(string s) {
        char hash[26] = {0},marked[26] = {0};
        string st;
        
        for(auto c : s)
            hash[c - 'a']++; 
        
        for(auto c : s){
            hash[c - 'a']--;
            
            if(marked[c - 'a'])
                continue;
            
            while(!st.empty() && hash[st.back() - 'a']  && st.back() > c){
                marked[st.back()-'a']--;
                st.pop_back();
            }
            st.push_back(c);
            marked[c-'a']++;
        }
        return st;
    }
*/