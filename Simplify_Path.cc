/*
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"

click to show corner cases.
Corner Cases:

    Did you consider the case where path = "/../"?
    In this case, you should return "/".
    Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
    In this case, you should ignore redundant slashes and return "/home/foo".
*/

/*

	in this question, deque is a better choice.

    string simplifyPath(string path) {
        string copy , result;
        deque<string> s;
        istringstream iss(path);
        
        while(getline(iss,copy,'/')){
            
            if("" == copy||"." == copy)
                continue;
            else if(".." == copy){
                if(!s.empty())
                    s.pop_back();
            }else{
                s.push_back(copy);
            }
        }
        
        result.push_back('/');
        while(!s.empty()){
            result.append(s.front());
            s.pop_front();
            if(!s.empty())
                result.push_back('/');
        }
        return result;
    }
*/