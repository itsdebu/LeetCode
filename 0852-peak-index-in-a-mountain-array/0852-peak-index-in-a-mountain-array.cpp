class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int index=0;
        int mx=INT_MIN;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]>mx)
            {
                mx=arr[i];
                index=i;
            }
        }return index;
    }
};