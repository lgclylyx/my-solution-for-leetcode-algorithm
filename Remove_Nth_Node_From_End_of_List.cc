/*

Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:
Given n will always be valid.
Try to do this in one pass. 

*/

/*
	space:O(n) time:O(n)

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> temp;
        for(ListNode* p = head; p != NULL; p=p->next)
            temp.push_back(p);
        int rank = temp.size()-n-1;
        if(rank < 0){
            head = head->next;
        }else{
            ListNode* p = temp[temp.size()-n-1];
            p->next = p->next->next;
        }
        return head;
    }
*/

/*

	space: O(1) time:O(n)


    ListNode* removeNthFromEnd(ListNode* head, int n) {
    	if (!head)
        	return nullptr;

    	ListNode new_head(-1);
    	new_head.next = head;

    	ListNode *slow = &new_head, *fast = &new_head;

    	for (int i = 0; i < n; i++)
        	fast = fast->next;

    	while (fast->next) {
        	fast = fast->next;
        	slow = slow->next;
    	}

    	slow->next = slow->next->next;

    	return new_head.next;
    }

*/