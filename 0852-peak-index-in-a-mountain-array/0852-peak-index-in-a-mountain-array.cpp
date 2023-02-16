class Solution {
public:
    int bs(vector<int>&arr,int i,int j)
    {

        if(i<j){
            int mid=i+(j-i)/2;
            if(arr[mid]<arr[mid+1])
                return bs(arr,mid+1,j);
            else return bs(arr,i,mid);
        }return i;
    }
    int peakIndexInMountainArray(vector<int>& arr) {
        return bs(arr,0,arr.size()-1);
    }
};