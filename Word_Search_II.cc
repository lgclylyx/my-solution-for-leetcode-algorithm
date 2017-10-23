/*
Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

For example,
Given words = ["oath","pea","eat","rain"] and board =

[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]

Return ["eat","oath"]. 
*/

/*
class TrieNode
{
public:
    TrieNode *next[26];
    bool is_word;
    
    // Initialize your data structure here.
    TrieNode(bool b = false)
    {
        memset(next, 0, sizeof(next));
        is_word = b;
    }
};

class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s)
    {
        TrieNode *p = root;
        for(int i = 0; i < s.size(); ++ i)
        {
            if(p -> next[s[i] - 'a'] == NULL)
                p -> next[s[i] - 'a'] = new TrieNode();
            p = p -> next[s[i] - 'a'];
        }
        p -> is_word = true;
    }

    // Returns if the word is in the trie.
    bool search(string key)
    {
        TrieNode *p = find(key);
        return p != NULL && p -> is_word;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix)
    {
        return find(prefix) != NULL;
    }

    TrieNode* find(string key)
    {
        TrieNode *p = root;
        for(int i = 0; i < key.size() && p != NULL; ++ i)
            p = p -> next[key[i] - 'a'];
        return p;
    }
};


将待查找的单词组成一颗前缀树（trie），然后在字典中的每一个开始的位置进行查找，在前缀树中进行匹配。
使用trie的优点在于，每次都可以对整个待查找的单词组进行查找，而不用对每个单词分别进行不必要的查找。

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        vector<string> res;
        for(auto c : words)
            trie.insert(c);
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                string t;
                solver(res,t,board,trie.root,i,j);
            }
        }
        return res;
    }
    void solver(vector<string>& res, string& t,vector<vector<char>>& board,TrieNode *p, int i, int j){
        if(p->is_word){
            p->is_word = false;
            res.push_back(t);
        }
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == '\0')
            return ;
        char c = board[i][j];
        p = p ->next[c - 'a'];
        if(!p)
            return;
        t.push_back(c);
        board[i][j] = '\0';
        solver(res,t,board,p,i,j+1);
        solver(res,t,board,p,i,j-1);
        solver(res,t,board,p,i+1,j);
        solver(res,t,board,p,i-1,j);
        board[i][j] = c;
        t.pop_back();
    }
};
*/