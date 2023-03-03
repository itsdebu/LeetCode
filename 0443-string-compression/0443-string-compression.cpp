class Solution {
public:
    int compress(vector<char>& chars) {
         int writeIndex = 0, currentCount = 1;

        char prev = chars[0];

        for(int i=1 ; i<=chars.size() ; i++) {
            if(i < chars.size() && prev == chars[i]) {
                currentCount++;
            }
            else {
                chars[writeIndex++] = prev;
                if(currentCount > 1) {
                    string digits = to_string(currentCount);

                    for(int j=0 ; j<digits.size() ; j++) {
                        chars[writeIndex++] = digits[j];
                    }
                }

                currentCount = 1;
                if(i < chars.size()) prev = chars[i];
            }
        }

        return writeIndex;
    }
};