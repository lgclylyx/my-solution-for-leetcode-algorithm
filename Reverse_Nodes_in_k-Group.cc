/*
 Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5 
*/

/*

	找出每组需逆置子串德起始位置，然后使用单链表逆置方法进行逆置，O(n)

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(1 == k || NULL == head || NULL == head->next)
            return head;
        ListNode *p = head, *s = p,*t;
        while(true){
            int i = 0;
            for(; i < k && NULL != s; i++){
                s = s->next;
            }
            if(NULL == s && i < k)
                break;
            else{
                if(p == head)
                    head = reverselist(p,s);
                else
                    t->next =reverselist(p,s);
            }
            t = p;//每组之间进行连接
            p = s;
        }
        return head;
    }
	//链表逆置
    ListNode* reverselist(ListNode* p ,ListNode* s){
        ListNode *first = p,*reserve = s;
        while(first != s){
            ListNode *second = first->next;
            first->next = reserve;
            reserve = first;
            first = second;
        }
        return reserve;
    }
*/