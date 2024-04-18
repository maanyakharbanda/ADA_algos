#include<iostream>
using namespace std;
void merging(int arr1[],int arr2[],int temp[],int m,int n){
    int i=0;
    int j=0;
    int index=0;
    while(i<m && j<n){
        if(arr1[i]<arr2[j]){
            temp[index++]=arr1[i++];
        }
        else{
            temp[index++]=arr2[j++];
        }
    }
    while(i<m){
        temp[index++]=arr1[i++];
    }
    while(j<m){
        temp[index++]=arr2[j++];
    }
}
void display(int arr[],int x){
    for(int i=0;i<x;i++){
        cout<<arr[i]<<endl;
    }
};
int main(){
    int arr1[5]={1,3,5,7,9};
    int m=5;
    display(arr1,m);
    cout<<endl;
    int arr2[4]={2,4,6,8};
    int n=4;
    display(arr1,n);
    cout<<endl;
    int temp[m+n];
    merging(arr1,arr2,temp,m,n);
    display(temp,m+n);
    return 0;
}