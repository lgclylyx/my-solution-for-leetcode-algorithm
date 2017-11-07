/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

    You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
    After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)

Example:

prices = [1, 2, 3, 0, 2]
maxProfit = 3
transactions = [buy, sell, cooldown, buy, sell]
*/

/*

	DP.要使用DP算法要解决的问题要具有最优子结构。即在本问题的接解中要包含
	子问题的解。sell[i]表式[0,i]之间以sell操作结尾时的最大值。buy[i]同理。
	所以递归公式是sell[i] = max(sell[i-1],buy[i-1] + prices[i])
	 buy[i] = max(buy[i-1], sell[i-2] - prices[i])

    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1)
            return 0;
        
        int n = prices.size();
        
        vector<int> buy(n,0),sell(n,0);
        buy[0] = -prices[0];
        for(int i = 1; i < n; i++){
            sell[i] = max(sell[i-1],buy[i-1] + prices[i]);
            buy[i] = max(buy[i-1], (i - 2 >= 0 ? sell[i-2]  : 0) - prices[i]);
        }
        return sell[n-1];
    }
*/
