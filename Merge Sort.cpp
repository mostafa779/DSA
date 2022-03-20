#include <iostream>
using namespace std;
void merge(int arr[] , int left , int mid , int right)
{
    int i,j,k;
    int n1 = mid-left+1 , n2 = right - mid;
    int *L_arr = new int [n1] , *R_arr = new int [n2];
    for(i=0; i<n1; i++)
        L_arr[i] = arr[left+i];
    for(j=0; j<n2; j++)
        R_arr[j] = arr[mid+1+j];
    i=j=0;
    k=left;
    while(i<n1 && j<n2)
    {
        if(L_arr[i]<=R_arr[j])
        {
            arr[k] = L_arr[i];
            i++;
        }
        else
        {
            arr[k] = R_arr[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        arr[k] = L_arr[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k] = R_arr[j];
        j++;
        k++;
    }
}
void MergeSort(int arr[] , int left , int right)
{
    if(left<right)
    {
        int mid = left + (right - left) / 2;
        MergeSort(arr,left,mid);
        MergeSort(arr,mid+1,right);
        merge(arr,left,mid,right);
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
	MergeSort(arr,0,n-1);
	display(arr,n);
	return 0;
}
