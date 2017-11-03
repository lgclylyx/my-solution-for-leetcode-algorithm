/*
A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. Now suppose you are given the locations and height of all the buildings as shown on a cityscape photo (Figure A), write a program to output the skyline formed by these buildings collectively (Figure B).
Buildings Skyline Contour

The geometric information of each building is represented by a triplet of integers [Li, Ri, Hi], where Li and Ri are the x coordinates of the left and right edge of the ith building, respectively, and Hi is its height. It is guaranteed that 0 ≤ Li, Ri ≤ INT_MAX, 0 < Hi ≤ INT_MAX, and Ri - Li > 0. You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.

For instance, the dimensions of all buildings in Figure A are recorded as: [ [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ] .

The output is a list of "key points" (red dots in Figure B) in the format of [ [x1,y1], [x2, y2], [x3, y3], ... ] that uniquely defines a skyline. A key point is the left endpoint of a horizontal line segment. Note that the last key point, where the rightmost building ends, is merely used to mark the termination of the skyline, and always has zero height. Also, the ground in between any two adjacent buildings should be considered part of the skyline contour.

For instance, the skyline in Figure B should be represented as:[ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ].
*/

/*
    天迹线问题，首先想到的解法就是构建一个HEIGHTMAP，用线扫描的方式构建
    高度图，最后扫描高度图，将高度变化处输出。然而这种方法需要的时间空间
    复杂度都很高。可以使用优先队列，对没一个矩形进行处理，活跃的矩形放在
    优先队列中。如果不活跃了就从优先队列中移除。优先队列中以高度排序。是
    否活跃是指当处理到CUR_X时，该矩形是否还在处理区间内。
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> res;
        int cur=0, cur_X, cur_H =-1,  len = buildings.size();
        priority_queue< pair<int, int>> liveBlg; 
        while(cur<len || !liveBlg.empty())
        { 
            cur_X = liveBlg.empty()? buildings[cur][0]:liveBlg.top().second;//cur_X为当前活跃最高矩形的右边界

            if(cur>=len || buildings[cur][0] > cur_X){//如果当前处理矩形的左边大于活跃最高矩形中的右边，则先处理活跃的矩形 
                while(!liveBlg.empty() && ( liveBlg.top().second <= cur_X) ) liveBlg.pop();//将矩形变为不活跃，直达有活跃矩形的右边界大于最高矩形的右边界
            }										   //因为这种情况下，肯定存在一个变化点		
            else{ 
                cur_X = buildings[cur][0];
                while(cur<len && buildings[cur][0]== cur_X){//处理想同起点的矩形  
                    liveBlg.push(make_pair(buildings[cur][2], buildings[cur][1]));
                    cur++;
                }
            }
            cur_H = liveBlg.empty()?0:liveBlg.top().first;//取出当前活跃矩形中的最高者
            if(res.empty() || (res.back().second != cur_H) ) res.push_back(make_pair(cur_X, cur_H));//如果高度发生变化，则返回
        }
        return res;
*/
