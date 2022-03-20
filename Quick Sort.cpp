#include <iostream>
using namespace std;
int partition(int arr[] , int first , int last)
{
    int pivot = arr[first] , i = first , j = last;
    while(i<j)
    {
        do
        {
            i++;
        }while(arr[i] <= pivot);
        do
        {
            j--;
        }while(arr[j] > pivot);
        if(i<j)
            swap(arr[i] , arr[j]);
    }
    swap(arr[first] , arr[j]);
    return j;
}
void quickSort(int arr[] , int first , int last)
{
    if(first<last)
    {
        int pivot = partition(arr , first , last);
        quickSort(arr,first,pivot);
        quickSort(arr, pivot+1 , last);
    }
}
void display(int arr[] , int  n)
{
    for(int i = 0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main()
{
    int arr[] = { -60, 0, 50, 30, 10,20 };
	int n = sizeof(arr) / sizeof(arr[0]);//6*4=24  /  4
	quickSort(arr,0,n);
	display(arr,n);
	return 0;
}
