//将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0 
//输入一个字符串,包括数字字母符号,可以为空
//如果是合法的数值表达则返回该数字，否则返回0

class Solution {
public:
    int StrToInt(string str) {
        if (str.size() == 0)
            return 0;
        
        long result = 0;
        int flag = 1;
        int i = 0;
        if (str[0] == '-') {
            flag = -1;
            ++i;
        }
        else if (str[0] == '+')
            ++i;
        
        while (i < str.size()) {
            if (str[i] < '0' || str[i] > '9')
                return 0;
            result *=  10;
            result += str[i] - '0';
            ++i;
        }
        
        return flag*result;
        
        
    }
};