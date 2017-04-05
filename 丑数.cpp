//把只包含素因子2、3和5的数称作丑数（Ugly Number）。
//例如6、8都是丑数，但14不是，因为它包含因子7。
//习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if (index == 1)
            return 1;
        
    	int* nums = new int[index];
        for (int i = 0; i < index; ++i)
            nums[i] = 0;
        
        nums[0] = 1;
        int max2 = 0;
        int max3 = 0;
        int max5 = 0;
        
        for (int i = 1; i < index; ++i) {
            int temp = 0;
            for (int j = max2; j < i; ++j) {
        		if (nums[j]*2 > nums[i-1]) {
                    max2 = j;
                    temp = nums[j]*2;
                    break;
                }                
            }
            for (int j = max3; j < i; ++j) {
        		if (nums[j]*3 > nums[i-1]) {
                    max3 = j;
                    temp = nums[j]*3 < temp ? nums[j]*3 : temp;
                    break;
                }                
            }
            for (int j = max5; j < i; ++j) {
        		if (nums[j]*5 > nums[i-1]) {
                    max5 = j;
                    temp = nums[j]*5 < temp ? nums[j]*5 : temp;
                    break;
                }                
            }
            
            nums[i] = temp;
        }
        
        
        int result = nums[index-1];
        delete [] nums;
        
        return result;
        
        
    }
};