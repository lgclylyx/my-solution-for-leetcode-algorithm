/*

Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

*/

/*

	ugly code!!!  

class Solution {
public:
    
    void process(const string& digits, vector<string>& result){
        
        int i = 0;
        int lim;
        switch(digits[i]){
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '8':
                lim = 3;
                break;
            case '9':
            case '7':
                lim = 4;
        }        
        for(int j = 0; j < lim; j++){
            string temp = "";
            int num;
            switch(digits[i]){
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                    num = (digits[i] - '0' - 2) * 3;
                    break;
                case '8':
                    num = ('7'-'0'-2)*3+4;
                    break;
                case '9':
                    num = ('7'-'0'-2)*3+4+3;
            }
            temp = temp + char(num + j + 'a');
            process1(digits,++i,temp,result);
            --i;
        }
    }
    void process1(const string& digits,int& i, string& temp,vector<string>& result){
        if(i >= digits.size()){
            result.push_back(temp);
            return;
        }
        
        int lim;
        switch(digits[i]){
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '8':
                lim = 3;
                break;
            case '9':
            case '7':
                lim = 4;
        }
        
        for(int j = 0; j < lim; j++){
            int num;
            switch(digits[i]){
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                    num = (digits[i] - '0' - 2) * 3;
                    break;
                case '8':
                    num = ('7'-'0'-2)*3+4;
                    break;
                case '9':
                    num = ('7'-'0'-2)*3+4+3;
            }
            temp = temp + char(num + j + 'a');
            process1(digits,++i,temp,result);
            temp.erase(--temp.end());
            --i;
        }
        
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        
        if(digits.size() == 0)
            return result;
        
        if(digits.find('0')!=string::npos || digits.find('1')!=string::npos)
            return result;
        
        process(digits,result);
        
        return result;
    }
};

*/

/*
class Solution {
public:
vector<string> letterCombinations(string digits) {
    vector<string> res;
    if(digits.size() == 0)
        return res;
    if(digits.find('0')!=string::npos || digits.find('1')!=string::npos)
        return res;
    string charmap[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    res.push_back("");
    for (int i = 0; i < digits.size(); i++){
        vector<string> tempres;
        string chars = charmap[digits[i] - '0'];
        for (int c = 0; c < chars.size();c++)
            for (int j = 0; j < res.size();j++)
                tempres.push_back(res[j]+chars[c]);
        res = tempres;
    }
    return res;
}
};
*/