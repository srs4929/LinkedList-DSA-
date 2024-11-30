#include<bits/stdc++.h>
using namespace std;
struct node
{
   int data;
   node* next;
};

node* head=NULL;
node* tail=NULL;

void in(int x)
{
    node* p=new node;
    p->data=x;
    p->next=NULL;
    if(head==NULL)
    {
        head=p;
        tail=p;
    }
    else
    {
        tail->next=p;
        tail=p;
    }
}

void remove()
{    
    node* ptr=head;
     while (ptr != NULL && ptr->next != NULL) {
        if (ptr->data == ptr->next->data) {
            node* temp = ptr->next;
            ptr->next = ptr->next->next;
            delete temp;  // Free the memory of the duplicate node
        } else {
            ptr = ptr->next;  // Move to the next node only if no deletion
        }
    }
}


void display()
{
    node* ptr=head;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<endl;
        ptr=ptr->next;
    }
}




int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        in(x);
    }
    cout<<"Before remove"<<endl;
    display();
    cout<<"After remove"<<endl;
    remove();
    display();

    


}