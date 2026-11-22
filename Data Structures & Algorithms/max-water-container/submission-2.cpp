class Solution {
public:
    int maxArea(vector<int>& heights) {
        int water_max_area = 0;
        int left = 0, right = (int)heights.size() - 1;
        
        while (left < right) {
            int height = min(heights[left], heights[right]);
            int width = right - left;
            int curr_area = height * width;
            water_max_area = max(curr_area, water_max_area);

            if(heights[left] <= heights[right]) {
                left++;
            } else {
                right--;
            }
        }

        return water_max_area;
    }
};
