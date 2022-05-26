class Solution {
public:
    void helper(vector<int> nums, vector<vector<int>> &ans, vector<int> helperAns, int freq[]){
        if(helperAns.size() == nums.size()){
            ans.push_back(helperAns);
            return;
        }
        
        for(int i=0;i<nums.size();i++){
           if(!freq[i]) {
                freq[i]=1;
                helperAns.push_back(nums[i]);
                helper(nums, ans, helperAns, freq);
                helperAns.pop_back();
                freq[i]=0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> helperAns;
        vector<vector<int>> ans;
        int freq[nums.size()];
        for(int i=0;i<nums.size();i++)freq[i]=0;
        helper(nums, ans, helperAns, freq);
        return ans;
    }
};