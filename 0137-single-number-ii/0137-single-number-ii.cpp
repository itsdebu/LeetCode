class Solution {
public:
    int singleNumber(vector<int>& nums) {
        long long int res=0;
        for(int i=0;i<32;i++)
        {   int p=0;
            for(int j=0;j<nums.size();j++)
            {   
			    int k=abs(nums[j]);
                p+=(k&(1<<i))!=0?1:0;    //by shifting 1 to left ith time and taking and with1  will give us 
				                                         //that ith bit of nums[j] is 1 or 0
            } 
           p%=3; 
          res+=pow(2,i)*p;
        } 
		/*
		**To handle if res is -ve**
		 We have calculated our result positive number
		 But there may be chance that single number may be negative
		 Eg.array= [2,2,-4,2]
		 Here after bitwise calculation our res will store 4 
		 but you see that 4 is not present in  our array.
		 So , we will check if res (4) is present in array or not
		 if present , then return it else res must be -ve
		 Hence return -res (-4):
		*/
        cout<<res;
        int c=0;
        for(auto x:nums)   //for negative numbers
          if(x==res) {c++;}   //if our calculates value res is present in array, then increment c
        return c==1?res:-res; //if c=1 return res else res must be -ve
    }
};