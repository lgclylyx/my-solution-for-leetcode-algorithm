/*
Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:

    Only one letter can be changed at a time
    Each transformed word must exist in the word list. Note that beginWord is not a transformed word.

For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]

Return

  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]

Note:

    Return an empty list if there is no such transformation sequence.
    All words have the same length.
    All words contain only lowercase alphabetic characters.
    You may assume no duplicates in the word list.
    You may assume beginWord and endWord are non-empty and are not the same.

UPDATE (2017/1/20):
The wordList parameter had been changed to a list of strings (instead of a set of strings). Please reload the code definition to get the latest changes. 
*/

/*

	Time Limit Exceeded; backtracking algorithm,相当于遍历所有情况，这是一个DFS，通过一个DFS会从图中生成一颗高度最高的树

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> tresult;
        vector<string> temp;
        int min = INT_MAX;
        temp.push_back(beginWord);
        solver(tresult,temp,beginWord,endWord,wordList,min);
        return tresult;
    }
    
    void solver(vector<vector<string>>& result, vector<string> temp, string& beginWord, string& endWord, vector<string>& wordList,int& min ){
        
        for(int i = 0; i < wordList.size(); i++){
            int sum = 0;
            for(int j = 0; j < beginWord.size(); j++){
                if(beginWord[j] != wordList[i][j])
                    sum++;
            }
            if(sum == 1){
               if(wordList[i] == endWord){
                   temp.push_back(endWord);
                   if(temp.size() < min){
                       min = temp.size();
                       result.clear();
                   }
                   result.push_back(temp);
                   return;
               }else{
                   if(temp.size() + 1 < min){
                       temp.push_back(wordList[i]);
                       wordList.erase(wordList.begin()+i);
                       solver(result,temp,temp.back(),endWord,wordList,min);
                       wordList.insert(wordList.begin()+i,temp.back());
                       temp.pop_back();
                   }
               }
            }
        }
    }
*/


/*

	Time Limit Exceeded; DFS, 这相当于在一个无权图中，寻找最短路径

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> tresult;
        vector<string> temp;
        int min  = INT_MAX;
        temp.push_back(beginWord);
        solver(tresult,temp,beginWord,endWord,wordList,min);
        return tresult;
    }
    
    void solver(vector<vector<string>>& result, vector<string> temp, string& beginWord, string& endWord, vector<string>& wordList,int & min){
        queue<string> que;
        vector<string> tlist;
        for(int i = 0; i < wordList.size(); i++){//效率问题
            int sum  = 0;
            for(int j = 0; j < wordList[i].size(); j++){
                if(beginWord[j] != wordList[i][j])
                    sum++;
            }
            if(sum == 1){
                if(endWord == wordList[i]){
                    temp.push_back(endWord);
                    if(temp.size() < min){
                        min = temp.size();
                        result.clear();
                    }
                    result.push_back(temp);
                    return;
                }else{
                    que.push(wordList[i]);
                }
            }else{
                tlist.push_back(wordList[i]);
            }
        }
        
        while(que.size()){
            temp.push_back(que.front());
            if(temp.size() < min)
                solver(result,temp,que.front(),endWord,tlist,min);
            que.pop();
            temp.pop_back();
        }
    }
*/

/*

	AC,BFS;与上述方法不同之处在于，该算法每次处理一层的节点，而上述的算法每次处理一层中的一个节点，每次都会去遍历一遍可选的子节点集，所以
	会导致效率问题。该算法，每次处理一层的节点，从图中构建一颗符合要求的树。然后从叶节点遍历回根。

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> cur;
        unordered_set<string> list(wordList.begin(),wordList.end());
        unordered_map<string,unordered_set<string>> path;//为一反向邻接表
        cur.insert(beginWord);
        solver(cur,endWord,list,path);
        
        vector<vector<string>> result;
        vector<string> temp;
        if(path.count(endWord) > 0)
            solver2(path,result,beginWord,endWord,temp);
        return result;
    }
    
    void solver(unordered_set<string>& cur,string& endWord, unordered_set<string>& wordList,unordered_map<string,unordered_set<string>>& path){
        unordered_set<string> next;//下一层的节点
        
        for(auto itr = cur.begin(); itr != cur.end(); itr++){
            for(int i = 0; i < endWord.size(); i++){//寻找当前节点的合法的子节点
                for(int j = 0; j < 26; j++){
                    string temp = *itr;
                    if(temp[i] == 'a'+j)
                        continue;
                    temp[i] = 'a'+j;
                    if(wordList.find(temp) != wordList.end()){
                        next.insert(temp);
                        path[temp].insert(*itr);
                    }
                }
            }
        }
        
        for(auto itr = next.begin(); itr != next.end(); itr++){//上层使用过的节点，在下层不使用
                wordList.erase(*itr);
        }
        if(next.empty())
            return;
        solver(next,endWord,wordList,path);
    }
    void solver2(unordered_map<string,unordered_set<string>>& path, vector<vector<string>>& result,string& begin,string end,vector<string> temp){
        temp.push_back(end);
        if(begin == end){
            reverse(temp.begin(),temp.end());
            result.push_back(temp);
            return;
        }
        auto t = path[end];
        for(auto tt = t.begin(); tt != t.end(); tt++){
            solver2(path,result,begin,*tt,temp);
        }
        temp.pop_back();
    }

*/