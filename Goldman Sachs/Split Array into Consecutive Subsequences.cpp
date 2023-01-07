class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n=nums.size();
        unordered_map <int,int> am,pm;
        for (int i=0;i<n;i++){
            am[nums[i]]++;
        }
        for (int i=0;i<n;i++){
            if (am[nums[i]]<=0) continue;
            else if (pm[nums[i]]>0){ //needed to be added in a seq
                am[nums[i]]--;
                pm[nums[i]]--;
                pm[nums[i]+1]++;
            }
            else if (am[nums[i]]>0 && am[nums[i]+1]>0 && am[nums[i]+2]>0){ //start a new
                am[nums[i]]--;
                am[nums[i]+1]--;
                am[nums[i]+2]--;
                pm[nums[i]+3]++;
            }
            else{
                return false;
            }
        }
        return true;
    }

};
