class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] == nums[i + 1]){
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }

        vector<int> result(n, 0);
        int idx = 0;

        for(int num : nums){
            if(num != 0){
                result[idx++] = num;
            }
        }
        return result;
    }
};
