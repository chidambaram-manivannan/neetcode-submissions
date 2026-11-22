class Solution {
public:
  int trap(vector<int> &height) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    if (height.empty() || height.size() == 1 || height.size() == 2)
      return 0;

    int ans = 0;
    int n = (int)height.size();

    vector<int> prefix_max(n);
    int max_of_prefix = 0;
    for (int i = 0; i < n; ++i) {
      max_of_prefix = max(max_of_prefix, height[i]);
      prefix_max[i] = max_of_prefix;
    }

    vector<int> suffix_max(n);
    int max_of_suffix = 0;
    for (int i = n - 1; i >= 0; --i) {
      max_of_suffix = max(max_of_suffix, height[i]);
      suffix_max[i] = max_of_suffix;
    }

    for (int i = 0; i < n - 1; ++i) {
      ans += min(prefix_max[i], suffix_max[i]) - height[i];
    }

    return ans;
  }
};
