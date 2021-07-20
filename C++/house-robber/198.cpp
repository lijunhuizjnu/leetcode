class Solution {
public:
    int rob(vector<int>& nums) {
        int L=nums.size();
        if(L==0)return 0;
        int ans[L];
        ans[0]=nums[0];
        if(L!=1){
            ans[1]=max(nums[0],nums[1]);
            for(int i=2;i<L;i++){
                ans[i]=max(ans[i-1],ans[i-2]+nums[i]);
            }
        }
        return ans[L-1];    
        
    }
};
