#include <iostream>
using namespace std;
void BubbleSort(int arr[] , int n)
{
    bool flag = true ; int c=0;
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j] , arr[j+1]);
                flag=false;
            }
            c++;
        }
    }
    cout<<"#"<<c<<" rounds"<<endl;
}
void display(int arr[] , int size)
{
    for(int i = 0; i<size; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}


int main()
{
    int arr[] = { 0, -60 , 50, 30, 10,20 };
	int size = sizeof(arr) / sizeof(arr[0]);//6*4=24  /  4
	BubbleSort(arr,size);
	display(arr,size);
	return 0;
}
