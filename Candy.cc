/*
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

    Each child must have at least one candy.
    Children with a higher rating get more candies than their neighbors.

What is the minimum candies you must give? 
*/

/*

	use a min_pq.

    int candy(vector<int>& ratings) {
        if(ratings.empty())
            return 0;
        if(1 == ratings.size())
            return 1;
        vector<pair<int,int>> p_r;
        vector<int> cand(ratings.size(), 0);
        int total = 0;
        for(int i = 0; i < ratings.size();i++){
            p_r.push_back(pair<int,int>(ratings[i],i));
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,comp> pq(p_r.begin(),p_r.end());
        while(!pq.empty()){
            pair<int,int> tmin = pq.top();
            pq.pop();
            int pos = tmin.second;
            int tpos;
            if(pos - 1 < 0 || pos + 1 == ratings.size()){
                if(pos - 1 < 0)
                    tpos = pos + 1;
                else
                    tpos = pos - 1;
                if(ratings[pos] < ratings[tpos])
                    cand[pos] = 1;
                else if(ratings[pos] > ratings[tpos]){
                    cand[pos] =cand[tpos] + 1;
                }else
                    cand[pos] = 1;
            }else{
                if(ratings[pos] < min(ratings[pos - 1],ratings[pos+1]))
                    cand[pos] = 1;
                else if(ratings[pos] > max(ratings[pos - 1],ratings[pos+1]))
                    cand[pos] = max(cand[pos+1] , cand[pos-1]) + 1;
                else if(ratings[pos] == ratings[pos - 1] || ratings[pos] == ratings[pos + 1]){
                    int tpos = ratings[pos] == ratings[pos - 1] ? pos + 1 : pos - 1;
                    if(ratings[tpos] < ratings[pos]){
                        cand[pos] = cand[tpos] + 1;
                    }else{
                        cand[pos] = 1;
                    }
                }else
                    cand[pos] = ratings[pos+1] < ratings[pos-1] ? cand[pos + 1]+1 : cand[pos-1]+1;
            }
            total += cand[pos];
        }
        return total;
    }
}; 
class comp{
public:
    bool operator()(const pair<int,int>& a,const pair<int,int>& b)const{
       	return a.first > b.first;
	}
}
*/

/*

	aother idea,greedy algorithm.

    int candy(vector<int>& ratings) {
        const int n=ratings.size();
        vector<int>amount(n);
        for(int i=1,inc=1;i<n;i++){
            if(ratings[i]>ratings[i-1])
                amount[i]=inc++;
            else inc=1;
        }
        for(int i=n-2,inc=1;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                amount[i]=max(inc,amount[i]);
                inc++;
            }
            else inc=1;
        }
        int sum=n;
        for(int i=0;i<n;i++){
            sum+=amount[i];
        }
        return sum;
    }
*/