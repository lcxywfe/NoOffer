//在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 
//例如，链表1->2->3->3->4->4->5 处理后为 1->2->5

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
    ListNode* deleteDuplication(ListNode* pHead)
    {
		ListNode* result = nullptr;
        ListNode* pre = nullptr;
        ListNode* p = pHead;
        while(p) {
            if (p->next && p->val == p->next->val) {
                int temp = p->val;
                while (p && p->val == temp)
                    p = p->next;
                
                if (!p && pre)
                    pre->next = NULL;
                    
            }
            else {
                if (!result)
                    result = p;
                
                if (!pre)
                    pre = p;
                else {
                    pre->next = p;
                    pre = p;
                }
                    
                
                p = p->next;
            }
        }
        
        return result;
    }
};