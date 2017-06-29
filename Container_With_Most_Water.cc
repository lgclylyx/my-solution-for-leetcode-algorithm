/*
question : 
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
Note: You may not slant the container and n is at least 2. 	
*/


/*
	暴力算法O(n^2)


	    1 2 3 4 5 6
	  1 x 
      2 x x
      3 x x x 
      4 x x x x
      5 x x x x x
      6 x x x x x x

	暴力算法计算计算矩阵中除x以外的其它位置O((n+1)n/2)，但是根据题意有很多位置并不需要计算，




    int maxArea(vector<int>& height) {
        if(height.size() < 2)
            return 0;
        int result = 0;
        for(int i =0;i<height.size();i++)
        	for(int j =i+1;j < height.size();j++)
            	result = max(result,min(height[i],height[j])*(j-i));
        return result;
    }
*/


/*
 *O(n)
	

		1 2 3 4 5 6
	  1 x         o
      2 x x
      3 x x x 
      4 x x x x
      5 x x x x x
      6 x x x x x x

	从（1,6）即(1,size)开始计算，如果height[1] > height[6],则(2,6),(3,6),(4,6),(5,6)都不需要计算，因为（1,6）之间的距离最大，而height[1] > height[6]，
	则面积为（6-1）* height[6],对于(2,6),(3,6),(4,6),(5,6)不论height[i]比height[6]是大还是小，则都不会比(1,6)更大；故在这种情况下，可以不计算“|”的情况。
	  1 2 3 4 5 6
    1 x         o
    2 x x       |
    3 x x x     |
    4 x x x x   |
    5 x x x x x |
    6 x x x x x x
	
	同理，当height[1] < height[6]时，(1,5)(1,4),(1,3),(1,2),(1,1)都不用计算。

		1 2 3 4 5 6
	  1 x - - - - o
      2 x x
      3 x x x 
      4 x x x x
      5 x x x x x
      6 x x x x x x
	

    int maxArea(vector<int>& height) {
        if(height.size() < 2)
            return 0;
        int result = 0;
        int i = 0 , j =height.size()-1;
        while(i<j){
            result = max(result,min(height[i],height[j])*(j-i));
            if(height[i] < height[j])
                i++;
            else
                j--;
        }
        return result;
    }
*/