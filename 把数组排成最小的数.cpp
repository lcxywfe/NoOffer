//输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
//例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。

class Solution {
private:
    static bool compare(const int& a, const int& b) {
        string astr = to_string(a);
        string bstr = to_string(b);
        
        return (astr+bstr < bstr+astr);
    }
public:
    string PrintMinNumber(vector<int> numbers) {
        if (numbers.size() == 0)
            return "";
        
        sort(numbers.begin(), numbers.end(), compare);
        
        string result = "";
        for (int i = 0; i < numbers.size(); ++i) {
            result += to_string(numbers[i]);
        }
        
        return result;
        
    }
};