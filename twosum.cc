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
<<<<<<< HEAD
 * soulution:O(n)--±éÀúÒ»±éÊý×é£¬Ã¿´Î²éÕÒÊÇ·ñÓÐÒÑ±éÀú¹ýµÄÔªËØÊ¹Á½ÊýµÄºÍÎª¸ø¶¨Öµ£¬±£Ö¤O(n)µÄÌõ¼þÊÇÒªÄÜ¹»ÔÚ³£ÊýÊ±¼äÄÚ½øÐÐ²éÕÒ£¬ËùÒÔÊ¹ÓÃhash±í
=======
 * soulution:O(n)--éåŽ†ä¸€éæ•°ç»„ï¼Œæ¯æ¬¡æŸ¥æ‰¾æ˜¯å¦æœ‰å·²éåŽ†è¿‡çš„å…ƒç´ ä½¿ä¸¤æ•°çš„å’Œä¸ºç»™å®šå€¼ï¼Œä¿è¯O(n)çš„æ¡ä»¶æ˜¯è¦èƒ½å¤Ÿåœ¨å¸¸æ•°æ—¶é—´å†…è¿›è¡ŒæŸ¥æ‰¾ï¼Œæ‰€ä»¥ä½¿ç”¨hashè¡¨
>>>>>>> branch 'master' of ssh://git@github.com/lgclylyx/my-solution-for-leetcode-algorithm.git
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
