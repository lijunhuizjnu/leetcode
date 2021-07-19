class Solution(object):
    def checkSubarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """      
        a=set([nums[0]%k,0])
        S=nums[0]
        print(len(nums))
        for i in range(1,len(nums)):
            # if(i%1000==0):print(i)
            S=(S+nums[i])%k
            if((nums[i]%k==0)&(nums[i-1]%k==0)):
                return True
            if(nums[i]%k==0):
                continue;
            if(S in a):
                return True;
            a.add(S)
        return False
