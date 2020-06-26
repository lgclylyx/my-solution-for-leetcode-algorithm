/*
Implement the StreamChecker class as follows:

    StreamChecker(words): Constructor, init the data structure with the given words.
    query(letter): returns true if and only if for some k >= 1, the last k characters queried (in order from oldest to newest, including this letter just queried) spell one of the words in the given list.

 

Example:

StreamChecker streamChecker = new StreamChecker(["cd","f","kl"]); // init the dictionary.
streamChecker.query('a');          // return false
streamChecker.query('b');          // return false
streamChecker.query('c');          // return false
streamChecker.query('d');          // return true, because 'cd' is in the wordlist
streamChecker.query('e');          // return false
streamChecker.query('f');          // return true, because 'f' is in the wordlist
streamChecker.query('g');          // return false
streamChecker.query('h');          // return false
streamChecker.query('i');          // return false
streamChecker.query('j');          // return false
streamChecker.query('k');          // return false
streamChecker.query('l');          // return true, because 'kl' is in the wordlist

 

Note:

    1 <= words.length <= 2000
    1 <= words[i].length <= 2000
    Words will only consist of lowercase English letters.
    Queries will only consist of lowercase English letters.
    The number of queries is at most 40000.
*/

/*
class StreamChecker {
public:
    StreamChecker(vector<string>& words){ // construct trie tree
        for(int i = 0; i < words.size(); i++) {
            auto& tmp = words[i];
            auto troot = &root;
            for(int j = tmp.size() - 1; j >= 0; j--) {
                auto& p = troot->trees[tmp[j] - 'a'];
                if(p) {
                    troot = p;
                } else {
                    TreeNode* t = new TreeNode;
                    p = t;
                    troot = p;
                }
            }
            troot->completed = true;
        }
    }
    
    bool query(char letter) { // search
        str.push_back(letter);
        auto troot = &root;
        int i;
        for(i = str.size() - 1; i >= 0; i--) {
            auto& p = troot->trees[str[i] - 'a'];
            if(p) {
                troot = p;
            } else {
                break;
            }
            if(troot->completed)
                return true;
        }
        return false;
    }

private:
    struct TreeNode {
        vector<TreeNode*> trees;
        bool completed;
        TreeNode(): trees(26, NULL), completed(false) {}
    };
    string str;
    TreeNode root;
};
*/