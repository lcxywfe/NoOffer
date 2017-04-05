//输入两个链表，找出它们的第一个公共结点。

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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if (!pHead1 || !pHead2)
            return NULL;
        ListNode* a = pHead1;
        ListNode* b = pHead2;
        int lenA = 0, lenB = 0;
        while (a) {
            ++lenA;
            a = a->next;
        }
        while (b) {
            ++lenB;
            b = b->next;
        }
        a = pHead1;
        b = pHead2;
        for (int i = 0; i < lenA-lenB; ++i) {
            a = a->next;
        }
		for (int i = 0; i < lenB-lenA; ++i) {
            b = b->next;
        }
        while (a != b) {
            a = a->next;
            b = b->next;
        }
        
        return a;
    }
};