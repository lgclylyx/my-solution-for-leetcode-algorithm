/*
 * question: Regular Expression Matching
 *
	'.' Matches any single character.
	'*' Matches zero or more of the preceding element.

	The matching should cover the entire input string (not partial).

	The function prototype should be:
	bool isMatch(const char *s, const char *p)

	Some examples:
	isMatch("aa","a") → false
	isMatch("aa","aa") → true
	isMatch("aaa","aa") → false
	isMatch("aa", "a*") → true
	isMatch("aa", ".*") → true
	isMatch("ab", ".*") → true
	isMatch("aab", "c*a*b") → true
 *
 */

/*
 * 暴力算法
 *
bool isMatch(string s, string p) {
	return isMatch(s, p, 0, 0);
}

bool isMatch(string& s,string& p,int i,int j){
    int lens = s.size();
    int lenp = p.size();

    for(;i<lens&&j<lenp;){
		if(p[j]==s[i]||p[j]=='.'){//p中字符有三种可能，‘。’，‘*’和其他，对于非‘*’的字符，当i,j处字符匹配时
			if(j == lenp-1 || p[j+1]!='*'){//则需要判定其后是否存在‘*’
				i++,j++;//若不存在则直接移动至下一位比较处
			}else{//若存在，则也存在两种情况,一是“。*”的模式和‘a*’的模式
				if(p[j]=='.'){//对于“。*”的模式
					int k =i;
					for(;k<lens;k++)//我们需要对(i,j+2),(i+1,j+2),...,(lens,j+2)进行比对分别代表(null匹配0个前述字符),(.),(..),(...),...等情况
						if(isMatch(s, p, k, j+2))
							break;
					if(k < lens)
						return true;//如果匹配成功,整个串匹配成功
					else
						i=k,j=j+2;//否则对当前的(.*)处理完成，跳跃到下一个匹配点
				}else{//对于“a*”这一模式
					int l = i;
					int k = i;
					while(l<lens-1 && p[j]==s[l+1]){//首先要找到其能在S串中延伸的最大的范围，即(aaaaa...)的最大长度
						l=l+1;
					}
					for(;k<=l;k++)//然后处理（null）,(a),(aa),...等情况，即比对（i,j+2）,(i+1,j+2),...,(i+l,j+k)
						if(isMatch(s, p, k, j+2))
							break;
					if(k <= l)//如果比对成功，则整个串比对成功
						return true;
					else//否则跳过这些比对过的锻，然后从下一位开始继续比对
						i=k,j=j+2;
				}
			}
		}else{//如果i,j处的字符不匹配，
			if(j== lenp-1 || p[j+1]!='*'){//如果其后没有跟随‘*’，则必然匹配失败
				return false;
			}else{//不然，可以将 不匹配的字符用‘*’消去，对剩余部分继续匹配
				return isMatch(s,p,i,j+2);
			}
		}
    }
    while(j+1<lenp){//若存在P串剩余的情况
    	if(p[j+1]=='*')//要考察是否可以将剩余的部分使用‘*’完全消去
    		j=j+2;
    	else
    		break;
    }
    return (i>=lens)&&(j>=lenp);
}
*/
/*
 * DP算法解决
 *
 * vec[i][j]:
 * 	0 1 2 3 4 5...lenp
 * 0
 * 1
 * 2
 * 3
 * 4
 * .
 * .
 * .
 * lens
bool isMatch(string s, string p) {
	int lens = s.size();
	int lenp = p.size();
	vector<vector<bool> > vec(lens+1,vector<bool>(lenp+1,false));
	//vec[i][j]代表s[0,i-1]长度的子串与p[0,j-1]长度的子串德匹配情况
	vec[0][0] = true;//问题边界条件1
	for(int i =1;i<= lens;i++)//问题边界条件2
		vec[i][0]=false;
	for(int j =1;j<=lenp;j++)//问题边界条件3：当存在‘*’时，其结果与vec[0][j-2]的结果一致；
		vec[0][j]= j>1 && '*'==p[j-1] && vec[0][j-2];
	for(int i = 1;i<=lens;i++)//对表中的每一个值进行裘求解
		for(int j = 1;j<=lenp;j++){
			if('*'!=p[j-1])//如果p中的字符不是‘*’，则直接比对
				vec[i][j] = vec[i-1][j-1]&&(p[j-1]==s[i-1]||p[j-1]=='.');
			else//如果是‘*’，该位置的结果为‘x*’代表0字符或者1个字符的情况，vec[i][j-2]代表0个字符，vec[i-1][j]代表一个字符，只有当s[j-1]与p[j-2]匹配时才成立，这种情况代表的是
				vec[i][j] =vec[i][j-2] || ((s[i-1]==p[j-2] || '.'== p[j-2]) && vec[i-1][j]);//vec[i][j]是在vec[i-1][j]的基础上通过‘*’扩展匹配的
		}
	return vec[lens][lenp];
}
*/
