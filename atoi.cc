/*
question : String to Integer (atoi) 
*/

/*
对字符串内的每一个字符依次处理，将会遇到4种情况，首先是数字字符，前置空格，符号和其他空格
对此，我们将进行分别处理。对遇到数字字符时，则将其加入最终结果，在期间要判定是否溢出；然后对于
字符串首部的空格则忽略，符号和第一个字符串后的空格不能忽略。对于符号同理。

int myAtoi(string str) {
        int result = 0;
        int len = str.size();
        bool flag = true;
        bool signflag = true;
        int sign = 1;
        for(int i = 0; i < len; i++){
            char c= str[i];
            int k;
            if(c >= '0' && c <= '9')
                k =1;
            else if((c == '+' || c=='-') && signflag)
                k = 2;
            else if(c == ' '&&flag)
                k = 3;
            else
                k = 4;
            
            switch(k){
                case 1:
                {
                    int temp = result * 10;
                    if(temp/10 != result)
                        if(sign == 1)
                            return INT_MAX;
                        else
                            return INT_MIN;
                    result = temp + (c-'0');
                    if(result < temp)
                        if(sign == 1)
                            return INT_MAX;
                        else
                            return INT_MIN;
                }
                    if(flag)
                        flag = false;
                    if(signflag)
                        signflag = false;
                    break;
                case 2:
                    if(c == '-')
                        sign = -1;
                    if(signflag)
                        signflag = false;
                    if(flag)
                        flag = false;
                    break;
                case 3:
                    break;
                case 4:
                    return result*sign;
            }
        }
        return result*sign;
 }
 */