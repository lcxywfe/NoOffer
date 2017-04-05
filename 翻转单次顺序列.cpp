//牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。
//同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。例如，“student. a am I”。
//后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。
//Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？

class Solution {
private:
    void swap(string& str, const int& l, const int& r) {
        if (l >= r)
            return;
        
        for (int i = l; i <= (l+r)/2; ++i) {
            char temp = str[i];
            str[i] = str[l+r-i];
            str[l+r-i] = temp;
        }
    }
public:
    string ReverseSentence(string str) {
        if (str.size() == 0)
            return "";
        
        swap(str, 0, str.size()-1);
        
        int l = 0, r = 0;
        while(r < str.size()) {
            if (r == str.size()-1 || str[r+1] == ' ') {
                swap(str, l, r);
                r += 2;
                l = r;
            }
            else
                ++r;
        }
        
        return str;
    }
};