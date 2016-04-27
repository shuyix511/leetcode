class Solution {
public:
	bool isValid(string s) {
		stack<char> s1;
		int len = s.size();
		char ch;
		for (int i = 0; i < len; i++) {
			if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
				s1.push(s[i]);
			}
			else if (s1.size() > 0 && ((s[i] == ')' && s1.top() == '(') || (s[i] == ']' && s1.top() == '[') || (s[i] == '}' && s1.top() == '{'))) {
				s1.pop();
			}
			else {
				return false;
			}
		}
		return s1.size() == 0;
	}
};