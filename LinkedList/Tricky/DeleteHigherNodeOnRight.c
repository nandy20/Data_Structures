{
#include<bits/stdc++.h>
using namespace std;
struct Node
{
int data;
Node* next;
};
Node *newNode(int data)
{
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
void print(Node *root)
{
Node *temp = root;
while(temp!=NULL)
{
cout<<temp->data<<" ";
temp=temp->next;
}
}
Node *compute(Node *head);
int main()
{
    int T;
	cin>>T;
	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;
		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=newNode(data);
			else
			{
				temp->next = newNode(data);
				temp=temp->next;
			}
		}
        Node *result = compute(head);
        print(result);
        cout<<endl;
    }
}

}
/*This is a function problem.You only need to complete the function given below*/
/*
The structure of linked list is the following
struct Node
{
int data;
Node* next;
};
*/
Node *compute(Node *head)
{
    // your code goes here
    Node *temp,*temp1,*tempc;
    temp=head;
    int l=temp->data;
    while(temp!=NULL){
        if(temp->data>l){
            l=temp->data;
        }
        temp=temp->next;
    }
  
    for(temp=head;temp!=NULL;temp=temp->next){
        if(temp->data==l){
            head=temp;
            break;
        }
    }
    //Frst highest num il b the head node
    temp=head;
    tempc=temp->next;
    while(temp->next!=NULL){
        temp1=tempc->next;
        int c=0;
        while(temp1!=NULL){
            if(tempc->data<temp1->data){
                temp->next=temp->next->next;
                c=1;
                break;
            }
            temp1=temp1->next;
        }
        if(c==1){
            //if node is deleted only change tempc beoz tht is lost
            tempc=temp->next;
        }
        else{
            temp=temp->next;
            tempc=temp->next;
        }
    }
    return head;
}