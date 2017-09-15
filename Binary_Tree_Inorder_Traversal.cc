/*
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],

   1
    \
     2
    /
   3

return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?
*/

/*

	inorder traversal with iteratively

    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* p = root;
        vector<int> result;
        if(NULL != p){
            st.push(p);
            p = p->left;
        }
        while(!st.empty()){
            while(p){
                st.push(p);
                p = p->left;
            }
            
            do{
                p = st.top();
                st.pop();
                result.push_back(p->val);
                if(p->right){
                    st.push(p->right);
                    p = p->right->left;
                    break;
                }
            }while(!st.empty());
        }
        return result;
    }
*/