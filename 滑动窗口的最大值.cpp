//给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
//例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}； 
//针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： {[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。


class Solution {
	struct Atom
	{
		int index;
		int val;
		Atom(int index, int val)
		{
			this->index = index;
			this->val = val;
		}
	};
public:
	vector<int> maxInWindows(const vector<int>& num, unsigned int size)
	{
		vector<int> result(0);
		if (size == 0)
			return result;
		if (num.size() < size)
			return result;

		deque<Atom> d;
		d.clear();
		for (int i = 0; i < num.size(); ++i)
		{
			auto it = d.begin();
			while (d.size() > 0 && (it->val <= num[i] || i - it->index >= size))
			{
				d.pop_front();
				it = d.begin();
			}
			it = d.end();
			while (d.size() > 0 && ((--it)->val <= num[i] || i - it->index >= size))
			{
				d.pop_back();
				it = d.end();
			}

			Atom temp(i, num[i]);
			d.push_back(temp);
			if (i >= size-1)
				result.push_back(d.begin()->val);
		}
		


		return result;
	}
};