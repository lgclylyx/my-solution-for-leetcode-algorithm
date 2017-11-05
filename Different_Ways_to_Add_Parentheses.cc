/*
Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.

Example 1

Input: "2-1-1".

((2-1)-1) = 0
(2-(1-1)) = 2

Output: [0, 2]

Example 2

Input: "2*3-4*5"

(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10

Output: [-34, -14, -10, -10, 10]
*/

/*

	分治算法。在每个符号位置，将表达式分为两部分，这样递归就遍历了所有的
	情况。在递归的过程，存在重复计算的情况，可以使用一个哈希表保存中间结果。

    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        
        for(int i = 0; i < input.size(); i++){
            if(input[i] == '+' || input[i] == '-' || input[i] == '*'){
                vector<int> left = diffWaysToCompute(input.substr(0,i));
                vector<int> right = diffWaysToCompute(input.substr(i+1));
                
                for(auto c : left){
                    for(auto d : right){
                        int t = 0;
                        switch(input[i]){
                            case '+':
                                t = c + d;
                                break;
                            case '-':
                                t = c - d;
                                break;
                            case '*':
                                t = c * d;
                        }
                        res.push_back(t);
                    }
                }
             }
        }
        
        if(res.empty())
            res.push_back(stoi(input));
        return res;
    }
*/
