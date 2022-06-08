// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
void rotate(int arr[], int n);

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int a[n] , i;
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        rotate(a, n);
        for (i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");
    }
        return 0;
}
// } Driver Code Ends


//User function Template for C++
void reverseArr(int* arr,int i,int end){
    if(i >= end)
      return;
    
    //Do this
    swap(arr[i],arr[end]);
    reverseArr(arr,i+1,end-1);
}
void rotate(int arr[], int n)
{
    reverseArr(arr,0,n-2);
    reverseArr(arr,0,n-1);
}