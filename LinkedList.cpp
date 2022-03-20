#include <iostream>
using namespace std;
template <class t>
class linkedlist
{
    struct node
    {
        int item;
        node *next;
    };
    typedef node* nodeptr;
    nodeptr first , last;
    int length;
public:
    linkedlist(): first(NULL) , last(NULL) , length(0) {}
    bool isempty()
    {
        return length == 0;
    }
    void insertfirst(t elm)
    {
        nodeptr newnode = new node;
        newnode ->item = elm;
        if(length==0)
        {
            first = last = newnode;
            newnode ->next = NULL;
        }
        else
        {
            newnode ->next = first;
            first = newnode;
        }
        length++;
    }
    void insertend(t elm)
    {
        nodeptr newnode = new node;
        newnode ->item = elm;
        if(length==0)
        {
            first = last = newnode;
            newnode ->next = NULL;
        }
        else
        {
            last ->next = newnode;
            newnode ->next = NULL;
            last = newnode;
        }
        length++;
    }
    void insertpos(int pos , t elm)
    {
        nodeptr newnode = new node;
        newnode ->item = elm;
        if(pos==0)
            insertfirst(elm);
        else if(pos == length)
            insertend(elm);
        else
        {
            nodeptr cur = first;
            for(int i=1; i<pos; i++)
                cur=cur->next;
            newnode ->next = cur ->next;
            cur ->next = newnode;
        }
        length++;
    }
    void display()
    {
        nodeptr cur = first;
        while(cur != NULL)
        {
            cout<<cur->item<<" ";
            cur = cur ->next;
        }
    }
    void removefirst()
    {
        if(length==0)
            cout<<"List is already empty\n";
        else if(length==1)
        {
            delete first;
            first = last = NULL;
            length--;
        }
        else
        {
            nodeptr cur = first;
            first = first -> next;
            delete cur;
            length --;
        }
    }
    void removelast ()
    {
        if(length==0)
            cout<<"List is already empty\n";
        else if(length==1)
        {
            delete first;
            first = last = NULL;
            length--;
        }
        else
        {
            nodeptr cur = first->next , pre = first;
            while(cur!=last)
            {
                pre = cur;
                cur=cur->next;
            }
            delete cur;
            pre->next=NULL;
            last = pre;
            length--;
        }
    }
    void removepos(t elm)
    {
        if(isempty())
            cout<<"List is empty\n";
        nodeptr cur , pre;
        if(first->item==elm)
        {
            cur = first;
            first = first ->next;
            delete cur;
            length--;
            if(length==0)
                last==NULL;
        }
        else
        {
            cur = first->next;
            pre = first;
            while(cur!=NULL&&cur->item!=elm)
            {
                pre=cur;
                cur=cur->next;
            }
            if(cur==NULL)
                cout<<"Not found\n";
            else
            {
                pre->next= cur->next;
                if(last==cur)
                    last=pre;
                delete cur;
                length--;
            }
        }
    }
    void rev()
    {
        nodeptr pre , cur , next;
        pre = NULL;
        cur = first;
        next = cur ->next;
        while(next != NULL)
        {
            next = cur -> next;
            cur -> next = pre;
            pre = cur;
            cur=next;
        }
        first = pre;
    }
    int search(t elm)
    {
        nodeptr cur = first;
        int pos = 0;
        while(cur != NULL)
        {
            if(cur->item==elm)
            {
                cout<<"Element in position #"<<pos<<endl;
                break;
            }
            cur = cur -> next;
            pos++;
        }
        return -1;
    }

};

int main()
{
    linkedlist<int> lq;
    lq.insertfirst(10);
    lq.insertend(50);
    lq.insertpos(1,20); lq.insertpos(2,30); lq.insertpos(3,40);
    //lq.removefirst();
    //lq.removelast();
    lq.removepos(30);
    lq.rev();
    lq.search(20);
    lq.display();
	return 0;
}
