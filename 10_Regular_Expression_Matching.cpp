class Solution {
public:
	bool isMatch(string s, string p) {
		return helper(s, p, 0, 0);
	}

	bool helper(const string &s, const string &p, int index_s, int index_p) {
		int size_s = s.length(), size_p = p.length();
		if (index_p == size_p) {
			return index_s == size_s;
		}

		if (p[index_p + 1] != '*') {
			if (index_s < size_s && (p[index_p] == s[index_s] || p[index_p] == '.')) {
				return helper(s, p, index_s + 1, index_p + 1);
			}
		}
		else {
			if (helper(s, p, index_s, index_p + 2)) {
				return true;
			}
			while (index_s < size_s && (p[index_p] == s[index_s] || p[index_p] == '.')) {
				if (helper(s, p, ++index_s, index_p + 2)) {
					return true;
				}
			}
			return false;
		}
	}
};