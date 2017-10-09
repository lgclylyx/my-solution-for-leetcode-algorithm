/*
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3

return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?
*/

/*

	don't modify tree's structure.but add a hashtable to store the visited node.

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        unordered_set<TreeNode*> us;
        if(!root)
            return result;
        stack<TreeNode*> cnode;
        cnode.push(root);
        while(!cnode.empty()){
            TreeNode* t = cnode.top();
            
            if(us.find(t) != us.end() || (!t->right && !t->left)){
                result.push_back(t->val);
                cnode.pop();
                continue;
            }
            if(t->right)
                cnode.push(t->right);
            if(t->left)
                cnode.push(t->left);
            us.insert(t);
        }
        return result;
    }
*/

/*

	modify the tree's structure.

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if(!root)
            return result;
        stack<TreeNode*> cnode;
        cnode.push(root);
        while(!cnode.empty()){
            TreeNode* t = cnode.top();
            
            if(!t->right && !t->left){
                result.push_back(t->val);
                cnode.pop();
            }else if(t->left && ! t->right){
                cnode.push(t->left);
                t->left = NULL;
            }else if(t->right && !t->left){
                cnode.push(t->right);
                t->right = NULL;
            }else{
                cnode.push(t->right);
                cnode.push(t->left);
                t->right = NULL;
                t->left = NULL;
            }
        }
        return result;
    }
*/