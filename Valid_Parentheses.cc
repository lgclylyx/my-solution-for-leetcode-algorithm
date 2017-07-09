/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

/*
	使用栈
    bool isValid(string s) {
        if(s.size() == 0)
            return true;
        stack<char> stacks;
        for(int i = 0; i < s.size(); i++){
            char c;
            switch(s[i]){
                case '}':
                    c = '{';
                    break;
                case ']':
                    c = '[';
                    break;
                case ')':
                    c = '(';
                    break;
                default:
                    stacks.push(s[i]);
                    continue;
            }
            if(!stacks.empty()&&c == stacks.top())
                stacks.pop();
            else
                return false;
        }
        if(stacks.empty())
            return true;
        return false;
    }
*/