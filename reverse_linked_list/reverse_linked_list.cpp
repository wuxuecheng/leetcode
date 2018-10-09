/**

 * Definition for singly-linked list.

 * struct ListNode {

 *     int val;

 *     ListNode *next;

 *     ListNode(int x) : val(x), next(NULL) {}

 * };

 */

#include <cstdlib>

struct ListNode {

    int val;

    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}

};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL)
        {
            return NULL;
        }

        ListNode* currentNode = head;
        ListNode* nextNode = head->next;
        ListNode* nextNextNode = NULL;

        while (nextNode != NULL)
        {
            nextNextNode = nextNode->next;

            nextNode->next = currentNode;

            currentNode = nextNode;

            nextNode = nextNextNode;
        }

        head->next = NULL;

        return currentNode;
    }
};

int main()
{
    return 0;
}
