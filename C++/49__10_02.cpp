class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>  m={};
        int L=strs.size();
        for(int i=0;i<L;i++){
            string s = strs[i];
            sort(s.begin(),s.end());
            if(m.find(s)==m.end()){
                m[s]={};
            }
            m[s].push_back(strs[i]);    
        }
        vector<vector<string>> ans={};
        for(auto [_,k]:m){
            ans.push_back(k);
        }
        return ans;
    }
};
