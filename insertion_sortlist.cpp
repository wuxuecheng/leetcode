/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        
        if (head == NULL)
        {
            return NULL;
        }
        
        ListNode* headNode = head;
        ListNode* currentNode = head;
        ListNode* nextNode = head->next;
        
        while (currentNode != NULL && nextNode != NULL)
        {
            if (nextNode->val < currentNode->val)
            {
                ListNode* tmpNode = nextNode;
                currentNode->next = nextNode->next;
                
                if (tmpNode->val < headNode->val)
                {
                    tmpNode->next = headNode;
                    headNode = tmpNode;
                    
                    nextNode = currentNode->next;
                    
                    continue;
                }
                
                ListNode* sublistCurrentNode = headNode;
                
                while(sublistCurrentNode->next != NULL)
                {
                    if (tmpNode->val < sublistCurrentNode->next->val)
                    {
                        tmpNode->next = sublistCurrentNode->next;
                        sublistCurrentNode->next = tmpNode;
                        
                        nextNode = currentNode->next;
                        
                        break;
                    }
                    
                    sublistCurrentNode = sublistCurrentNode->next;
                }

            }
            else
            {
                currentNode = nextNode;
                nextNode = nextNode->next;
            }
        }
        
        return headNode;
    }
};
