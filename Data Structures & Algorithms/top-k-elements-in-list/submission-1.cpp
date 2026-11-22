class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map_nums;
        for (auto &num : nums) {
            map_nums[num]++;
        }

        multimap<int, int> frequencies;
        for (auto &p : map_nums) {
            frequencies.insert({p.second, p.first});
        }

        vector<int> ans;
        auto it = frequencies.rbegin();
        for (int i = 0; it != frequencies.rend() && i < k; it++, i++) {
            ans.push_back(it->second);
        }

        return ans;
    }
};
