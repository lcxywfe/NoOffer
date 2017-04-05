//请实现一个函数，将一个字符串中的空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
class Solution {
public:
	void replaceSpace(char *str,int length) {
        int countSpace = 0;
        int countChar = 0;
        char* i = str;
		while (*i != '\0') {
            ++countChar;
            if (*i == ' ')
                ++countSpace;
            ++i;
        }
        int iOld = countChar;
        int iNew = countChar + 2*countSpace;
        while (iOld >= 0) {
            if (*(str+iOld) != ' ') {
                *(str+iNew) = *(str+iOld);
                --iOld;
                --iNew;
            } else {
                *(str+iNew) = '0';
                *(str+iNew-1) = '2';
                *(str+iNew-2) = '%';
                --iOld;
                iNew -= 3;
            }
        }
	}
};