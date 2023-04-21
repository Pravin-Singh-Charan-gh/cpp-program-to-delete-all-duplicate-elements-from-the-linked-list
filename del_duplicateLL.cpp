#include <iostream>
using namespace std;

class linklist
{
private:
    struct node {
        int data;
        node *next;
    }*head;

public:
    linklist()
    {
        head=NULL;
    }

    void append(int num)
    {
        node *t=head,*temp;
        if(head==NULL) {
            t=new node;
            t->data=num;
            t->next=NULL;
            head=t;
        }

        else {
            while(t->next!=NULL)
                t=t->next;

            temp=new node;
            temp->data=num;
            temp->next=NULL;
            t->next=temp;
        }
    }

    void del_duplicate()
    {
        for(node *i=head; i!=NULL; i=i->next)
            for(  node *j=i -> next , *prev=i  ;  j!=NULL  ;  j=j->next ,  prev=prev->next  )
                if(i->data == j->data) {
                    node *temp=j->next;
                    delete j;
                    prev->next=temp;
                }
    }

    void display()
    {
        node *t=head;
        while(t!=NULL) {
            cout<<t->data<<" ";
            t=t->next;
        }
        cout<<endl;
    }

    ~linklist()
    {
        node *t;
        while(head!=NULL) {
            t=head->next;
            delete head;
            head=t;
        }
    }
};

int main()
{
    linklist A;
    A.append(7);
    A.append(-5);
    A.append(3);
    A.append(-1);
    A.append(20);
    A.append(1);
    A.append(1);
    A.append(0);
    A.append(56);
    A.append(-91);
    A.append(10);
    A.append(15);
    A.append(20);
    A.append(301);
    A.append(61565);
    A.append(-561);

    cout<<"Before deleting:\n";
    A.display();

    A.del_duplicate();
    cout<<"after deleting:\n";
    A.display();

    return 0;
}
