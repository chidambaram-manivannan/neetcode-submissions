class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> nums_set;
        for (auto &num : nums) {
            if (nums_set.count(num)) return true;
            else nums_set.insert(num);            
        }     
        return false;
    }
};
