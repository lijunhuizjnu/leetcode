class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> ans(n,0);
        stack<int> s={};
        for(int i=0;i<n;i++){        
            while(!s.empty()&&temperatures[s.top()]<temperatures[i]){
                int k=s.top();
                ans[k]=i-k;
                s.pop();
               // printf("top=%d\n",k);
            }         
            s.push(i);
            //printf("i=%d\n",temperatures[i]);
        }
        return ans;
    }
};
