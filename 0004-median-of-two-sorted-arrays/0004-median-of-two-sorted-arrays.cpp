class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>v;
        for(int i=0;i<nums1.size();i++)
        {
            v.push_back(nums1[i]);
        }
        for(int i=0;i<nums2.size();i++)
        {
            v.push_back(nums2[i]);
        }
        sort(v.begin(),v.end());
        int n=v.size();
        if(n%2!=0)return double(v[n/2]);
        else 
        {
            int c=n/2;
            return double (v[c-1]+v[c])/2;
        }
    }
};