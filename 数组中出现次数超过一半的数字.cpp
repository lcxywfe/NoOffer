//数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
//例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
//由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
    	if (numbers.size() == 0)
            return 0;
        int result = numbers[0], count = 1;
        for (int i = 1; i < numbers.size(); ++i) {
            if (count == 0) {
                result = numbers[i];
                count = 1;
            } else {
                if (numbers[i] == result)
                    ++count;
                else
                    --count;
            }
        }
       	count = 0;
        for (int i = 0; i < numbers.size(); ++i) {
            if (numbers[i] == result)
                ++count;
        }
        
        if (2*count > numbers.size())
            return result;
        else
            return 0;
       
    }
};