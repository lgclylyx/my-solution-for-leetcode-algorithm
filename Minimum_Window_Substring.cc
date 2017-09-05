/*
 Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"

Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the empty string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S. 
*/


/*

对于一个最值子串问题，一般的解法是将子串散列，然后用两个指针指向主串中的一段，然后判断是否符合条件，然后移动窗口。

string minWindow(string s, string t) {
        unordered_map<char,int> a;
        string result;
        int minlen = INT_MAX, min = 0, max = 0, tlen = t.size(), begin; //tlen用于标识[min,max]之间的一段是否满足条件
        for(auto c : t)
            if(a.find(c) == a.end())
                a[c] = 1;
            else
                a[c]++;
        while(max < s.size()){
            if(a.find(s[max]) != a.end()){
                if(a[s[max]] > 0)
                    tlen--;
                a[s[max]]--;
            }
            max++;
            while(tlen==0){
                if(minlen > max - min){
                    minlen = max - min;
                    begin = min;
                }
                if(a.find(s[min]) != a.end()){
                    if(a[s[min]] == 0)
                        tlen++;
                    a[s[min]]++;
                }
                min++;
            }
        }
        return minlen==INT_MAX ? "" : s.substr(begin,minlen);
    }
*/