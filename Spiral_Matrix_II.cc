/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,
You should return the following matrix:

[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/

/*
	
	有限状态机，有四个状态相互转换

    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n,vector<int>(n,0));
        int rowt = 0, rowb = n - 1, coll = 0, colr = n - 1;
        int tag = 0;
        for(int j = 1; j <= n*n; ){
            switch(tag){
                case 0:
                    for(int i = coll; i <= colr; i++,j++){
                        result[rowt][i] = j;
                    }
                    rowt++;
                    tag = 1;
                    break;
                case 1:
                    for(int i = rowt; i <= rowb; i++,j++){
                        result[i][colr] = j;
                    }
                    colr--;
                    tag = 2;
                    break;
                case 2:
                    for(int i = colr; i >= coll; i--,j++){
                        result[rowb][i] = j;
                    }
                    rowb--;
                    tag = 3;
                    break;
                case 3:
                    for(int i = rowb; i >= rowt; i--,j++){
                        result[i][coll] = j;
                    }
                    coll++;
                    tag = 0;
                    break;
            }
        }
        return result;
    }
*/