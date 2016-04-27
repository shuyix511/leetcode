class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> ans;
		int len = nums.size();
		if (len < 4) {
			return ans;
		}
		sort(nums.begin(), nums.end());
		for (int i = 0; i < len - 3; i++) {
			if (i > 0 && nums[i] == nums[i - 1]) {
				continue;
			}
			int j = i + 1;
			int target3 = target - nums[i];
			for (; j < len - 2; j++) {
				int left = j + 1;
				int right = len - 1;
				int target2 = target3 - nums[j];
				while (left < right) {
					int tmp = nums[left] + nums[right];
					if (tmp == target2) {
						ans.push_back({ nums[i], nums[j], nums[left], nums[right] });
						while (nums[left] == nums[left + 1]) {
							left++;
						}
						while (nums[right] == nums[right - 1]) {
							right--;
						}
						left++;
						right--;
					}
					else if (tmp > target2) {
						right--;
					}
					else {
						left++;
					}
				}
				while (j + 1 < len && nums[j] == nums[j + 1]) {
					j++;
				}
			}
		}
		return ans;
	}
};