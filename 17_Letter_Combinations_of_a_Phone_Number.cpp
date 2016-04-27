class Solution {
private:
	string match[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
public:
	vector<string> letterCombinations(string digits) {
		vector<string> sol;
		if (digits.length() == 0) {
			return sol;
		}
		vector<char> tmp;
		helper(sol, tmp, digits, 0);
		return sol;
	}

	void helper(vector<string> &sol, vector<char> &tmp, string digits, int level) {
		if (level == digits.length()) {
			string s = "";
			for (int i = 0; i < tmp.size(); i++) {
				s += tmp[i];
			}
			sol.push_back(s);
			return;
		}

		for (int j = 0; j < match[digits[level] - '0'].length(); j++) {
			tmp.push_back(match[digits[level] - '0'][j]);
			helper(sol, tmp, digits, level + 1);
			tmp.pop_back();
		}
	}
};