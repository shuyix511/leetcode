class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> sol;
		if (nums.size() < 2) {
			return sol;
		}
		map<int, int> map;
		for (int i = 0; i < nums.size(); i++) {
			if (map.find(target - nums[i]) != map.end()) {
				sol.push_back(map[target - nums[i]]);
				sol.push_back(i);
				break;
			}
			else {
				map[nums[i]] = i;
			}
		}
		return sol;
	}
};