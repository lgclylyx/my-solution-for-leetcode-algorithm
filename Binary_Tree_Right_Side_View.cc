/*
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---

You should return [1, 3, 4]. 
*/

/*

	在while循环内部要找出对每个节点都一致的公共操作。

    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root)
            return res;
        stack<TreeNode*> st;
        stack<int> hs;
        unordered_set<int> us;
        int h = 0;
        st.push(root);
        hs.push(h);
        while(!st.empty()){
            TreeNode *t = st.top();
            h = hs.top();
            st.pop();
            hs.pop();
            if(us.find(h) == us.end()){
                us.insert(h);
                res.push_back(t->val);
            }
            if(t->left){
                st.push(t->left);
                hs.push(h+1);
            }
            if(t->right){
                st.push(t->right);
                hs.push(h+1);
            }
        }
        return res;
    }
*/