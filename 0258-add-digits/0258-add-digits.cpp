class Solution {
public:
    int addDigits(int num) {
        if(num<10)return num;
        int sum=0;
        int temp=num;
        while(num>=10)
        {
            int n=temp%10;
            sum+=n;
            temp/=10;
            if(temp==0)
            {
                temp=sum;
                sum=0;
                num=temp;
            }
        }return num;
    }
};