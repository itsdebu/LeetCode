class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        //binary aearch o(logn)
        int i=0,j=arr.size()-1;
        while(i<j)
        {
            int mid=i+(j-i)/2;
            if(arr[mid]<arr[mid+1])
            {
                i=mid+1;
            }
            else j=mid;
        }return i;
    }
};