//请实现一个函数用来找出字符流中第一个只出现一次的字符。
//例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。
//当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。 
//如果当前字符流没有存在出现一次的字符，返回#字符。

class Solution
{
private:
    vector<int> count;
    vector<char> single;
public:
    Solution() {
        count = vector<int>(256);
        single = vector<char>(0);
    }
  //Insert one char from stringstream
    void Insert(char ch)
    {
         ++count[ch];
        if (count[ch] == 1)
            single.push_back(ch);
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
    	for (int i = 0; i < single.size(); ++i)
            if (count[single[i]] == 1)
                return single[i];
        
        return '#';
    }

};