/*
You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).
*/

/*
solution 1: o(kn-k^2*m)，最坏情况下为O(n^2)
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        unordered_multiset<string> wordss;//将words构建成散列表
        for(int i = 0; i < words.size(); i++)
            wordss.insert(words[i]);
        for(int i = 0; i < s.size() && i+words.size()*words[0].size() <= s.size();i+=1){//迭代所有可能的起点
            unordered_multiset<string> temp = wordss;
            int j = i;
            while(0 != temp.size()){//对于每一个可能的起点i,判断km长度的窗口内的子串是否是由words构成的
                auto itr = temp.find(s.substr(j,words[0].size()));//判断子串类的每个子窗口，看是否是Words中的元素
                if(itr != temp.end()){//如果是则去除
                    temp.erase(itr);
                }else
                    break;
                j = j + words[0].size();
            }
            if(0 == temp.size())//如果以i为起点的窗口是正好由words中所有元素构成，则temp将会被清空
                result.push_back(i);
        }
        return result;
    }
*/

/*
solution 2: O(n)
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        unordered_map<string,int> wordss;//将words构建成散列表
        for(int i = 0; i < words.size(); i++)
            wordss[words[i]]++;
        
        for(int i = 0; i < words[0].size(); i++){
            int left = i;//left一直指向滑动窗口的最左边一个子窗口
            int count = 0;//cout表示滑动窗口中子窗口的数目，即包含words中元素的数目
            unordered_map<string,int> temp;//窗口中元素构成的散列
            for(int j = i; j <= int(s.size())-int(words[0].size()); j+=words[0].size()){//j指向窗口最右边的一个子窗口，窗口的大小随着
                string str = s.substr(j,words[0].size());//j的移动而增加
                if(wordss[str]){//如果j所指的元素在words中
                    temp[str]++;//则将其添加进散列表
                    if(temp[str] <= wordss[str])//并且窗口中的元素对于words来说没有重复的元素
                        count++;//则将其添加进窗口
                    else{//如果重复了，则将从left到重复元素之间的窗口中的元素都删除掉（left->>k->>j,left->>k删除）
                        while(temp[str] > wordss[str]){//这么做的原因在于，既然j与k重复，则left到k之间的元素到j都不会是合法的排列
                            string strtemp = s.substr(left,words[0].size());
                            temp[strtemp]--;
                            if(temp[strtemp] < wordss[strtemp])
                                count--;
                            left = left + words[0].size();
                        }
                    }
                    if(count == words.size())//如果窗口内的元素数目等于words中的元素数目，且保证的temp是wordss的一个排列，则left是一个合法起点
                        result.push_back(left);
                }else{//如果j指向的s中的元素，不是words中的一个元素，则left->j这一段应该废弃活动窗口从下一个位置从0长度开始
                    temp.clear();
                    count = 0;
                    left = j + words[0].size();
                }
            }
        }
        return result;
    }
*/
