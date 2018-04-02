/*
Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks.Tasks could be done without original order. Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.

However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals that CPU are doing different tasks or just be idle.

You need to return the least number of intervals the CPU will take to finish all the given tasks.

Example 1:

Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.

Note:

    The number of tasks is in the range [1, 10000].
    The integer n is in the range [0, 100].
*/

/*

  使用优先队列每次取出值剩余次数最大的n+1个任务，这就是该轮需要执行的任务数；则下一轮开始时，取出的n+1个任务
  都是符合同一个任务相隔n的约束条件的。

    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26,0);
        for(auto c : tasks)
            count[c-'A']++;
        priority_queue<int> pq;
        int cycle = n + 1;
        int res = 0;
        
        for(int i : count)
            if(i > 0)
                pq.push(i);
        
        while(!pq.empty()){
            vector<int> temp;
            int time = 0;
            for(int i = 0; i < cycle; i++){
                if(!pq.empty()){
                    temp.push_back(pq.top());
                    pq.pop();
                    time++;
                }else
                    break;
            }
            
            for(int i : temp)
                if(i-1 > 0)
                    pq.push(i-1);
            
            res+= pq.empty()? time : cycle;//如果为空，则说明所有任务在这轮结束了，且没有用完本轮的时间；队列不为空，则说明本轮的时间都被使用了
        }
        
        return res;
    }
*/
