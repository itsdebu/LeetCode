class Solution {
public:
    int maximumBags(vector<int>& c, vector<int>& r, int rock) {
        int count=0;
        vector<int>v;
        for(int i=0;i<c.size();i++)
        {
            v.push_back(c[i]-r[i]);
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++)
        {
            if(rock>=v[i] and v[i]!=0)
            {
                rock-=v[i];
                v[i]=0;
            }
            else if(v[i]<rock and v[i]!=0)
            {
                v[i]=v[i]-rock;
                rock=0;
            }
        }
        for(int i=0;i<v.size();i++)
        {
            if(v[i]==0)count++;
        }return count;
    }
};