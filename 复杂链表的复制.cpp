//输入一个复杂链表
//（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），
//返回结果为复制后复杂链表的head。
//（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）


/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if (!pHead)
            return NULL;
        
        RandomListNode* p = pHead;
        while (p) {
            RandomListNode* temp = new RandomListNode(p->label);
            temp->next = p->next;
            p->next = temp;
            p = temp->next;
        }
        p = pHead;
        while (p) {
            if (p->random)
            	p->next->random = p->random->next;
            p = p->next->next;
        }
        
        
        p = pHead->next;
        RandomListNode* result = p;
        pHead->next = NULL;
        while (p->next) {
            p->next = p->next->next;
            p = p->next;
        }
        
        return result;
    }
};