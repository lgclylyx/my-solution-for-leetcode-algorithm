/*
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Return 6. 
*/

/*

	O(mn)，DP algorithm.要求最大的矩形面积，则需找到矩形的长和高。则使用动态规划算法，计算每个以当前元素为右下角的最大矩形的面积。对
	每个元素维护最大矩形的高和边长。

int maximalRectangle(vector<vector<char>>& matrix) {
    if(matrix.empty()) return 0;
    const int m = matrix.size();
    const int n = matrix[0].size();
    int left[n], right[n], height[n];
    fill_n(left,n,0); fill_n(right,n,n); fill_n(height,n,0);
    int maxA = 0;
    for(int i=0; i<m; i++) {
        int cur_left=0, cur_right=n; 
        for(int j=0; j<n; j++) { // compute height (can do this from either side)
            if(matrix[i][j]=='1') height[j]++; 
            else height[j]=0;
        }
        for(int j=0; j<n; j++) { // compute left (from left to right)
            if(matrix[i][j]=='1') left[j]=max(left[j],cur_left);
            else {left[j]=0; cur_left=j+1;}
        }
        // compute right (from right to left)
        for(int j=n-1; j>=0; j--) {
            if(matrix[i][j]=='1') right[j]=min(right[j],cur_right);
            else {right[j]=n; cur_right=j;}    
        }
        // compute the area of rectangle (can do this from either side)
        for(int j=0; j<n; j++)
            maxA = max(maxA,(right[j]-left[j])*height[j]);
    }
    return maxA;
}

*/

/*

	O(mn),将矩阵看成柱状图，求能组成的最大矩形。

    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = rows == 0 ? 0 : matrix[0].size();
        vector<vector<int>> m(rows,vector<int>(cols,0));
        int result = 0;
        for(int i = 0; i < rows; i++)
            for(int j = 0; j < cols; j++){
                if(i == 0){
                    if(matrix[i][j] == '0')
                        m[i][j] = 0;
                    else
                        m[i][j] = 1;
                }else{
                    if(matrix[i][j] == '0')
                        m[i][j] = 0;
                    else
                        m[i][j] = m[i-1][j] + 1;
                }
            }
        for(int i = 0; i < rows; i++)
            result = max(largestRectangleArea(m[i]),result);
        return result;
    }
    int largestRectangleArea(vector<int>& heights) {
        stack<int> pos;
        int i = 0;
        int max = 0;
        while(i < heights.size()){
            if(pos.empty() || heights[pos.top()] <= heights[i]){
                pos.push(i++);
            }else{
                int tp = pos.top();
                pos.pop();
                int tmax = heights[tp] * (pos.empty() ? i : i - pos.top() - 1);
                if(tmax > max)
                    max = tmax;
            }
        }
        
        while(!pos.empty()){
            int tp = pos.top();
            pos.pop();
            int tmax = heights[tp] * (pos.empty() ? i : i - pos.top() - 1);
            if(tmax > max)
                max = tmax;
        }
        return max;
    }

*/