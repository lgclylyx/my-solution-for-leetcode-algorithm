/*

Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

*/

/*

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL || l2 == NULL)
            return l1==NULL? l2 : l1;
        ListNode *p = NULL , *s;
        while(l1 != NULL && l2 != NULL){
            if(l1->val < l2 ->val){
                if(p == NULL){
                    p = l1;
                    s = p;
                }else{
                    s->next = l1;
                    s = s->next;
                }
                l1 = l1->next;
            }else{
                if(p == NULL){
                    p = l2;
                    s = p;
                }else{
                    s->next = l2;
                    s = s->next;
                }
                l2 = l2->next;
            }
        }
        if(l1 != NULL)
            s->next = l1;
        if(l2 != NULL)
            s->next = l2;
        return p;
    }

*/