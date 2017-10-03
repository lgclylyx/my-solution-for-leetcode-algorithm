/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list. 
*/

/*

	两次遍历。第一次建立这条链表，并将其random的指向保留。第二次处理random的指向。

    typedef unordered_map<RandomListNode*,vector<RandomListNode*>> hashmap;
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head)
            return NULL;
        hashmap um;
        RandomListNode res(0);
        RandomListNode * p = head, *q = &res;
        while(p){
            q -> next = new RandomListNode(p->label);
            q = q->next;
            if(p->random)
                um[p->random].push_back(q);
            p = p -> next;
        }
        q = res.next;
        p = head;
        while(q){
            if(um.find(p) != um.end()){
                vector<RandomListNode*> t = um[p];
                for(auto c : t)
                    c->random = q;
            }
            p = p->next;
            q = q->next;
        }
        return res.next;
    }
*/