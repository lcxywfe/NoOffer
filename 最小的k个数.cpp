//输入n个整数，找出其中最小的K个数。
//例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。

class Solution {
private:
    int partition(vector<int>& input, int l, int r) {
        if (l >= r)
            return l;
        int i = l;
        int j = r;
        int k = input[i];
        while (i < j) {
            while(i < j && input[j] >= k)
            	--j;
            input[i] = input[j];
            while(i < j && input[i] <= k)
                ++i;
            input[j] = input[i];
        }
        input[i] = k;
        return i;
    }
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> result(0);
        if (input.size() == 0 || k > input.size() || k <= 0)
            return result;
        
        int l = 0, r = input.size() - 1;
        int index = partition(input, l, r);
        while (index != k-1) {
            if (index < k-1) {
                l = index + 1;
                index = partition(input, l, r);
            } else if (index > k-1) {
                r = index - 1;
                index = partition(input, l, r);
            }
        }
        for (int i = 0; i <= index; ++i)
			result.push_back(input[i]);
		return result;
    }
};