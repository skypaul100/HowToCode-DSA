void reversePrint(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* temp=head;
   
    if(temp==NULL) //base case
      return;
    
    reversePrint(temp->next); //rec case
    
    cout<<temp->data<<endl;
    

}
