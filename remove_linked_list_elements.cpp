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

    ListNode* removeElements(ListNode* head, int val) {

        //find the head

        while(head != NULL && head->val == val)

        {

              head = head->next;

        }

        if (head == NULL)

        {

        	return NULL;

        }

        ListNode* pFirst = head;

        ListNode* pSecond = head->next;

        while (pSecond != NULL)

        {

        	if (pSecond->val == val)

        	{

        		pSecond = pSecond->next;

        		//is last node

        		if (pSecond == NULL)

        		{

        			pFirst->next = NULL;

        		}

        		continue;

        	}

        	pFirst->next = pSecond;

        	pFirst = pSecond;

        	pSecond = pSecond->next;

        }



        return head;

    }

};

