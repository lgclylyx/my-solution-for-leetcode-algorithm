/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.

Example 1:

    2
   / \
  1   3

Binary tree [2,1,3], return true.

Example 2:

    1
   / \
  2   3

Binary tree [1,2,3], return false. 
*/

/*

	迭代处理BST中的每一个节点，判断其是否符合条件pprev表示转折处的节点（如左右），prev为当前处理节点的父节点。

    bool isValidBST(TreeNode* root) {
        return solver(NULL,NULL,root);
    }
    
    bool solver(TreeNode *pprev, TreeNode* prev,TreeNode* root){
        if(!root)
            return true;
        if(!prev)
            return solver(NULL,root,root->left) && solver(NULL,root,root->right);
        else if(!pprev && prev){
            if(root == prev->left){
                if(root -> val < prev->val)
                    return solver(pprev,root,root->left) && solver(prev,root,root->right);
                else
                    return false;
            }else{
                if(root -> val > prev -> val)
                    return solver(prev,root,root->left) && solver(pprev,root,root->right);
                else
                    return false;
            }
        }else{
            if(root == prev->left){
                if(prev == pprev->left){
                    if(root->val < prev -> val)
                        return solver(prev,root,root->left) && solver(pprev,root,root->right);
                    else
                        return false;
                }else{
                    if(root->val < prev -> val && root -> val > pprev->val)
                        return solver(pprev,root,root->left) && solver(prev,root,root->right);
                    else
                        return false;
                }
            }else{
                if(prev == pprev->right){
                    if(root->val > prev -> val)
                        return solver(pprev,root,root->left) && solver(prev,root,root->right);
                    else
                        return false;
                }else{
                    if(root->val > prev -> val && root -> val < pprev->val)
                        return solver(prev,root,root->left) && solver(pprev,root,root->right);
                    else
                        return false;
                }
            }
        }
    }
*/

/*
idea: 可以使用中序遍历，对于一个BST使用中序遍历，生成一个有序数组，判断最后生成的数组是否有序就可以判断，是否为一BST
*/