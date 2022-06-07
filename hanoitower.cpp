#include<bits/stdc++.h>
using namespace std;
//https://youtu.be/QDBrZFROuA0
void hanoitower(int n,char a,char b,char c)
{
    if(n==0)//base case
    {
        //cout<<n<<"("<<a<<"->"<<b<<")";
        return ;
    }
    hanoitower(n-1,a,c,b);
    cout<<n<<"("<<a<<"->"<<b<<")"<<"\n";//IN area
    hanoitower(n-1,c,b,a);
}
int first_occur(int arr[],int key,int n,int index=0)
{
    if(index==n)
    {
        return -1;
    }
    if(arr[index]==key)
    {
        return 0;
    }
    int val=first_occur(arr,key,n,index+1);
    if(val>=0)
    {
        return val+1;
    }
    else
    {
        return val;
    }
}
int main()
{
    int arr[]={1,4,3,1,2,5,5};
    int n=sizeof(arr)/sizeof(int);
    cout<<first_occur(arr,5,n,0);
    return 0;
}

