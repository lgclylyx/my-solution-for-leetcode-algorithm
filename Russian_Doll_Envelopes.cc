/*
You have a number of envelopes with widths and heights given as a pair of integers (w, h). 
One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.

What is the maximum number of envelopes can you Russian doll? (put one inside other)

Example:
Given envelopes = [[5,4],[6,4],[6,7],[2,3]], the maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]). 
*/

/*

	O(nlogn).先将数组对按first升序，second降序排序。这时问题就转化为了Longest Increasing Subsequence 这一问题。
	即求出second中最大长度升序序列。求该序列，维持一个有序数组，则在其中使用二分查找找到第一个比现在处理的值要
	大于或等于的书，用正在处理的数进行替换。这样处理，当以当前数结尾的序列小于现在状态的最长序列时，则无影响，
	否则最长序列长度加1.

    int maxEnvelopes(vector<pair<int, int>>& es) {
        if(es.empty())
            return 0;
        sort(es.begin(),es.end(),[](pair<int,int>& a,pair<int,int>& b){
           return a.first < b.first || (a.first == b.first && a.second > b.second); 
        });
        
        vector<int> dp;
        
        for(auto c : es){
            auto itr = lower_bound(dp.begin(),dp.end(),c.second);
            if(itr == dp.end())
                dp.push_back(c.second);
            else if(c.second < *itr)
                *itr = c.second;
        }
        return dp.size();
    }
*/