/*
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

    "123"
    "132"
    "213"
    "231"
    "312"
    "321"

Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
*/

/*

	O(n),逐位逼近k

    string getPermutation(int n, int k) {
        string result;
        int sum = 0;
        vector<char> list;
        int fac[10] = {1,1,2,6,24,120,720,5040,40320,362880};
        for(int i = 1; i <= n; i++){
            list.push_back(i+'0');
        }
        int i = 0, j = n;
        for(;list.size() > 0; ){
            int temp = sum + fac[j-1];
            if(temp < k){
                sum = temp;
                i++;
            }else{
                result.push_back(list[i]);
                list.erase(list.begin() + i);
                i = 0;
                j--;
            }
        }
        return result;
    }
*/