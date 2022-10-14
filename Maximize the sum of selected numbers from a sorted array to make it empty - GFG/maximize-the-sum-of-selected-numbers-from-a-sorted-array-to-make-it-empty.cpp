//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 
  

// } Driver Code Ends
class Solution{
    public:
    int maximizeSum(int a[], int n) 
    {
        // Complete the function
        
        unordered_map<int,int>ma;

        

        for(int i=0;i<n;i++){

            ma[a[i]]++;

        }

        sort(a,a+n,greater<int>());  //then sorted in decreasing order

        

        

        int start=0; //starting index will be maximum element

        int ans=0;

        

        while(start<n){

            

            if(ma[a[start]]>0){

                ans+=a[start];

                ma[a[start]]--;

                ma[a[start]-1]--;

                

            }

            start++;

        }

        

        return ans;
    }

};


//{ Driver Code Starts.



int main()
{
    
    int t;cin>> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr, arr+n);
        Solution ob;
        
        cout << ob.maximizeSum(arr, n) << endl;
        
        
    }

}


// } Driver Code Ends