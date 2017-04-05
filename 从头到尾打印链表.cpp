//输入一个链表，从尾到头打印链表每个节点的值。
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        stack<int> stk;
        while (head) {
            stk.push(head->val);
            head = head->next;
        }
        vector<int> result(0);
        while (stk.size() > 0) {
            result.push_back(stk.top());
            stk.pop();
        }
        return result;
    }
};