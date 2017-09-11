/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given heights = [2,1,5,6,2,3],
return 10. 
*/

/*

	本问题的主要任务：假设在位置i，则要计算以heights[i]为高的矩形面积，则应该在其左右两边找到首次小于heights[i]的位置


	O(n)

    int largestRectangleArea(vector<int>& heights) {
        stack<int> pos;
        int i = 0;
        int max = 0;
        while(i < heights.size()){
            if(pos.empty() || heights[pos.top()] <= heights[i]){//栈底保存的是到位置i-1为止的最小值的位置
                pos.push(i++);//一旦遇到了一个比当前栈顶位置的值小的值时，则比栈顶位置的元素的右边位置找到，而左边位置以在栈中
            }else{
                int tp = pos.top();//所以可以计算出该位置的值为边的矩形面积。
                pos.pop();
                int tmax = heights[tp] * (pos.empty() ? i : i - pos.top() - 1);
                if(tmax > max)
                    max = tmax;
            }
        }
        
        while(!pos.empty()){
            int tp = pos.top();
            pos.pop();
            int tmax = heights[tp] * (pos.empty() ? i : i - pos.top() - 1);
            if(tmax > max)
                max = tmax;
        }
        return max;
    }
*/

/*

	Divide & conquer algorithm: 对于每一个问题都有三种情况，最优为左和右或者横跨左右。这可以用分治算法解决。

	O(nlogn)

    int largestRectangleArea(vector<int>& heights) {
        if(heights.empty())
            return 0;
        return solver(heights,0,heights.size()-1);
        
    }
    
    int solver(vector<int>& heights, int left, int right){
        if(left == right){
            return heights[left];
        }
        int mid = (left+right) / 2;
        
        int area1 = solver(heights,left,mid);
        int area2 = solver(heights,mid+1,right);
        int area = max(area1,area2);
        
        int i = mid, j = mid+1;
        int h = min(heights[i], heights[j]);
        while(i >= left && j <= right){
            h = min(h,min(heights[i], heights[j]));
            area = max(area,h * (j - i + 1));
            if(j == right)
                i--;
            else if(i == left)
                j++;
            else{
                if(heights[i-1] > heights[j+1])
                    i--;
                else
                    j++;
            }
        }
        return area;
    }
*/