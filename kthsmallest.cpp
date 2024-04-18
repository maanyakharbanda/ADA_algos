#include<iostream>
using namespace std;
int partition(int arr[],int low,int high){
    int pivot=arr[low];
    int i=low;
    int j=high;
    while(i<j){
        while(arr[i]<=pivot && i<=high-1){
            i++;
        }
        while(arr[j]>=pivot && j>=low+1){
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[low],arr[j]);
    return j;
}
int check(int arr[],int low,int high,int k){
    int j=partition(arr,low,high);
    if(j==k){
        return arr[j];
    }
    else if(j<k){
        return check(arr,j+1,high,k);
    }
    else{
        return check(arr,low,j-1,k);
    }
}
int main(){
    int arr[5]={4,5,2,3,1};
    int low=0;
    int high=sizeof(arr)/sizeof(arr[0]);
    int k=4;
    cout<<check(arr,low,high,k);
}