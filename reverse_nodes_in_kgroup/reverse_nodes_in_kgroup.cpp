//1->2->3->4->5 --- 2 ----2->1->4->3->5
//1->2->3->4->5 --- 3 ----3->2->1->4->5
/**
 * Definition for singly-linked list.*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        ListNode* nodes[k];

        return reverseKGroupInternal(head, k, nodes);
    }
private:
    ListNode* reverseKGroupInternal(ListNode* head, int k, ListNode** nodes)
    {
        if (k < 2 or head == NULL)
        {
            return head;
        }

        memset(nodes, 0, k);
        ListNode* currentNode = head;

        int num = k;
        while(currentNode != NULL && num > 0)
        {
            nodes[--num] = currentNode;
            currentNode = currentNode->next;
        }

        if (num > 0)
        {
            return head;
        }
        else
        {
            ListNode* firstNode = nodes[0];
            for (int i = 0; i < k - 1; ++i)
            {
                nodes[i]->next = nodes[i + 1];
            }

            ListNode* lastNode =  nodes[k - 1];

            lastNode->next = reverseKGroupInternal(currentNode, k, nodes);

            return firstNode;
        }
    }
};
