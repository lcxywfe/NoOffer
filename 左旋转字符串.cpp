//汇编语言中有一种移位指令叫做循环左移（ROL），
//现在有个简单的任务，就是用字符串模拟这个指令的运算结果。
//对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。
//例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！

class Solution {
private:
    void swap(char& a, char& b) {
        char temp = a;
        a = b;
        b = temp;
    }
public:
    string LeftRotateString(string str, int n) {
        if (str.size() == 0) 
            return str;
        n = n % str.size();
        for (int i = 0; i < str.size()/2; ++i) {
            swap(str[i], str[str.size()-1-i]);
        }
        for (int i = 0; i < (str.size()-n)/2; ++i) {
            swap(str[i], str[str.size()-1-n-i]);
        }
        for (int i = str.size()-n; i < (2*str.size()-n)/2; ++i) {
            swap(str[i], str[2*str.size()-1-n-i]);
        }
        
        return str;
    }
};