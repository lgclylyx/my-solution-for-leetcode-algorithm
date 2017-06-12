/*
 * question: Longest Substring Without Repeating Characters
 * Given a string, find the length of the longest substring without repeating characters.
 * Examples:
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 * Given "bbbbb", the answer is "b", with the length of 1.
 * Given "pwwkew", the answer is "wke", with the length of 3.
 * Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */

/*
 *
 * //primitive solution:346ms
 *
 * 最初的解法：顺序扫描string，将每个字符放入hash表中，然后查看是否有重复的字符，如果有就计算一次最长子串，然后从最右边重复字符的下一位继续进行扫描
 *
 * 问题：倒回去重复扫描，每次清空hash表
 *
   int lengthOfLongestSubstring(string s) {
        int len = 0;
        int templen = 0;
        unordered_map<char,int> hash;
        for(int i = 0; i < s.size(); i++){
            if(hash.find(s[i]) == hash.end()){
                hash.insert({s[i] , i});
                templen++;
            }else{
                if(templen > len){
                    len = templen;
                }
                templen = 0;
                i = hash[s[i]];
                hash.clear();
            }
        }
        if(templen > len){
            len = templen;
        }
        return len;
    }
 */

/*
 * improvement:36ms
 *
     int lengthOfLongestSubstring(string s) {
        int len = 0;
        int pos = 0;
        unordered_map<char,int> hash;
        for(int i = 0; i < s.size(); i++){
            if(hash.find(s[i]) == hash.end()){
                hash.insert({s[i] , i});
                len = max(len,i-pos+1);  //如果没有重复，则将len长度增加；（+1）是指包括现在i所指的字符
            }else{
                pos = max(pos,hash[s[i]]+1);
                len =max(len,i - pos + 1); //如果重复，则先判定重复字符相对于pos的位置，并修正pos的值；分为3种情况：（1）如果pos在最左边重复字符的右边，则保持pos不变；（2）如果pos
                hash[s[i]] = i;            //就是重复的位置，则向前 移动一位，目的是统一处理（使用+1）；（3）如果重复位置位于pos右边，则将pos移动到重复位置之前一位。
            }							   //并更新该字符的在hash表中的值，在hash表中的值代表的是该字符出现在已处理的串最右边的位置
        }
        return len;
    }
  */
