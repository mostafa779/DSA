#include <iostream>
using namespace std;
void SelectionSort(int arr[] , int size)
{
    int min ;
    for(int i = 0; i<size-1; i++)
    {
        min=i;
        for(int j=i+1;j<size;j++)
        {
            if(arr[j]<arr[min])
                min = j;
        }
        swap(arr[min] , arr[i]);
    }
}
void display(int arr[] , int size)
{
    for(int i = 0; i<size; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}


int main()
{
    int arr[] = { -60, 0, 50, 30, 10,20 };
	int size = sizeof(arr) / sizeof(arr[0]);//6*4=24  /  4
	SelectionSort(arr,size);
	display(arr,size);
	return 0;
}
