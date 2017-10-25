/*
Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
*/

/*

	一个完全二叉树，在其某些子树上是满二叉树。在每个子树上判断其是否为满二叉树。

    int countNodes(TreeNode* root) {
        if(!root) return 0;

        int hl=0, hr=0;

        TreeNode *l=root, *r=root;

        while(l) {hl++;l=l->left;}

        while(r) {hr++;r=r->right;}

        if(hl==hr) return pow(2,hl)-1;

        return 1+countNodes(root->left)+countNodes(root->right);
    }
*/

/*
    int countNodes(TreeNode* root) {
        int Deep = 0, result = 0;
        if (!root) return 0;
        TreeNode* temp = root, *cur = root;
        while(temp) {
            Deep++;
            temp=temp->left;
        }
        int parentHigh = Deep;//父节点的高度，也就是当前节点的高度
        
        while (parentHigh>1) {//parentHigh表示当前节点，因为要计算子节点即curHigh，所以不能等于0
            cur = root->left;
            int curHigh = parentHigh-1;//当前节点的子节点高度
            for (int i = curHigh; i > 1; i--) cur = cur->right;
            if (cur) {
                root = root->right;
                result += 1<<(curHigh-1);
            }else{
                root=root->left;
            }
            parentHigh--;        
        }
        if (root) result++;
        return result + (1<<(Deep-1))-1;
    }
*/