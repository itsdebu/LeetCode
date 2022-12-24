class Solution {
public:
    int numTilings(int n) {
        if(n<3)return n;
        vector<long long>v(n);
        v[0]=1;
        v[1]=2;
        v[2]=5;
         int mod = pow(10, 9) + 7;
        if(n<=3)return v[n-1];
        for(int i=3;i<n;i++)
        {
            v[i]=(v[i-1]*2+v[i-3])%mod;
        }return v[n-1];
    }
};