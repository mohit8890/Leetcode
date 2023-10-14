class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        numsList = {}
        for i,n in enumerate(nums):
            diff = target-n
            if diff in numsList:
                return [numsList[diff],i]
            else:
                numsList[n]=i        