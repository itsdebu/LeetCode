class Solution {
public:
    vector<int> evenOddBit(int n) {
      if(n==2)return {0,1};
        long long c=0;
        int count=0;
        int even,odd=0;
        while(n!=0)
        {
            c=n%2;
            n/=2;
            if(c==1 and count%2==0)even++;
            else if(c==1 and count%2!=0)odd++;
            count++;
        }
        return {even,odd};
    }
};