class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int len = nums.size();
		if (len < 3) {
			return -1;
		}
		int i = 0, j = 0, k = len - 1;
		int closest = INT_MAX / 2;  //otherwise it will overflow for opearation (closest - target), target may be negative number
		sort(nums.begin(), nums.end());
		while (i < len - 2) {
			j = i + 1;
			k = len - 1;
			while (j < k) {
				int sum = nums[i] + nums[j] + nums[k];
				if (sum == target) {
					return target;
				}
				else if (sum > target) {
					k--;
				}
				else {
					j++;
				}
				closest = abs(sum - target) > abs(closest - target) ? closest : sum;
			}
			i++;
		}
		return closest;
	}
};