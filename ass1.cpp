#include <iostream>
using namespace std;

int main() {
    int n,j;
    cout<<"Enter number of elements";
    cin>>n;

    int arr[n];

    cout<<"Enter elements of array";
    for(int i=0;i<n;i++)
        cin>>arr[i];

    int low=0,high=n-1,mid;
    int firstZero = n; //firstZero in array at which index

    for(int i=0; i<n-1;i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j]<arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    cout<<"Sorted array:";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    while(low<=high)
    {
        mid=(low+high)/2;
        if(arr[mid]==0)
        {
            firstZero = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout<<"Number of 0's in array is"<<n-firstZero;
    return 0;
}