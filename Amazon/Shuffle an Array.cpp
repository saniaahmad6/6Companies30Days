class Solution {
    vector<int> arr, idx;
public:
    Solution(vector<int> nums) {
        srand(time(NULL));
        arr.resize(nums.size());
        idx.resize(nums.size());
        for (int i=0;i<nums.size();i++){
            arr[i] = nums[i];
            idx[i] = nums[i];
        }
    }
    
    
    vector<int> reset() {
        for (int i=0;i<arr.size();i++)
            arr[i] = idx[i];
        return arr;    
    }
    
    
    vector<int> shuffle() {
         int i,j;
         for (i = arr.size() - 1; i > 0; i--) {
            j = rand() % (i + 1);
            swap(arr[i], arr[j]);
         }
         return arr;    
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
