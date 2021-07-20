class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int L=nums.size();
        if(L==0)return {-1,-1};
        int ans1=-1,ans2=-1;
        //找左边界
        int l=0,r=L;
        while(l<r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target){
                r=mid;
            }
            else if(nums[mid]<target){
                l=mid+1;
            }
            else{
                r=mid;
            }
            printf("%d %d\n",l,r);
        }
        if(l>=L||target!=nums[l])return {-1,-1};
        ans1=l;
        //找右边界
        l=ans1,r=L;
        while(l<r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target){
                l=mid+1;
            }
            else if(nums[mid]<target){
                l=mid+1;
            }
            else{
                r=mid;
            }
            printf("%d %d\n",l,r);
        }
        if(r>0&&target==nums[r-1])ans2=r-1;
        return {ans1,ans2};
    }
};
