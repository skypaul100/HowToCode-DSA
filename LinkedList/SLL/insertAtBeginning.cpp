SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* head, int data) {
	SinglyLinkedListNode* temp=new SinglyLinkedListNode(data);
    
    temp->data=data;
    temp->next=head;// insert at head
    
    head=temp;
    
    return head;

}
