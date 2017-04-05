//一个链表中包含环，请找出该链表的环的入口结点。

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(!pHead) 
            return NULL;

		ListNode* pFast = pHead;
        ListNode* pSlow = pHead;
        if (!(pFast) || !(pFast->next) || !(pFast->next->next) || !(pSlow) || !(pSlow->next))
                return NULL;
        pFast = pFast->next->next;
        pSlow = pSlow->next;
        while (pFast != pSlow) {
            if (!(pFast) || !(pFast->next) || !(pFast->next->next) || !(pSlow) || !(pSlow->next))
                return NULL;
            
            pFast = pFast->next->next;
            pSlow = pSlow->next;
        }
        
        ListNode* p1 = pFast;
        ListNode* p2 = pHead;
        while (p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
        }
        
        return p1;
        
    }
};