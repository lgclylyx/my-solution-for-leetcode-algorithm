/*
 * question:
 * You are given two non-empty linked lists representing two non-negative integers.
 * The digits are stored in reverse order and each of their nodes contain a single digit.
 * Add the two numbers and return it as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 */


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#define NULL 0

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	ListNode* t1 = l1;
    	ListNode* t2 = l2;
    	ListNode* result = NULL;
    	ListNode* t3;
    	int p = 0;
    	while(t1 != NULL && t2 != NULL){
    		int temp = t1->val + t2->val + p;
    		if(temp >= 10){
    			if(result == NULL){
    				result = t3 = new ListNode(temp - 10);
    				p = 1;
    			}else{
    				t3->next = new ListNode(temp - 10);
    				t3 = t3->next;
    				p = 1;
    			}
    		}else{
    			if(result == NULL){
    				result = t3 = new ListNode(temp);
    				p = 0;
    			}else{
    				t3->next = new ListNode(temp);
    				t3 = t3->next;
    				p = 0;
    			}
    		}
    		t1 = t1->next;
    		t2 = t2->next;
    	}
    	ListNode* app = (t1==NULL)?t2:t1;
    	while(app != NULL){
    		int temp = app->val + p;
    		if(temp >= 10){
    			t3->next = new ListNode(temp - 10);
    			t3 = t3->next;
    			p = 1;
    		}else{
    			t3->next = new ListNode(temp);
    			t3 = t3->next;
    			p = 0;
    		}
    		app = app->next;
    	}
    	if(p == 1)
    		t3->next = new ListNode(1);
    	return result;
    }
};
