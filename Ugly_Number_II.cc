/*
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number, and n does not exceed 1690. 
*/
/*

	DP algorithm.O(n).从小到大依次计算每一个ugly number

    int nthUglyNumber(int n) {
        vector<int> dp;
        
        for(int i = 0; i <= 6; i++)
            dp.push_back(i);
        if(n <= 6)
            return dp[n];
        int r2 = 4,r3 = 3,r5 = 5;
        for(int i = 7; i <= n; i++){
            int t2 = 2*dp[r2];
            int t3 = 3*dp[r3];
            int t5 = 5*dp[r5];
            int t = min(t2,min(t3,t5));
            if(t == t2)
                r2++;
            if(t == t3)
                r3++;
            if(t == t5)
                r5++;
            dp.push_back(t);
        }
        return dp.back();
    }
*/
