/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3

Note:
Bonus points if you could solve it both recursively and iteratively. 
*/

/*
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        swapnode(root->right);
        return isSameTree(root->left,root->right);
    }
    
    void swapnode(TreeNode* root){
        if(!root)
            return;
        TreeNode* t = root->left;
        root->left = root->right;
        root->right = t;
        swapnode(root->left);
        swapnode(root->right);
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)
            return true;
        if((p && !q) || (q && !p))
            return false;
        if(p->val != q->val)
            return false;
        
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
*/