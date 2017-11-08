/*
You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

Example:

Given nums = [5, 2, 6, 1]

To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.

Return the array [2, 1, 1, 0]. 
*/

/*

	统计每一个位置处的逆序对数量。

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n,0);
        vector<int> index(n,0);
        
        for(int i = 0; i < n; i++)
            index[i] = i;
        
        solver(index,res,nums,0,n-1);
        
        return res;
    }
    
    void solver(vector<int>& index, vector<int>& res,vector<int>& nums, int l,int r){
        if(l >= r){
            return;
        }
        
        int mid = l + (r - l)/2;
        solver(index,res,nums,l,mid);
        solver(index,res,nums,mid+1,r);
        
        int rs = mid + 1, st = l;
        
        vector<int> temp1,temp2;
    
        while(l <= mid && rs <= r){
            if(nums[l] <= nums[rs]){
                temp1.push_back(nums[l]);
                temp2.push_back(index[l]);
                res[index[l]] += (rs - mid - 1);
                l++;
            }else if(nums[l] > nums[rs]){
                temp1.push_back(nums[rs]);
                temp2.push_back(index[rs]);
                rs++;
            }
        }
        
        while(l <= mid){
            temp1.push_back(nums[l]);
            temp2.push_back(index[l]);
            res[index[l]] += (r - mid);
            l++;
        }
        while(rs <= r){
            temp1.push_back(nums[rs]);
            temp2.push_back(index[rs]);
            rs++;
        }
        
        copy_n(temp1.begin(),temp1.size(),nums.begin() + st);
        copy_n(temp2.begin(),temp2.size(),index.begin() + st);
    }
*/