class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ans;
		int len = nums.size();
		if (len < 3) {
			return ans;
		}
		sort(nums.begin(), nums.end());
		int i = 0, j = 0, k = len - 1;
		for (i = 0; i < len - 2; i++) {
			if (i > 0 && nums[i] == nums[i - 1]) {
				continue;
			}
			j = i + 1;
			k = len - 1;
			int target = 0 - nums[i];
			while (j < k) {
				int sum = nums[j] + nums[k];
				if (sum == target) {
					ans.push_back({ nums[i], nums[j], nums[k] });
					while (nums[j] == nums[j + 1]) {
						j++;
					}
					while (nums[k] == nums[k - 1]) {
						k--;
					}
					j++;
					k--;
				}
				else if (sum > target) {
					k--;
				}
				else {
					j++;
				}
			}
		}
		return ans;
	}
};