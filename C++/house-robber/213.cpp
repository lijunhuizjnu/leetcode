class Solution {
public:
    int rob1(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        printf("%d ",nums[i]);
        printf("\n");
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
        printf("%d\n",ans[L-1]);
        return ans[L-1];            
    }
    int rob(vector<int>& nums) {
        if(nums.size()==0)return 0;
        if(nums.size()==1)return nums[0];
        vector<int> n1=nums;
        vector<int> n2=nums;
        n1.erase(n1.begin());
        n2.pop_back();
        return max(rob1(n1),rob1(n2));

    }
};
