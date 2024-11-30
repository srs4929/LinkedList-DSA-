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

void del()  //delete at first position
{
     node* temp=head;
     head=head->next;
    
     delete(temp);
}

void del_last()
{
     node* temp=head;
     while(temp->next->next!=NULL) 
     {
        temp=temp->next;
     }
     delete temp->next;
     temp->next=NULL;
     tail=temp;
}

void del_pos(int pos)
{
    node* ptr=head;
    node* ptr1;
    int count=1;
    for(int i=0;i<(pos-1)&&ptr!=NULL;i++)
    {   
        ptr1=ptr;
        ptr=ptr->next;
    }
    if(ptr==NULL||ptr->next==NULL)
    cout<<"Invalid"<<endl;

    ptr1->next=ptr->next;
    delete ptr;
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

    display();
    cout<<"After deletion at first point"<<endl;
    del();
    display();

    cout<<"After deletion at last position"<<endl;
    del_last();
    display();
    cout<<"After deletion at a position"<<endl;
    del_pos(2);
    display();


}