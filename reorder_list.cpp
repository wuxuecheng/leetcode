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
