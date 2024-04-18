#include<iostream>
using namespace std;
int horner(int poly[],int n,int x){
    int result=poly[0];
    for(int i=1;i<n;i++){
        result=result*x+poly[i];
    }
    return result;
}
int main(){
    int poly[]={2,-6,2,-1};
    int n=sizeof(poly)/sizeof(poly[0]);
    int x=3;
    cout<<"Result obtained is: "<<horner(poly,n,x);
}