/*
Given a binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

For example:
Given the below binary tree,

       1
      / \
     2   3

Return 6. 
*/

/*

	相当于分治算法，对于一棵树，其最长的路径，要么通过通过根横跨左右子树，要么在左子树或在右子树中。这样就可以将其分解成子问题进行解决。

    int maxPathSum(TreeNode* root) {
        if(!root)
          return 0;  
        int smax = INT_MIN;
        solver(root,smax);
        return smax;
    }
    
    int solver(TreeNode* root, int& smax){
        
        int ltmax = root->left ? solver(root->left,smax) : root->val > 0 ? 0 : root->val  - 1;
        int rtmax = root->right ? solver(root->right,smax) : root->val > 0 ? 0 : root->val  - 1;
        smax = max(smax,max(ltmax,ltmax + root->val));
        smax = max(smax,max(rtmax,rtmax + root->val));
        smax = max(smax,max(root->val,ltmax + rtmax + root->val));
        
        return max(ltmax + root->val,max(root->val,rtmax + root->val));
    }
*/