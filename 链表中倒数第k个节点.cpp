//输入一个链表，输出该链表中倒数第k个结点。
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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    	if (pListHead == NULL || k == 0)
            return nullptr;
        
        
        ListNode* pRight = pListHead;
        for (int i = 1; i < k; ++i) {
            pRight = pRight->next;
            if (!pRight) {
                return nullptr;
            }
        }
        
        ListNode* pLeft = pListHead;
        while (pRight->next) {
            pLeft = pLeft->next;
            pRight = pRight->next;
        }
        
        return pLeft;

    }
};