class Solution {
public:
    int numDecodings(string s) {
        int cnt = 0;
        if(s.size() == 0 || (s.size() == 1 && s[0] == '0')) return 0;
        if(s.size() == 1) return 1;
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        for(int i=0;i<s.size();i++ ){
            if(s[i]=='0')dp[i+1]=0;
            else dp[i+1]=dp[i];
            if(i>0){
                int k=(s[i-1]-'0')*10+s[i]-'0';
                if(k>=10&k<=26){
                    dp[i+1]+=dp[i-1];
                }
            }
        }
        return dp.back();
    }
    
};
