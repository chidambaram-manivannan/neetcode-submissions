class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans((int)temperatures.size(), 0);
        stack<int> pile_temps;
        for (int i = 0; i < (int)temperatures.size(); ++i) {            
            while (pile_temps.size()) {
                if (temperatures[i] > temperatures[pile_temps.top()]) {
                    ans[pile_temps.top()] = i - pile_temps.top();
                    pile_temps.pop();
                } else {
                    pile_temps.push(i);
                    break;
                }
            }

            if (pile_temps.empty()) {
                pile_temps.push(i);
                continue;
            }
        }
        
        return ans;
    }
};