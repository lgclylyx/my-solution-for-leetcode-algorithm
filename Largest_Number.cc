/*
Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.
*/

/*

	字符串能够直接进行大小比较

    struct greaterComp{
        bool operator () (const string& a, const string & b){
            return a+b > b+a;
        }
    };
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        for(int i=0;i<nums.size();i++){
            v.push_back(to_string(nums[i]));
        }
        sort(v.begin(), v.end(),greaterComp());
        string ans = "";
        for(int i=0;i<v.size();i++){
            ans += v[i];
        }
        while(ans[0]=='0' && ans.length()>1)
            ans.erase(0,1);
        return ans;
    } 
*/