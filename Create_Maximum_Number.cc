/*
Given two arrays of length m and n with digits 0-9 representing two numbers. 
Create the maximum number of length k <= m + n from digits of the two.
The relative order of the digits from the same array must be preserved. 
Return an array of the k digits. You should try to optimize your time and space complexity.

Example 1:

nums1 = [3, 4, 6, 5]
nums2 = [9, 1, 2, 5, 8, 3]
k = 5
return [9, 8, 6, 5, 3]

Example 2:

nums1 = [6, 7]
nums2 = [6, 0, 4]
k = 5
return [6, 7, 6, 0, 4]

Example 3:

nums1 = [3, 9]
nums2 = [8, 9]
k = 3
return [9, 8, 9] 
*/

/*

	最直接的解法就是使用递归，对每一种情况进行尝试，这样时间复杂度O((m+n)^k)，太高。
	所以后来的想法就是，将原问题分解为两个子问题，在nums1中找到i个值并且在nums2中找到
	k-i个值。

	vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
		vector<int> ans(k, 0);
		for (int i = max(0, k - (int)nums2.size()); i <= min(k, (int)nums1.size()); i++) {
			vector<int> res1 = get_max_sub_array(nums1, i);
			vector<int> res2 = get_max_sub_array(nums2, k - i);
			vector<int> res(k, 0);
			int pos1 = 0, pos2 = 0, tpos = 0;
			while (pos1 < res1.size() || pos2 < res2.size()) {
				res[tpos++] = greater(res1, pos1, res2, pos2) ? res1[pos1++] : res2[pos2++];
			}
			if (!greater(ans, 0, res, 0))
				ans = res;
		}
		return ans;
	}

	bool greater(const vector<int> & a, int start1, const vector<int> &b, int start2) {
		for (; start1 < a.size() && start2 < b.size(); start1++, start2++) {
			if (a[start1] > b[start2]) return true;
			if (a[start1] < b[start2]) return false;
		}
		return start1 != a.size();
	}

	//从nums中生成一个长度为k的最大子数组
	vector<int> get_max_sub_array(const vector<int> &nums, const int& k) {
		vector<int> res(k,0);
		int len = 0 , n = nums.size();
		for (int i = 0; i < n; i++) {
			//len+n-i>k代表返回数组现在的长度加上现在处理的位置i到数组末尾的长度要大于指定的长度，即一定要能生成定长的数组
			while (len && len + n - i > k && nums[i] > res[len - 1])
				len--;
			if (len < k)
				res[len++] = nums[i];
		}
		return res;
	}
*/
