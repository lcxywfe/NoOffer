//统计一个数字在排序数组中出现的次数。

class Solution {
private:
	int findLeft(const std::vector<int>& data, int l, int r, const int k) {
		if (l >= r) {
			if (data[l] == k)
				return l;
			else
				return -1;
		}
		int mid = (l + r) / 2;
		if (data[mid] == k) {
			if (mid == 0 || data[mid - 1] != k)
				return mid;
			if (l <= mid - 1)
				return findLeft(data, l, mid - 1, k);
			else
				return -1;
		}
		else if (data[mid] < k) {
			if (mid + 1 <= r)
				return findLeft(data, mid + 1, r, k);
			else
				return -1;
		}
		else if (data[mid] > k) {
			if (l <= mid - 1)
				return findLeft(data, l, mid - 1, k);
			else
				return -1;
		}

		return -1;
	}

	int findRight(const std::vector<int>& data, int l, int r, const int k) {
		if (l >= r) {
			if (data[l] == k)
				return l;
			else
				return -1;
		}
		int mid = (l + r) / 2;
		if (data[mid] == k) {
			if (mid == data.size() - 1 || data[mid + 1] != k)
				return mid;
			if (mid + 1 <= r)
				return findRight(data, mid + 1, r, k);
			else
				return -1;
		}
		else if (data[mid] < k) {
			if (mid + 1 <= r)
				return findRight(data, mid + 1, r, k);
			else
				return -1;
		}
		else if (data[mid] > k) {
			if (l <= mid - 1)
				return findRight(data, l, mid - 1, k);
			else
				return -1;
		}
		return -1;
	}

public:
	int GetNumberOfK(std::vector<int> data, int k) {
		if (data.size() == 0)
			return 0;

		int left = findLeft(data, 0, data.size() - 1, k);
		int right = findRight(data, 0, data.size() - 1, k);

		if (left == -1)
			return 0;
		return (right - left + 1);
	}
};