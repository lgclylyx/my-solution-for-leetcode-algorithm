/*
Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

/*

	Divide & conquer;每次选取一个数作为子树的根，然后将有序数组分为两部分，左边的只能作为根的左子树，
	右边的只能作为右子树，所以可以不断重复这个过程。

    vector<TreeNode*> generateTrees(int n) {
        return solver(1,n);
    }
    
    vector<TreeNode*> solver(int start,int end){
        vector<TreeNode*> vect;
        if(start > end){
            vect.push_back(NULL);
            return vect;
        }
        
        if(start == end){
            vect.push_back(new TreeNode(start));
            return vect;
        }
        
        vector<TreeNode*> left,right;
        
        for(int i = start; i <= end; i++){
            left = solver(start,i-1);//每次分为左，右两颗子树
            right = solver(i+1,end);
            for(auto l : left)
                for(auto r : right){//遍历以i为根时，左右子树的所有情况
                    TreeNode* root = new TreeNode(i);
                    root -> left = l;
                    root -> right = r;
                    vect.push_back(root);
                }
        }
        return vect;
    }
*/