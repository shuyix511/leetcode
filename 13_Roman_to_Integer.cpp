class Solution {
public:
	int romanToInt(string s) {
		int len = s.length();
		int sol = transform(s[0]);
		for (int i = 1; i < len; i++) {
			if (transform(s[i - 1]) < transform(s[i])) {
				sol += transform(s[i]) - 2 * transform(s[i - 1]);
			}
			else {
				sol += transform(s[i]);
			}
		}
		return sol;
	}

	int transform(char ch) {
		switch (ch) {
		case 'I': return 1;
		case 'V': return 5;
		case 'X': return 10;
		case 'L': return 50;
		case 'C': return 100;
		case 'D': return 500;
		case 'M': return 1000;
		}
	}
};