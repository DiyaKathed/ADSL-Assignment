#include<iostream>
using namespace std;

int trailingZeroes(int n) {
    int count = 0;
    while (n>0){
        count+=n/5;
        n/=5;
    }
    return count;
}
int smallestFactorial(int n){
    if(n==0||n==1) return 5;
    int ans = -1;
    int low=0, high=5*n;
    while (low<=high){
        int mid=(low+high)/2;
        if(trailingZeroes(mid)>=n){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
        }
    return low;
}
int main(){
    int n;
    cout<<"Enter number of Trailing Zeroes";
    cin>>n;
    cout<<smallestFactorial(n);
    return 0;
}