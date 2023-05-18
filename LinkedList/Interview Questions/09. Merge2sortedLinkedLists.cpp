#include <bits/stdc++.h>
// Complete the mergeLists function below.

/* HckerRank problem / codestudio / leetcode
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* solve(SinglyLinkedListNode* h1, SinglyLinkedListNode* h2)
{
    //base case only 1 elt in 1st List
    if(h1->next==NULL)
    {
        h1->next=h2;
        return h1;
    }
    
    SinglyLinkedListNode* curr1=h1;
    SinglyLinkedListNode* next1=curr1->next;
    SinglyLinkedListNode* curr2=h2;
    SinglyLinkedListNode* next2=curr2->next;
    
    while(next1!=NULL && curr2!=NULL){
        if((curr2->data>=curr1->data) && (curr2->data<=next1->data))
        {
            //add node betn 2 nodes in 1st list
            curr1->next=curr2;
            next2=curr2->next;
            curr2->next=next1;
            //update pointers
            curr1=curr2;
            curr2=next2;
        }
        else{//move forward next1 nad curr1
         curr1=next1;
         next1=next1->next;
         
         if(next1==NULL)
         {
             curr1->next=curr2;
             return h1;
         }
            
        }
    }
    return h1;    
}
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    
    //two lists already sorted
  if(head1==NULL)
    return head2;
  if(head2==NULL)
    return head1;
    
  if(head1->data <= head2->data)
  {
      return solve(head1,head2);
  }
  else 
    return solve(head2,head1);
}

