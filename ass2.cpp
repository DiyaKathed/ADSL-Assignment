#include <iostream>
using namespace std;

void merge(int arr[], int low, int mid ,int high) {
    int temp[100];
    int i,j,k;
    i=low;
    j=mid+1;
    k=low;

    while(i<=mid && j<=high){
        if(arr[i]<=arr[j]){
            temp[k]=arr[i];
            i++;
        }
        else{
            temp[k]=arr[j];
            j++;
        }
        k++;
    }
    while(i<=mid){
        temp[k]=arr[i];
        i++;
        k++;
    }
    while(j<=high){
        temp[k]=arr[j];
        j++;k++;
    }
    for(int i=low;i<=high;i++){
        arr[i]=temp[i];
    }
}

void mergeSort(int arr[],int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

int main() {
    int n;
    cout<<"Enter number of elements";
    cin>>n;

    int arr[n];
    int j=0;

    cout<<"Enter array elements";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            arr[j]=arr[i];
            j++;
        }
    }

    mergeSort(arr, 0, j - 1);

    while(j<n){
        arr[j]=0;
        j++;
    }
    for(int i=0;i<j;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}