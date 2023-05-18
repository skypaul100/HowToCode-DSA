//HackerRank / codestudio
bool has_cycle(SinglyLinkedListNode* head) {
//empty
if(head==NULL)
  return false;
//STL
map<SinglyLinkedListNode*,bool> visited;
SinglyLinkedListNode*temp=head;
while(temp!=NULL)
{
    if(visited[temp]==true)//cycle is present
    {
        return true;
    }
    //not require else 
    //since we need to check for eact node
    visited[temp]=true;//for each node visiting mark true
    temp=temp->next; //go forward
}
//when cycle is not present
return false;
}
