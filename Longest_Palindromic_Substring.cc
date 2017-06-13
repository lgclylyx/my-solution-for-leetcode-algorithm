/*
 * question:longest_Palindrome_Substring
 *
 * Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
 *
 * Example:
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 *
 * Example:
 * Input: "cbbd"
 * Output: "bb"
 *
 */



/*
 * first solution: manacher algorithm, O(N)
 * 应该还有很多可以改进的
 *
 * string longestPalindrome(string s) {
        string result="";
        preprocess(s);
    	size_t len = s.size();
    	int *RL = new int[len];
    	int maxright = 0;
    	int pos = 0;
    	int max;
    	RL[0]=1;
    	for(int i = 1; i < len;i++){
    		if(i > maxright){
    			int left = i-1,right = i+1;
    			while(left >= 0 && right < len && s[left] == s[right]){left--,right++;}
    			RL[i] = right -i;
    			if(right - 1 > maxright){
    				maxright = right -1;
    				pos = i;
    			}
    		}else{
    			int j = 2*pos -i;
    			if((j-RL[j]) > (pos -RL[pos])){
    				RL[i] = RL[j];
    			}else{
    				int left = i - RL[j],right = i + RL[j];
    				if(right > maxright){
    				    right = maxright;
    				    left = 2*i-maxright;
    		    	}
    				while(left >= 0 && right < len && s[left] == s[right]){left--,right++;}
    				RL[i] = right -i;
    				if(right - 1 > maxright){
    					maxright = right -1;
    					pos = i;
    				}
    			}
    		}
    	}
    	int leftpos = 0;
    	max = RL[0];
    	for(int i=0;i<len;i++){
    		if(RL[i]>max){
    			max = RL[i];
    			leftpos = i+1;
    		}
    	}
    	int i =(s[leftpos - max] == '#')?leftpos-max+1:leftpos-max;
    	int j =2*max+i-2;
    	for(;i<j;i+=2)
    	   result +=s[i];
    	return result;
    }
    void preprocess(string& s){
	    string ss("");
	    for(size_t i=0;i < s.size();i++){
		    ss=ss+"#"+s[i];
	    }
    	ss+="#";
    	s=ss;
    }
*/


/*
 * 这是一个QP算法的实现，效果不是太好，但很有意思
 *
 *

 public String longestPalindrome(String s) {
        if (s == null || s.length() < 2) {
            return s;
        }
        char[] c = s.toCharArray();
        boolean[][] isPalindrome = new boolean[c.length][c.length];
        int start = 0;
        int end = 0;
        int counter = 0;
        int preCounter = 0;

        // basic case for only one character
        for (int i = 0; i < isPalindrome.length; i++) {
            isPalindrome[i][i] = true;
            start = i;
            end = i;
        }

        // basic case for only two characters
        for (int i = 0; i < isPalindrome.length - 1; i++) {
            if (c[i] == c[i + 1]) {
                isPalindrome[i][i + 1] = true;
                start = i;
                end = i + 1;
            } else {
                isPalindrome[i][i + 1] = false;
            }
        }

        // for substring from index a to b, i == b - a
        for (int i = 2; i < isPalindrome.length; i++) {
            counter = 0; // uesd for check is no new palindrome for a longer substring for better performance
            // j is the starting point of a substring
            for (int j = 0; j < isPalindrome.length -i; j++) {
                int index = j + i;
                // check is 2 characters shorter substring is palindrome and if character on two ends is equal
                if (isPalindrome[j + 1][index - 1] && c[j] == c[index]) {
                    isPalindrome[j][index] = true;
                    counter++;
                    start = j;
                    end = index;
                } else {
                    isPalindrome[j][index] = false;
                }
            }
            if (counter == 0 && preCounter == 0) {
                break;
            }
            preCounter = counter;
        }

        return s.substring(start, end + 1);
    }
 */
