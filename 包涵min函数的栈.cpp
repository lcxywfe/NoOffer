//定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。

class Solution {
private:
    stack<int> stk1;
    stack<int> stk2;
    template<class T> 
    T minimun(const T a, const T b) {
        if (a < b)
            return a;
        else
            return b;
    }
public:
    void push(int value) {
        if (stk1.size() == 0) {
            stk1.push(value);
          	stk2.push(value);  
        } else {
            stk1.push(value);
            stk2.push(minimun(min(), value));
        }
    }
    void pop() {
        stk1.pop();
        stk2.pop();
    }
    int top() {
        return stk1.top();
    }
    int min() {
        return stk2.top();
    }
};