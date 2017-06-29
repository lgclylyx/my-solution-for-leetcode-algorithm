/*

question: Integer to Roman 

Given an integer, convert it to a roman numeral.
Input is guaranteed to be within the range from 1 to 3999.

*/

/*
	string intToRoman(int num) {
        string result = "",str;
        stack<string> strstack;
        char sign[] = {'I','V','X','L','C','D','M'};//可以通过扩展sign来扩充可以变换的范围
        for(int i = 0;num > 0; i+=2){
            int temp = num % 10;
            str = "";
            switch(temp){
                case 1:
                case 2:
                case 3:
                    while(temp-- > 0)
                        str+=sign[i];
                        strstack.push(str);
                    break;
                case 4:
                    str+=sign[i];
                    str+=sign[i+1];
                    strstack.push(str);
                    break;
                case 5:
                    str+=sign[i+1];
                    strstack.push(str);
                    break;
                case 6:
                case 7:
                case 8:
                    str+=sign[i+1];
                    while(temp-->5)
                        str+=sign[i];
                    strstack.push(str);
                    break;
                case 9:
                    str+=sign[i];
                    str+=sign[i+2];
                    strstack.push(str);
                    break;
                case 0:
                    ;
            }
            num = num / 10;
        }
        while(!strstack.empty()){
            result += strstack.top();
            strstack.pop();
        }
        return result;
    }
*/