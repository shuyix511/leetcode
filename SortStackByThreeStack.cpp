void sort(stack<int> &s) {
	if (s.empty()) {
		return;
	}
	int pivot = s.top();
	s.pop();

	// partition
	stack<int> left, right;
	while (!s.empty()) {
		int y = s.top();
		s.pop();
		if (y < pivot) {
			left.push(y);
		}
		else {
			right.push(y);
		}
	}
	sort(left);
	sort(right);

	// merge
	stack<int> tmp;
	while (!left.empty()) {
		tmp.push(left.top());
		left.pop();
	}
	tmp.push(pivot);

	while (!right.empty()) {
		tmp.push(right.top());
		right.pop();
	}
	while (!tmp.empty()) {
		s.push(tmp.top());
		tmp.pop();
	}

}