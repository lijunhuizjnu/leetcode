class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int p[100005]={1};
        int l=0,n=nums.size(),r=n-1;
        for(int i=1;i<n+1;i++){
            p[i]=p[i-1]*2%1000000007;
        }
        int ans=0;
        while(l<=r){
           // printf("%d %d\n",l,r);
            if(nums[r]+nums[l]>target)
                r-=1;
            else {
                ans=ans+p[r-l]%(1000000007);
                ans=ans%1000000007;
                l+=1;
            }
        }
        return ans;
    }
};
