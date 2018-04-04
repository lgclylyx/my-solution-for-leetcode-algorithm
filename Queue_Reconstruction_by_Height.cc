/*Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.

Example

Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
*/

/*

  将输入按照p.h从大到小，并p.k从小到大进行排序；然后再按排序后的顺序，按p.k进行插入。因为对于P.K有影响的只是
  其h值的输入，小于其h值的pair的位置对其无影响，所以值需在插入时确定其与比其大的pair的位置即可。

    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<pair<int,int>> res;
        sort(people.begin(),people.end(),[](pair<int,int>& a ,pair<int,int>& b) -> bool{
            if(a.first == b.first)
                return a.second < b.second;
            if(a.first > b.first)
                return true;
            else
                return false;
        });
        for(auto& p : people){
            res.insert(res.begin()+p.second,p);
        }
        return res;
    }
*/
