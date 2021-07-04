//copy some from 739.cpp
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> ans(n,-1);
        stack<int> s={};
        for(int i=0;i<n;i++){        
            while(!s.empty()&&temperatures[s.top()]<temperatures[i]){
                int k=s.top();
                ans[k]= temperatures[i];
                s.pop();
               // printf("top=%d\n",k);
            }         
            s.push(i);
            //printf("i=%d\n",temperatures[i]);
        }
        return ans;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> m=dailyTemperatures(nums2);
        map<int,int>ma={};
        for(int i=0;i<m.size();i++){
            ma[nums2[i]]=m[i];
            printf("%d ",m[i]);
        }
        vector<int> ans(nums1.size());
        for(int i=0;i<nums1.size();i++){
            ans[i]=ma[nums1[i]];
        }
        return ans;
    }
};
