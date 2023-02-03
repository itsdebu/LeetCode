class Solution {
public:
	string convert(string s, int numRows) {

		if(numRows==1) return s;
		vector<vector<char>> cnt(numRows);
		int cur=0;
		int flag=1;
		for(int i=0;i<s.size();i++){
			cnt[cur].push_back(s[i]);   
			if(cur==numRows-1){
				flag=0;
			}
			if(cur==0){
				flag=1;
			}
			if(flag==1){
				cur++;
			}
			else{
				cur--;
			}


		}

		string ans;
		for(auto& x:cnt){
			for(auto& v:x){
				ans.push_back(v);
			}
		}

		return ans;
	}
};