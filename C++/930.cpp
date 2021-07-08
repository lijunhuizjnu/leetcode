class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        vector<int> c(n+1,0);
        int S=0,ans=0;
        c[0]=1;
        for(int i=0;i<n;i++){
            //printf("c[%d]\n",i);
            S+=nums[i];
            if(S>=goal)ans+=c[S-goal];
            c[S]+=1;
        }
    
        return ans;
    }
};
