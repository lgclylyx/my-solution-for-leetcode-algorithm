/*
question: Determine whether an integer is a palindrome. Do this without extra space.
*/

/*

主要考虑负数和溢出

    bool isPalindrome(int x) {
        if( x < 0)
            return false;
        int temp = x, cmp = 0;
        while(temp){
            int res = cmp * 10 + temp % 10;
            if(res / 10 != cmp)
                return false;
            cmp = res;
            temp = temp / 10;
        }
        return cmp == x;
    }
*/