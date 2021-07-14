class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<int> n1=nums1;
        sort(n1.begin(),n1.end());
        int M=0;
        for(int i=0;i<n;i++){
            int l=0,r=n-1;
            while(r>l){
                int mid=(l + r )>> 1;
                if(n1[mid]<nums2[i])l=mid+1;
                else if(n1[mid]==nums2[i])r=l=mid;
                else r=mid-1;
            }
            int K=abs(n1[l]-nums2[i]);
            if(l+1<n)K=min(K,abs(n1[l+1]-nums2[i]));
            if(l-1>=0)K=min(K,abs(n1[l-1]-nums2[i]));
            M=max(M,abs(nums1[i]-nums2[i])-K);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=(ans+abs(nums1[i]-nums2[i]))%(1000000007);
        }
        return (ans+1000000007-M)%(1000000007);
    }
};
