/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/
// root: head node
Node *removeDuplicates(Node *head)
{
   // your code goes here
   Node *temp,*temp1,*temp2;
   temp=head;
   //use 3 pointers in which 2 are for iteration through the list
   while(temp->next!=NULL){
       temp1=temp;
       temp2=temp1->next;
       while(temp->data==temp2->data&&temp2->next!=NULL){
               temp1=temp1->next;
               temp2=temp2->next;
       }
       temp->next=temp1->next;
       temp=temp->next;
   }
   //For checking if last two elements are same
   temp=head;
   if(temp->next!=NULL){
   temp1=temp->next;
   while(temp1->next!=NULL){
       temp=temp->next;
       temp1=temp1->next;
   }
   if(temp->data==temp1->data){
       temp->next=NULL;
   }
   }
   return head;
}