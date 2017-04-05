//输入一个链表，反转链表后，输出链表的所有元素。

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if (pHead == NULL || pHead->next == NULL)
            return pHead;
        
        ListNode* pre = pHead;
        ListNode* cur = pHead->next;
        pHead->next = NULL;
        
        while (cur) {
            ListNode* temp = cur;
            cur = cur->next;
            temp->next = pre;
            pre = temp;
        }
        
        return pre;
        
    }
};