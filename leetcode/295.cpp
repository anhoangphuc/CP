#include <queue>

using namespace std;


class MedianFinder {
	private:
	priority_queue<int> leftPq;
	priority_queue<int, vector<int>, greater<int>>  rightPq;
	public:
	MedianFinder() {
		leftPq = {};
		rightPq = {};
	}
	void addNum(int num) {
		if (leftPq.size() == rightPq.size()) {
			if (rightPq.empty() || num <= rightPq.top()) {
				leftPq.push(num);
			} else {
				leftPq.push(rightPq.top());
				rightPq.pop();
				rightPq.push(num);
			}
		} else {
			if (num >= leftPq.top()) {
				rightPq.push(num);
			} else {
				rightPq.push(leftPq.top());
				leftPq.pop();
				leftPq.push(num);
			}
		}
	}
	double findMedian() {
		if (leftPq.size() == rightPq.size()) {
			return (leftPq.top() + rightPq.top()) * 1.0 / 2;
		} else {
			return leftPq.top();
		}
	}
};

int main() {
	return 0;
}
