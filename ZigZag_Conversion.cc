/*
 * question:
 *
 *  The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

	P   A   H   N
	A P L S I I G
	Y   I   R

	And then read line by line: "PAHNAPLSIIGYIR"

	Write the code that will take a string and make this conversion given a number of rows:

	string convert(string text, int nRows);

	convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

 *
 */

/*
 * solution:O(n)
 *
 *  string convert(string s, int numRows) {
        if(numRows <= 1)
            return s;
        int len = s.size()-1;
        string result="";
        string* str = new string[numRows];
        for(int i = 0; i < numRows; i++){
            bool flag = true;
            str[i]="";
            for(int j = i; j <= len; ){
                str[i]+=s[j];
                if(i==0||i==numRows-1){
                    j += 2*(numRows-1);
                }else{
                    if(flag){
                        j +=2*(numRows-(i+1));
                        flag = false;
                    }else{
                	    j+=2*i;
                    	flag = true;
                    }
                }
            }
        }
        for(int i = 0; i < numRows; i++){
        	result+=str[i];
        }
        delete []str;
        return result;
	}
 *
 */
