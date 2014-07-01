//version I: used extra memory, easily understood
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void reorderList(ListNode *head) {
        
    if (head == NULL)
    {
        return;
    }
    
    ListNode* currentNode = head;
    
    vector<ListNode*> nodes;
    
    while(currentNode != NULL)
    {
        nodes.push_back(currentNode);
        currentNode = currentNode->next;
    }

    int i(-1);
    int size(nodes.size());
    int j = size;
    int listHalf = size/2;
    
    while(--j > listHalf  && ++i < listHalf)
    {
        nodes[j]->next = nodes[i]->next;
        nodes[i]->next = nodes[j];
    }
    
    nodes[j]->next = NULL;
    
    }
};

// another version
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
    ListNode *reverseList(ListNode *head) {
        ListNode *pre = NULL, *cur = head, *next = NULL;
        while(cur) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
    void reorderList(ListNode *head) {
        int cnt = 0;
        ListNode *p1 = head, *p2 = head;
        while(p2) {
            p1 = p1->next;
            p2 = p2->next;
            if(p2)
                p2 = p2->next;
        }
        p2 = reverseList(p1);
        p1 = head;
        while(p2) {
            ListNode *tmp = p1->next;
            p1->next = p2;
            p2 = p2->next;
            p1->next->next = tmp;
            p1 = tmp;
        }
        if(p1 != NULL && p1->next != NULL)
            p1->next = NULL;
    }
};

