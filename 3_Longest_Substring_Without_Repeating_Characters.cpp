class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int max_len = 0, i = 0, j = 0;
		vector<char> dict(256, 0);
		for (; j < s.length(); j++) {
			dict[s[j]]++;
			if (dict[s[j]] > 1) {
				while (dict[s[j]] > 1) {
					dict[s[i++]]--;
				}
			}
			max_len = max(max_len, j - i + 1);
		}
		return max_len;
	}
};