#include<bits/stdc++.h>
using namespace std;
int exact(int arr[],int l,int h,int n){
    int i=l;
    int j=h;
    int pivot=arr[l];
    while(i<=j){
        do{
            i++;
        }while(arr[i]<pivot);
        do{
            j--;
        }while(arr[j]>pivot);
        if(i<=j){
            swap(arr[i],arr[j]);
        }
    }
    swap(n,arr[j]);
    return j;
}
int main(){
    int arr[5]={3,4,1,2,5};
    int n;
    for(int i=0;i<5;i++){
        cout<<arr[i]<<endl;
    }
    cout<<"Correct position of "<< arr[0] <<" is: "<<exact(arr,0,4,n);
}