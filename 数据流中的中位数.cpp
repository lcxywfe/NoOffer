//如何得到一个数据流中的中位数？
//如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
//如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。

class Solution {
public:
	multiset<int> left;
	multiset<int> right;
public:
	void Insert(int num)
	{
		if (left.size() == 0) {
			left.insert(num);
			return;
		}
		if (left.size() == right.size()) {
			auto it = left.end();
			--it;
			if (num <= *right.begin()) {
				left.insert(num);
			}
			else {
				int temp = *right.begin();
				right.erase(right.begin());
				right.insert(num);
				left.insert(temp);
			}
		}
		else if (left.size() > right.size()) {
			auto it = left.end();
			--it;
			if ((right.size() == 0 && num >= *it) || (right.size() >0 && num >= *it)) {
				right.insert(num);
			}
			else {
				
				int temp = *it;
				left.erase(it);
				left.insert(num);
				right.insert(temp);
			}
		}
	}

	double GetMedian()
	{
		if (left.size() == 0)
			return -1;
		auto it = left.end();
		--it;
		if (left.size() > right.size())
			return *it;
		else
			return double(double(*it + *right.begin()) / 2);
	}

};