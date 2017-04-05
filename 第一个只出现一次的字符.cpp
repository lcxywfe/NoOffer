//在一个字符串(1<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置。
//如果字符串为空,返回-1

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if (str.size() == 0)
            return -1;
        vector<int> count(256, 0);
        for (int i = 0; i < str.size(); ++i) {
            ++count[int(str[i])];
        }
        
        for (int i = 0; i < str.size(); ++i) {
            if (count[int(str[i])] == 1)
                return i;
        }
        
        return 0;
    }
};