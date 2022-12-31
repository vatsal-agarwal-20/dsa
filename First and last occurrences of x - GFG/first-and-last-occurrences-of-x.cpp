//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

int first(int arr[],int s,int e,int n,int x)
{
    if(e >= s)
    {
        int mid = s+ (e-s)/2;
        
        if ((mid == 0 || x > arr[mid - 1]) && arr[mid] == x)
            return mid;
        else if (x > arr[mid])
            return first(arr, (mid + 1), e, n, x);
        else
            return first(arr, s, (mid - 1), n, x);
    }
    return -1;
}
int last(int arr[],int s,int e,int n,int x)
{
    if(e >= s)
    {
        int mid = s+ (e-s)/2;
        
        if ((mid == n - 1 || x < arr[mid + 1])
            && arr[mid] == x)
            return mid;
        else if (x < arr[mid])
            return last(arr, s, (mid - 1), n, x);
        else
            return last(arr, (mid + 1), e, n, x);
    }
    return -1;
}
vector<int> find(int arr[], int n , int x )
{
    // code here
     int a=first(arr,0,n-1,n,x);
     int b=last(arr,0,n-1,n,x);
    return {a,b};
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends