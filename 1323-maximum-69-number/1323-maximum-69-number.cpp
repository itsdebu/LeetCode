class Solution {
public:
    int rev(int n)
    {
        int rem=0,reverse=0;
        while(n!=0)    
          {    
             rem=n%10;      
             reverse=reverse*10+rem;    
             n/=10;    
          }    
        return reverse;
    }
    int maximum69Number (int num) {
        int n=rev(num);
        int k=0,k1=0,v=0;
        while(n!=0)
        {
            k=n%10;
            if(k==6 and k1==0)
            {
                k=9;
                k1++;
            }n/=10;
            v=v*10+k;
        }return v;
    }
};