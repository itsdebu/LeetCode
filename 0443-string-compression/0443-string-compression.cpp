class Solution {
public:
int compress(vector<char>& v) {
        
        int cnt = 1;

        char prev = v[0];

        int n = v.size();

        vector<char>rejult;

        for(int i = 1 ;i < n ; i++){
            if(v[i] == prev){
                cnt++;
            }else{
                

                if(cnt == 1){
                    rejult.push_back(prev);
                }
                else if(cnt<=9){
                    rejult.push_back(prev);
                    char ch = '0'+cnt;
                    rejult.push_back(ch);
                }
                else{
                    rejult.push_back(prev);
                    string temp = to_string(cnt);
                    int j = 0;
                    while(j<temp.size()){
                        rejult.push_back(temp[j++]);
                    }
                }
                
                prev=v[i];
                cnt=1;
            }
        }
        if(cnt == 1 ){
            rejult.push_back(prev);
        }
        else if(cnt<=9){
            rejult.push_back(prev);
            char ch = '0'+cnt;
            rejult.push_back(ch);
        }
        else{
            rejult.push_back(prev);
            string temp = to_string(cnt);
            int j = 0;
            while(j<temp.size()){
                rejult.push_back(temp[j++]);
            }
        }


        v=rejult;
      
        return rejult.size();
    }
};