/*
 *question:
 *Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 *You may assume that each input would have exactly one solution, and you may not use the same element twice.
 *Example:
 *Given nums = [2, 7, 11, 15], target = 9,
 *Because nums[0] + nums[1] = 2 + 7 = 9,
 *return [0, 1].
*/

/*

 * soulution:O(n)--遍历一遍数组，每次查找是否有已遍历过的元素使两数的和为给定值，保证O(n)的条件是要能够在常数时间内进行查找，所以使用hash表

class Solution {
public:
vector<int> twoSum(vector<int> &numbers, int target)
{

	unordered_map<int, int> hash;
	vector<int> result;
	for (int i = 0; i < numbers.size(); i++) {
		int numberToFind = target - numbers[i];

		if (hash.find(numberToFind) != hash.end()) {
			result.push_back(hash[numberToFind]);
			result.push_back(i);
			return result;
		}

		hash[numbers[i]] = i;
	}
	return result;
}
};
*/
