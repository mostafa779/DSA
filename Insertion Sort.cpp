#include <iostream>
using namespace std;
void InsertionSort(int arr[] , int n)
{
    int key , j;
    for(int i=1; i<n; i++)
    {
        key=arr[i]; //80
        j= i-1;// i=2 , j=1
        while(j>=0 && arr[j]>key) //60 70 80 100
        {
            arr[j+1] = arr[j];
            j-=1;
        }
        arr[j+1] = key;
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
    int arr[] = { 0, -60 , 50, 30, 10,20 };
	int size = sizeof(arr) / sizeof(arr[0]);//6*4=24  /  4
	InsertionSort(arr,size);
	display(arr,size);
	return 0;
}
