class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        n=len(nums)
        
        a=sum(nums)-sum(set(nums))
        b=sum(set(list(range(1,n+1))))-sum(set(nums))
        return [a,b]
