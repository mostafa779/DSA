#include <iostream>
using namespace std;
#define size 5
class Q
{
    int items[size] , front , rear, count;
public:
    Q()
    {
        front = 0; rear = size-1; count = 0;
    }
    bool isfull()
    {
        if(count == size)
            return true;
        else
            return false;
    }
    bool isempty()
    {
        if(count == 0)
            return true;
        else
            return false;
    }
    void add(int elm)
    {
        if(isfull())
            cout<<"Queue is full\n";
        else
        {
            rear = (rear+1) % size;
            items[rear] = elm;
            ++count;
        }
    }
    void del()
    {
        if(isempty())
            cout<<"Queue is empty\n";
        else
        {
            front = (front+1) % size;
            --count;
        }
    }
    void display()
    {
        if(!isempty())
        {
            for(size_t i = front ; i != rear ; i = (i+1) % size )
            {
            cout<<items[i]<<" ";
            }
            cout<<items[rear];
        }
        else
            cout<<"Queue is empty\n";
    }
};


int main()
{
    Q q;
    q.add(3);q.add(5);q.add(7);q.add(9);q.add(11);
    q.del();q.del();q.add(13);q.add(15);
    q.display();
    cout<<endl;
	return 0;
}
