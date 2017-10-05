/*
Given a singly linked list L: L0?L1?…?Ln-1?Ln,
reorder it to: L0?Ln?L1?Ln-1?L2?Ln-2?…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}. 
*/

/*

	先将链表平分为两个部分，然后再将后面部分转置，然后再合并在一起

    void reorderList(ListNode* head) {
        if (!head) return ;
        ListNode* middle = getMiddleNode(head);
        ListNode* right = middle->next;
        middle->next = NULL;
        right = reverseLinkedList(right);
        head = merge(head, right);
    }
    ListNode* getMiddleNode(ListNode* head) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* slow = &dummy;
        ListNode* fast = &dummy;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* reverseLinkedList(ListNode* head) {
        ListNode* prev = NULL;
        while (head) {
            ListNode* temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }
    ListNode* merge(ListNode* left, ListNode* right) {
            
        ListNode *head = left;
        while (right) {
            ListNode* leftTemp = left->next;
            ListNode* rightTemp = right->next;
            left->next = right;
            right->next = leftTemp;
            left =  leftTemp;
            right = rightTemp;
        }
        return head;
    }
*/