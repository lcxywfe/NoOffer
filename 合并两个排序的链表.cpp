//输入两个单调递增的链表，输出两个链表合成后的链表，
//当然我们需要合成后的链表满足单调不减规则。

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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if (pHead1 == NULL)
            return pHead2;
        if (pHead2 == NULL)
            return pHead1;
        
        ListNode* head = NULL;
        ListNode* cur = NULL;
        while (pHead1 || pHead2) {
            if (pHead1 == NULL || (pHead2 && pHead2->val < pHead1->val)) {
                ListNode* temp = new ListNode(pHead2->val);
                if (head == NULL) {
                    head = temp;
                    cur = temp;
                } else {
                    cur->next = temp;
                	cur = temp;
                }
                pHead2 = pHead2->next;
            } else {
                ListNode* temp = new ListNode(pHead1->val);
                if (head == NULL) {
                    head = temp;
                    cur = temp;
                } else {
                    cur->next = temp;
                	cur = temp;
                }
                pHead1 = pHead1->next;
            }
        }
        
        return head;
    }
};