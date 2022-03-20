#include <iostream>
using namespace std;
#define max 10
template <class m>
class stack
{
    int top; m item[max];
public:
    stack(): top(-1) {}
    void push(int element)
    {
        if(top>=max-1)
            cout<<"Stack is full"<<endl;
        else
        {
            top++;
            item[top] = element;
        }
    }
    void pop(m &element)
   {
        if(top==-1)
            cout<<"Stack is empty"<<endl;
        else
           element = item[top];
           top--;
    }
    void getTop(m &topelement)
   {
        if(top==-1)
            cout<<"Stack is empty"<<endl;
        else
           topelement = item[top];
           cout<<"top element is: "<<topelement<<endl;
    }
    void display()
    {
        cout<<"[";
        for(int i = top; i>=0; i--)
        {
            cout<<item[i]<<" ";
        }
        cout<<"]"<<endl;
    }
};

int main()
{
    stack <int> s;int y;
    cout<<"Before deletion: "<<endl;
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.display();
    s.getTop(y);
    s.pop(y);
    cout<<"After deletion: "<<endl;
    s.display();
    s.getTop(y);

	return 0;
}
