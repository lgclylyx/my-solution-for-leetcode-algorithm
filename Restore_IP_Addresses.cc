/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter) 
*/

/*

	Backtracking algorithm

    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        string ts;
        solver(result,s,ts,0);
        return result;
    }
    void solver(vector<string>& result, string s, string ts,int count){
        if(count > 4)
            return;
        
        if(s.empty() && count < 4)
            return;
        
        if(s.empty()){
            result.push_back(ts);
            return;
        }
        
        int num = 0;
        for(int i = 0; i < 3 && i < s.size(); i++){
            num = num * 10 + (s[i] - '0');
            if(num > 255 || (i > 0 && (num == 0 || num == (s[i] - '0'))))
                return;
            ts.push_back(s[i]);
            if(count < 3)
                ts.push_back('.');
            solver(result,s.substr(i+1),ts,count+1);
            if(count < 3)
                ts.pop_back();
        }
    }
*/