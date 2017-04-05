//在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
//输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007 
//题目保证输入的数组中没有的相同的数字
//数据范围：
//	对于%50的数据,size<=10^4
//	对于%75的数据,size<=10^5
//	对于%100的数据,size<=2*10^5

class Solution {
private:
    int merge(vector<int>& data, int l ,int r) {
        if (l >= r)
            return 0;
        
        int result = 0;
        int mid = (l + r) / 2;
        result = (result + merge(data, l, mid)) % 1000000007;
        result = (result + merge(data, mid+1, r)) % 1000000007;
        
        vector<int> temp(0);
        int i = l, j = mid+1;
        while (i <= mid || j <= r) {
            if (i <= mid && j <= r) {
                if (data[i] <= data[j]) {
                    temp.push_back(data[i]);
                    ++i;
                } else if (data[i] > data[j]) {
                    temp.push_back(data[j]);
                    result = (result + mid-i+1) % 1000000007;
                    ++j;
                }
            } else if (i <= mid) {
                temp.push_back(data[i]);
                ++i;
            } else if (j <= r) {
                temp.push_back(data[j]);
                ++j;
            }
        }
        
        for (int i = l; i <= r; ++i){
            data[i] = temp[i-l];
        }
        
        return result;
        
    }
public:
    int InversePairs(vector<int> data) {
        return merge(data, 0, data.size()-1);
    }
};