/*
Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3

begin to intersect at node c1.

Notes:

    If the two linked lists have no intersection at all, return null.
    The linked lists must retain their original structure after the function returns.
    You may assume there are no cycles anywhere in the entire linked structure.
    Your code should preferably run in O(n) time and use only O(1) memory.
*/

/*

	这相当于一次赛跑，第一轮的时，将两个串的不相等长度去除，第二轮其会在相等的地方相遇

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        if (p1 == NULL || p2 == NULL) return NULL;
        while (p1 || p2){
            if (p1 == NULL) p1 = headB;
            if (p2 == NULL) p2 = headA;
            if (p1 == p2) return p1;
            p1 = p1->next;
            p2 = p2->next;
        }
        return NULL;
    }
*/