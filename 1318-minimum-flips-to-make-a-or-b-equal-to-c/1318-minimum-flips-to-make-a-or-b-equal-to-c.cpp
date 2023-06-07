class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count=0;
        while(a>0 or b>0 or c>0)
        {
            int num1=a%2,num2=b%2;
            if(c%2==0)
            {
                if(num1+num2>0)count+=num1+num2;
            }
            else
            {
                if(num1+num2==0)count+=1;
            }
            a/=2,b/=2,c/=2;
        }return count;
    }
};