//copy some from 739.cpp
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> n2=nums;
        nums.insert(nums.begin(),n2.begin(),n2.end());
        int n=nums.size();
        vector<int> ans(n,-1);
        stack<int> s={};
        for(int i=0;i<n;i++){        
            while(!s.empty()&&nums[s.top()]<nums[i]){
                int k=s.top();
                ans[k]=i;
                s.pop();
               // printf("top=%d\n",k);
            }         
            s.push(i);
            //printf("i=%d\n",temperatures[i]);
        }
        vector<int> ans2(n/2,-1);
        for(int i=0;i<n/2;i++)
            if(ans[i]!=-1)ans2[i]=nums[ans[i]];
        return ans2;
    }
};
