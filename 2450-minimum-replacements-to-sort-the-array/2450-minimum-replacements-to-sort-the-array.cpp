/*
 logic => we have to check for the decreasing order of the array and convert it into non-decreasing order.
=> let's take an example [2,4,7,2]=> start iterating from the backward and check for the number that is greater than the number we have seen or not in order.
=> So, In this array lets take the current minimum or number we have seen is "2" from the backward.
=>now, start iterating in the array and check for the number which is greater than the number we have seen, 2->7 now 7 is greater than 2 then we have to break it,
=> now how to break the number into the smaller number than 2,
divide 7 into 3,4 => then 3-> 1,2 and 4-> 2,2 and total_steps is 3.
=> now we have [2,4,1,2,2,2,2] => now current min is 1 and 4 is greater than 1 then divide it further to 4-> 2,2 -> 1,1,1,1 and total steps is 3.
=>now we have [2,1,1,1,1,1,2,2,2,2] and current min is 1
=> now 2 is less than 1 then further divide it to 2-> 1,1 and steps is 1.
=> now the whole array is sorted [1,1,1,1,1,1,1,2,2,2,2] and total steps is 7.


=> But do we actually need to divide the number can we just not count the steps and take the minimum.
=> steps = number/current_min - 1 and curent minimum is min(current_min,number/steps+1) 

 */

class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans = 0;
         
        int n = nums.size();

        int current_min = nums[n-1];

        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]>current_min)
            {
                int steps = ceil(nums[i] / (1.0 * current_min)) - 1;
                ans+= steps;
                current_min = min(current_min,nums[i]/(steps+1));
            }
            else current_min = nums[i];
        }
        return ans;
    }
};