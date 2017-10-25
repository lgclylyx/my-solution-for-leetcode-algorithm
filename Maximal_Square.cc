/*
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Return 4. 
*/

/*

将2D图看做多个分层的柱状图。然后求解每个柱状图中最大的正方形的面积。

    int maximalSquare(vector<vector<char>>& matrix) {
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
    int largestRectangleArea(vector<int>& heights) {//求解柱状图中的矩形面积
        stack<int> pos;
        int i = 0;
        int max = 0;
        while(i < heights.size()){
            if(pos.empty() || heights[pos.top()] <= heights[i]){
                pos.push(i++);
            }else{
                int tp = pos.top();
                pos.pop();
                int len = (pos.empty() ? i : i - pos.top() - 1);
                int tmax = min(heights[tp],len);
                tmax *= tmax;
                if(tmax > max)
                    max = tmax;
            }
        }
        
        while(!pos.empty()){
            int tp = pos.top();
            pos.pop();
            int len = (pos.empty() ? i : i - pos.top() - 1);
            int tmax = min(heights[tp],len);
            tmax *= tmax;
            if(tmax > max)
                max = tmax;
        }
        return max;
    }
*/

/*

DP algorithm;动态规划最重要的就是设置状态。dp[i][j]代表以i，j为右下角所能张成的正方形的边长。
状态方程如下：
    P[0][j] = matrix[0][j] (topmost row);
    P[i][0] = matrix[i][0] (leftmost column);
    For i > 0 and j > 0: if matrix[i][j] = 0, P[i][j] = 0; if matrix[i][j] = 1, P[i][j] = min(P[i - 1][j], P[i][j - 1], P[i - 1][j - 1]) + 1

int maximalSquare(vector<vector<char>>& matrix) {
    int m = matrix.size();
    if (!m) return 0;
    int n = matrix[0].size();
    vector<vector<int> > size(m, vector<int>(n, 0));
    int maxsize = 0;
    for (int j = 0; j < n; j++) {
        size[0][j] = matrix[0][j] - '0';
        maxsize = max(maxsize, size[0][j]);
    }
    for (int i = 1; i < m; i++) {
        size[i][0] = matrix[i][0] - '0';
        maxsize = max(maxsize, size[i][0]);
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] == '1') {
                size[i][j] = min(size[i - 1][j - 1], min(size[i - 1][j], size[i][j - 1])) + 1;
                maxsize = max(maxsize, size[i][j]);
            }
        }
    }
    return maxsize * maxsize;
}
*/