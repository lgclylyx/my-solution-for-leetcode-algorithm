/*
A frog is crossing a river. The river is divided into x units and at each unit there may or may not exist a stone. The frog can jump on a stone, but it must not jump into the water.

Given a list of stones' positions (in units) in sorted ascending order, determine if the frog is able to cross the river by landing on the last stone. Initially, the frog is on the first stone and assume the first jump must be 1 unit.

If the frog's last jump was k units, then its next jump must be either k - 1, k, or k + 1 units. Note that the frog can only jump in the forward direction.

Note:

    The number of stones is ≥ 2 and is < 1,100.
    Each stone's position will be a non-negative integer < 231.
    The first stone's position is always 0.

Example 1:

[0,1,3,5,6,8,12,17]

There are a total of 8 stones.
The first stone at the 0th unit, second stone at the 1st unit,
third stone at the 3rd unit, and so on...
The last stone at the 17th unit.

Return true. The frog can jump to the last stone by jumping 
1 unit to the 2nd stone, then 2 units to the 3rd stone, then 
2 units to the 4th stone, then 3 units to the 6th stone, 
4 units to the 7th stone, and 5 units to the 8th stone.

Example 2:

[0,1,2,3,4,8,9,11]

Return false. There is no way to jump to the last stone as 
the gap between the 5th and 6th stone is too large.
*/

/*

	backtracking.O(2^n).最容易想到的方法，遍历每一种情况。

    bool canCross(vector<int>& stones) {
        if(stones.empty() || (stones.size() > 1 && stones[0] + 1 != stones[1]))
            return false;
        
        unordered_map<int,int> us;
        for(int i = 0; i < stones.size(); i++)
            us[stones[i]] = i;
        return solver(0,1,2,us,stones,1);
    }
    
    bool solver(int left,int mid,int right, unordered_map<int,int>& us,vector<int>& stones,int pos){
        if(pos == stones.size()-1)
            return true;
        
        if(left > 0 && us.find(stones[pos] + left) != us.end())
            if(solver(left-1,left,left+1,us,stones,us[stones[pos] + left]))
                return true;
        if(us.find(stones[pos] + mid) != us.end())
            if(solver(mid-1,mid,mid+1,us,stones,us[stones[pos] + mid]))
                return true;
        if(us.find(stones[pos] + right) != us.end())
            if(solver(right-1,right,right+1,us,stones,us[stones[pos] + right]))
                return true;
        return false;
    }
*/

/*

	memorize.因为存在很多重叠的子问题。记录这些子问题的解，大大降低时间复杂度。

    bool canCross(vector<int>& stones) {
        if(stones.empty() || (stones.size() > 1 && stones[0] + 1 != stones[1]))
            return false;
        
        unordered_map<int,int> us;
        unordered_map<int,unordered_set<int>> um;
        for(int i = 0; i < stones.size(); i++)
            us[stones[i]] = i;
        return solver(0,1,2,us,stones,1,um);
    }
    
    bool solver(int left,int mid,int right, unordered_map<int,int>& us,vector<int>& stones,int pos,unordered_map<int,unordered_set<int>>& um){
        if(pos == stones.size()-1)
            return true;
        
        bool flag = (um.find(pos) == um.end()) || (um[pos].find(left) == um[pos].end());
        if(flag && left > 0 && us.find(stones[pos] + left) != us.end())
            if(solver(left-1,left,left+1,us,stones,us[stones[pos] + left],um))
                return true;
            else
                um[pos].insert(left);
        
        flag = um.find(pos) == um.end() || um[pos].find(mid) == um[pos].end();
        if(flag && us.find(stones[pos] + mid) != us.end())
            if(solver(mid-1,mid,mid+1,us,stones,us[stones[pos] + mid],um))
                return true;
            else
                um[pos].insert(mid);
        
        flag = um.find(pos) == um.end() || um[pos].find(right) == um[pos].end();
        
        if(flag && us.find(stones[pos] + right) != us.end())
            if(solver(right-1,right,right+1,us,stones,us[stones[pos] + right],um))
                return true;
            else
                um[pos].insert(right);
        return false;
    }
*/