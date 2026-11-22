class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        map<int, double> pos_time_map;
        int n = (int)position.size();

        for(int i = 0; i < n; ++i) {
            pos_time_map[position[i]] = (double)(target - position[i]) / speed[i];
        }

        auto last_in_map = pos_time_map.rbegin();
        long int finish_time = lround(last_in_map->second * 100.0);
        int carFleets_ans = 1;
        for (auto it = pos_time_map.rbegin(); it != pos_time_map.rend(); ++it) {
            if (lround(it->second * 100) > finish_time) {
                carFleets_ans++;
                finish_time = lround(it->second * 100);
            }
        }

        return carFleets_ans;
    }
};