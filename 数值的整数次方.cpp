//给定一个double类型的浮点数base和int类型的整数exponent。
//求base的exponent次方。
class Solution {
public:
    double Power(double base, int exponent) {
        if (base == 0)
            return 0;
        if (exponent == 0)
            return 1;
        
        int flag = 0;
        if (exponent < 0) {
        	flag = -1;   
            exponent = -exponent;
        }
        else
            flag = 1;
        
        double result = 1;
        int temp = base;
        if (exponent % 2 == 1) {
            result *= temp;
        }
        exponent >>= 1;
        while (exponent > 0) {
            temp = temp * temp;
            if (exponent % 2 == 1) {
                result *= temp;
            }
            exponent >>= 1;
        }
        
        if (flag == 1)
            return result;
        else
            return 1 / result;
    }
};