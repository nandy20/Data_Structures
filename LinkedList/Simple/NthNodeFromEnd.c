/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
/* Should return data of n'th node from the end of linked list.
*  head: head of the linked list
*  n: nth node from end to find
*/
int getNthFromLast(Node *head, int n)
{
       // Your code here
       Node *temp;
       int length=0;
       temp=head;
       while(temp!=NULL){
           temp=temp->next;
           length=length+1;
       }
       
       temp=head;
        int num=length-n;
        int c=0;
       while(temp!=NULL&&c!=num){
          
           temp=temp->next;
           c++;
       }
       if(temp==NULL){
           return -1;
       }
       else{
           return temp->data;
       }
}
