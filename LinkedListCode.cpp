#include<bits/stdc++.h>
#include<time.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

void insertLL(node **head, int d)
{
    node* newNode=new node;
    newNode->data=d;
    newNode->next=NULL;
    if(*head==NULL){
        *head=newNode;
        return;
    }
    node* curr=*head;
    while(curr->next!=NULL)
        curr=curr->next;
    curr->next=newNode;
}

void printLL(node *head)
{
    node* curr=head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }
}

void deleteMin(node** head)
{
    node* deleted;
    if(*head==NULL){
        cout<<"\nList is empty";
        return;
    }
    else if((*head)->next==NULL){
        deleted=(*head);
        cout<<(*head)->data;
        *head=NULL;
        delete(deleted);
        return;
    }
    node* curr=*head;
    node* min=*head;
    while(curr->next!=NULL){
        if(curr->data<min->data)
            min=curr;
        curr=curr->next;
    }
    node* prev=NULL;
    curr=(*head);
    while(curr->next!=NULL){
        if(curr==min){
            if(!prev){
                cout<<curr->data;
                deleted=(*head);
                (*head)=(*head)->next;
                delete(deleted);
            }
            else{
                cout<<curr->data;
                deleted=curr;
                prev->next=curr->next;
                curr->next=NULL;
                delete(deleted);
            }
            break;
        }
        prev=curr;
        curr=curr->next;
    }
}

int main()
{
    node* head=NULL;
    int n;
    cout<<"Enter the No. of Nodes You want to Enter: ";
    cin>>n;
    srand(time(0));
    insertLL(&head,0);
    for(int i=0;i<n;i++)
        insertLL(&head,rand()%100);
    printLL(head);
    int m;
    cout<<"\nHow Many nodes do you want to delete: ";
    cin>>m;
    for(int i=0;i<m;i++){
        cout<<"\nNow Minimum Deleted Node is: ";
        deleteMin(&head);
    }
    cout<<"\nUpdated List is: ";
    printLL(head);
}
