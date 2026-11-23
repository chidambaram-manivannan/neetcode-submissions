# https://neetcode.io/problems/products-of-array-discluding-self/question?list=neetcode150
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        ans = [0] * len(nums)

        product_all = 1
        no_of_zeros = 0
        for e in nums:            
            if e == 0:
                no_of_zeros += 1
                continue

            product_all *= e
        
        if no_of_zeros > 1:
                return ans

        for i, e in enumerate(nums):
            if no_of_zeros == 1:
                if e == 0:
                    ans[i] = product_all
            else:
                if e == 0:
                    continue
                ans[i] = product_all // e

        return ans