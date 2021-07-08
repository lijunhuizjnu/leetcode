class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        map<long long int,long long int> d={};
        for(auto de : deliciousness){
            long long int dd=de;
            d[dd]+=1;
        }
        //sort(d.begin(),d.end());
        long long int target = 1;
        int ans=0;
        for(int i=0;i<=21;i++){
            ans+=twoSum(d,target);
            target*=2;
        }
        return ans;
    }
    int twoSum(map<long long int,long long int>& nums, long long int target) {
        map<long long int,long long int>::reverse_iterator end=nums.rbegin();
        map<long long int,long long int>::iterator start=nums.begin();
        long long int ans=0;
        while(start->first<=end->first){
            if(start->first==end->first){
                if(start->first+end->first==target)
                    ans+=start->second*(start->second-1)/2;
                break;
            }
            if(start->first+end->first==target){
                ans+=start->second*end->second;
                start++;end++;
            }
            else if(start->first+end->first<target){
                start++;
            }
            else {
                end++;
            }
            ans=ans%(1000000000+7);
        }
        //printf("%lld %d\n",target,ans);
        return ans;
    }
};
