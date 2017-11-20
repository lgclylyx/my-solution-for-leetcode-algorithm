/*
A sequence of numbers is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

For example, these are arithmetic sequences:

1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9

The following sequence is not arithmetic.

1, 1, 2, 5, 7


A zero-indexed array A consisting of N numbers is given. A subsequence slice of that array is any sequence of integers (P0, P1, ..., Pk) such that 0 ≤ P0 < P1 < ... < Pk < N.

A subsequence slice (P0, P1, ..., Pk) of array A is called arithmetic if the sequence A[P0], A[P1], ..., A[Pk-1], A[Pk] is arithmetic. In particular, this means that k ≥ 2.

The function should return the number of arithmetic subsequence slices in the array A.

The input contains N integers. Every integer is in the range of -231 and 231-1 and 0 ≤ N ≤ 1000. The output is guaranteed to be less than 231-1.

Example:

Input: [2, 4, 6, 8, 10]

Output: 7

Explanation:
All arithmetic subsequence slices are:
[2,4,6]
[4,6,8]
[6,8,10]
[2,4,6,8]
[4,6,8,10]
[2,4,6,8,10]
[2,6,10]
*/

/*

	table[i],值为i的元素在数组中的位置。
	cnt[i][j]以i，j确定的该条等差数列的数目。

	int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size() < 3)
            return 0;
        
        int total = 0;
    
        unordered_map<int, vector<int>> table;
        vector<vector<int>> cnt(A.size(), vector<int>(A.size(), 0));
        
        for(int i = 0; i < A.size(); ++i)
            table[A[i]].push_back(i);
        
        for(int k = 1; k < A.size(); ++k){
            for(int j = k-1; j >= 0; --j)
            {
                long val_i = (long)A[j]*2 - A[k];
                if(val_i > INT_MAX || val_i < INT_MIN || table.find(val_i) == table.end())
                    continue;
                
                for(int i : table[val_i]){
                    if(i >= j)
                        break;
                    
                    cnt[j][k] += cnt[i][j] + 1;//
                }
                total += cnt[j][k];
            }
        }
        return total;
	}
*/