struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL){}
};

class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
};


/*ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2)
{
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    ListNode* nodeInL1 = l1;
    ListNode* nodeInL2 = l2;

    ListNode* head = NULL;
    ListNode* currentNode = NULL;

    unsigned step = 0;

    while (nodeInL1 != NULL && nodeInL2 != NULL)
    {
        unsigned sum = nodeInL1->val + nodeInL2->val + step;

        if (head == NULL)
        {
            head = new ListNode(sum % 10);
            currentNode = head;
        }
        else
        {
            currentNode->next = new ListNode(sum % 10);
            currentNode = currentNode->next;
        }

        step = sum / 10;

        nodeInL1 = nodeInL1->next;
        nodeInL2 = nodeInL2->next;
    }       

    while(nodeInL1 != NULL)
    {
        unsigned sum = nodeInL1->val + step;

        currentNode->next = new ListNode(sum % 10);

        currentNode = currentNode->next;

        step = sum / 10;
        nodeInL1 = nodeInL1->next;
    }

    while(nodeInL2 != NULL)
    {
        unsigned sum = nodeInL2->val + step;

        currentNode->next = new ListNode(sum % 10);

        currentNode = currentNode->next;

        step = sum / 10;
        nodeInL2 = nodeInL2->next;
    }
    
    if (step != 0)
    {
        currentNode->next = new ListNode(step);
    }

    return head;
}*/

ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2)
{
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    ListNode** nodeInL1 = &l1;
    ListNode** nodeInL2 = &l2;

    unsigned step = 0;

    while (*nodeInL1 != NULL && *nodeInL2 != NULL)
    {
        unsigned sum = (*nodeInL1)->val + (*nodeInL2)->val + step;

        (*nodeInL1)->val = sum % 10;

        step = sum / 10;

        nodeInL1 = &((*nodeInL1)->next);
        nodeInL2 = &((*nodeInL2)->next);
    }
    
    if (*nodeInL2 != NULL)
    {
        *nodeInL1 = *nodeInL2;
        *nodeInL2 = NULL;
    }

    while(*nodeInL1 != NULL)
    {
        unsigned sum = (*nodeInL1)->val + step;

        (*nodeInL1)->val = sum % 10;
        
        step = sum / 10;
        
        if (step == 0)
        {
            break;
        }
        
        nodeInL1 = &((*nodeInL1)->next);
    }
    
    if (step != 0)
    {
        *nodeInL1 = new ListNode(step);
    }

    return l1;
}

int main()
{
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    Solution s;

    ListNode* res = s.addTwoNumbers(l1, l2);

    while(res != NULL)
    {
        std::cout << res->val << "\t" << std::endl;
        /*ListNode* node = res;
        res = res->next;
        delete node;*/
        res = res->next;
    }

    return 0;
}
