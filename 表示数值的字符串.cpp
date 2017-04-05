//请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
//例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 
//但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。

class Solution {
public:
    bool isNumeric(char* string)
    {
        bool noPoint = false;
        bool noSign = false;
        bool noE = false;
        bool canEnd = false;
        int i = 0;
        while (string[i] != '\0') {
            if (string[i] == 'E' || string[i] == 'e') {
                if (noE)
                    return false;
                noSign = false;
                noE = true;
                noPoint = true;
                canEnd = false;
            }
            else if (string[i] == '-' || string[i] == '+') {
                if (noSign)
                    return false;
                noSign = true;
                canEnd = false;
            }
            else if (string[i] == '.') {
                if (noPoint)
                    return false;
                noPoint = true;
                canEnd = false;
            }
            else if (string[i] >= '0' && string[i] <='9') {
				canEnd = true;
                noSign = true;
            }
            else {
                return false;
            }
            
            ++i;
        }
        if (canEnd)
        	return true;
       	return false;
    }

};