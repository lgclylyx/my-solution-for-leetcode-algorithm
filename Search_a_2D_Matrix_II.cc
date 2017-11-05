/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

    Integers in each row are sorted in ascending from left to right.
    Integers in each column are sorted in ascending from top to bottom.

For example,

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]

Given target = 5, return true.

Given target = 20, return false.
*/

/*

    对每一行进行二项搜索，O(mlogn)

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty())
            return false;
        int len = matrix[0].size()-1;
        for(int i = 0; i < matrix.size(); i++){
            if(target >= matrix[i][0] && target <= matrix[i][len])
                if(binary_search(matrix[i].begin(),matrix[i].end(),target))
                    return true;
        }
        return false;
    }
*/

/*

    O(m+n),因为是有序的，所以可以根据目标值和当前位置的值的大小，找到一条从右上角到目标值的路径，最坏情况O(m+n)

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty())
            return false;
        int len = matrix[0].size()-1;
        int row = 0;
        while(row < matrix.size() && len >= 0){
            if(matrix[row][len] == target)
                return true;
            else if(matrix[row][len] < target)
                row++;
            else
                len--;
        }
        return false;
    }
*/
