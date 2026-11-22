class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans = {};
        if(nums.size() < 3) return ans;

        sort(nums.begin(), nums.end()); // O(n logn)
        int n = (int)nums.size();
        for(int i = 0; i < n - 2; ++i) {
            // handle duplicate in i pointer
            if (i >= 1) {
                if(nums[i]== nums[i-1]) {
                    continue;
                }
            }
            int j = i + 1, k = n - 1;
            while (j < k) {
                //handle duplicate in j pointer
                if(j >= i+2) {
                    if(nums[j] == nums[j-1]) {
                        j++;
                        continue;
                    }
                }

                // handle duplicate in k pointer
                if(k <= n-2) {
                    if (nums[k] == nums[k+1]) {
                        k--;
                        continue;
                    }
                }

                // 2sum for j and k, equating to -(ith element)
                if(nums[j] + nums[k] < -nums[i]) {
                    j++;
                    continue;
                }
                if(nums[j] + nums[k] > -nums[i]) {
                    k--;
                    continue;
                }
                if(nums[j] + nums[k] == -nums[i]) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
            }
        }
        return ans;
    }
};