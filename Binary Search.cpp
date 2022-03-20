#include <iostream>
using namespace std;
int binarySearch(int arr[] , int first , int last , int elm)
{

    while(first<=last)
    {
        int mid = (first + last) / 2;
        if(arr[mid] == elm)
            return mid;
        if(arr[mid] > elm)
            last = mid - 1;
        else
            first = mid + 1;
    }
    return -1;
}

int main()
{
    int arr[] = { -60, 0, 50, 30, 10,20 };
	int n = sizeof(arr) / sizeof(arr[0]);//6*4=24  /  4
	int num;
	cout<<"Enter a number to search: ";
	cin>>num;
	int result = binarySearch(arr,0,n-1,num);
	if(result == -1)
        cout<<"Not found"<<endl;
    else
        cout<<"Found at index "<<result<<endl;
	return 0;
}
