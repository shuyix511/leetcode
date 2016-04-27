class Solution {
public:
	int myAtoi(string str) {
		int i = 0;
		while (str[i] == ' ') {
			i++;
		}
		int sign = 1;
		if (str[i] == '+' || str[i] == '-') {
			sign = str[i++] == '-' ? -1 : 1;
		}
		long sum = 0;
		while (str[i] <= '9' && str[i] >= '0') { //INT_MAX = 2147483647  INT_MIN = -2147483648
			sum = sum * 10 + (str[i++] - '0');
			if (sign*sum >= INT_MAX) {
				return INT_MAX;
			}
			else if (sign*sum <= INT_MIN) {
				return INT_MIN;
			}
		}
		return sign * sum;
	}
};