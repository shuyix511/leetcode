class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0) {
			return "";
		}
		string prefix = strs[0];
		for (int i = 1; i < strs.size(); i++) {
			if (strs[i].length() == 0 || prefix.length() == 0) {
				return "";
			}
			int len = prefix.length() > strs[i].length() ? strs[i].length() : prefix.length();
			int j = 0;
			for (j = 0; j < len; j++) {
				if (prefix[j] != strs[i][j]) {
					break;
				}
			}
			prefix = prefix.substr(0, j);
		}
		return prefix;
	}
};