/*
 Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

*/

/*
	迭代版本


    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if(0 == n){
            result.push_back(string(""));
            return result;
        }
        int numpush = 1, numpop = 0;
        string s = "(";
        process(numpush,numpop,n,s,result);
        return result;
    }
    void process(int numpush, int numpop, int n, string s, vector<string>& result){
        if(numpush == n && numpop == n){
            result.push_back(s);
            return ;
        }
        
        if(numpush > numpop){
            if(numpush < n)
                process(numpush+1,numpop,n,s+"(",result);
            process(numpush,numpop+1,n,s+")",result);
        }else{
            process(numpush+1,numpop,n,s+"(",result);
        }
    }
*/