/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */
/* Should return data of intersection point of two linked
   lists head1 and head2.
   If there is no intersecting point, then return -1. */
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    Node *temp;
    temp=head1;
    while(temp!=NULL){
        temp->data=-(temp->data);
        temp=temp->next;
    }
    temp=head2;
    while(temp!=NULL){
        if(temp->data<0){
            return (-(temp->data));
        }
        temp=temp->next;
    }
}
