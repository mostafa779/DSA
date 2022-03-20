#include <iostream>
using namespace std;
template <class t>
class doublyLinkedList
{
    struct node
    {
        t item;
        node *next , *pre;
    };
    typedef node* nodeptr;
    nodeptr first,last;
    int count;
public:
    doublyLinkedList():first(NULL) , last(NULL) , count(0) {}
    bool isempty()
    {
        return first = last = NULL;
    }
    void insertfirst(t elm)
    {
        nodeptr newnode = new node;
        newnode ->item = elm;
        if(count==0)
        {
            first = last = newnode;
            newnode ->next = newnode ->pre = NULL;
        }
        else
        {
            newnode ->next = first;
            newnode ->pre =NULL;
            first ->pre = newnode;
            first = newnode;
        }
        count ++;
    }
    void insertlast(t elm)
    {
        nodeptr newnode = new node;
        newnode ->item = elm;
        if(count==0)
        {
            first = last = newnode;
            newnode ->next = newnode ->pre = NULL;
        }
        else
        {
            newnode ->next = NULL;
            newnode ->pre = last;
            last ->next = newnode;
            last = newnode;
        }
        count ++;
    }
    void insertpos(int pos , t elm)
    {
        if(pos<0||pos>count)
            cout<<"Out of range\n";
            else
            {
                nodeptr newnode = new node;
                newnode ->item = elm;
                if (pos==0)
                    insertfirst(elm);
                else if(pos==count)
                    insertlast(elm);
                else
                {
                    nodeptr cur = first;
                    for(int i=1;i<pos; i++)
                    {
                        cur=cur->next;
                    }
                    newnode ->next = cur ->next;
                    newnode ->pre = cur;
                    cur->next->pre=newnode;
                    cur->next=newnode;
                    count++;
                }
            }
    }
    void removefirst()
    {
        if(count==0)
            cout<<"List is empty\n";
        else if(count ==1)
        {
            delete first;
            first = last = NULL;
        }
        else
        {
            nodeptr cur = first;
            first = first ->next;
            first -> pre = NULL;
            delete cur;
        }
        count --;
    }
    void removelast()
    {
        if(count==0)
            cout<<"List is empty\n";
        else if(count ==1)
        {
            delete first;
            first = last = NULL;
        }
        else
        {
            nodeptr cur = last;
            last = last ->pre;
            last -> next = NULL;
            delete cur;
        }
        count --;
    }
    void remove(t elm)
    {
        if(count==0)
            cout<<"List is empty\n";
        if(first->item==elm)
            removefirst();
        else
        {
            nodeptr cur = first ->next;
            while(cur != NULL&&cur->item!=elm)
                cur = cur ->next;
            if(cur==NULL)
                cout<<"Not found\n";
            else if(cur->next ==NULL)
                removelast();
            else
            {
                cur->next->pre=cur->pre;
                cur->pre->next=cur->next;
                delete cur;
            }
            count --;
        }
    }
    void removepos(int pos)
    {
        if(pos<0||pos>count)
            cout<<"Out of range\n";
        else if(pos==0)
            removefirst();
        else if(pos==count)
            removelast();
        else
        {
            nodeptr cur = first ->next;
            for (int i = 1; i < pos; i++)
			{
				cur = cur->next;
			}
			cur->next->pre=cur->pre;
            cur->pre->next=cur->next;
            delete cur;
        }
        count--;
    }
    void display()
    {
        nodeptr cur = first;
        while(cur != NULL)
        {
            cout<<cur->item<<" ";
            cur=cur->next;
        }
        cout<<endl;
    }
    void reversdisplay()
    {
        nodeptr cur = last;
        while(cur != NULL)
        {
            cout<<cur->item<<" ";
            cur=cur->pre;
        }
        cout<<endl;
    }
    void destroy()
    {
        nodeptr temp ;
        while(first != NULL)
        {
            temp = first;
            first = first ->next;
            delete temp;
        }
        last = NULL;
        count = 0;
    }

};

int main()
{
    doublyLinkedList<int> ddl;
    ddl.insertpos(0,0); ddl.insertpos(1,10); ddl.insertpos(2,20); ddl.insertpos(3,30);
    ddl.insertfirst(-1);
    ddl.insertlast(-2);
    ddl.display();
    ddl.reversdisplay();
    cout<<endl;
    ddl.removefirst();
    ddl.removelast();
    ddl.display();
    ddl.removepos(2);
    ddl.display();
    cout<<endl;
    ddl.remove(10);
    ddl.display();
    /*ddl.destroy();
    ddl.display();*/
	return 0;
}
