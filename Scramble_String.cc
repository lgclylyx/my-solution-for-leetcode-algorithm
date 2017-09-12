/*
Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t

To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t

We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a

We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1. 
*/

/*

	递归解法，在每个可切分处，都存在两种情况，交换或不交换，对每个可切分处进行迭代，查看是否存在符合条件的情况。

    bool isScramble(string s1, string s2) {
        if(s1 == s2)
            return true;
        
        unordered_map<char,int> um;
        
        for(int i = 0; i < s1.size();i++){
            if(um.find(s1[i]) == um.end())
                um[s1[i]] = 1;
            else
                um[s1[i]]++;
            if(um.find(s2[i]) == um.end())
                um[s2[i]] = -1;
            else
                um[s2[i]]--;
        }
        for(auto itr = um.begin(); itr != um.end(); itr++)
            if((*itr).second != 0)
                return false;
        
        for(int i = 1; i < s1.size(); i++){
            if(isScramble(s1.substr(0,i),s2.substr(0,i)) && isScramble(s1.substr(i),s2.substr(i)))//交换
                return true;
            if(isScramble(s1.substr(0,i),s2.substr(s1.size() - i)) && isScramble(s1.substr(i),s2.substr(0,s1.size() - i)))//不交换
                return true;
        }
        return false;
    }
*/