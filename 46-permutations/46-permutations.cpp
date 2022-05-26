/*
Approach 1
class Solution {
public:
    void helper(vector<int> nums, vector<vector<int>> &ans, vector<int> helperAns, int freq[]){
        if(helperAns.size() == nums.size()){
            ans.push_back(helperAns);
            return;
        }
        
        for(int i=0;i<nums.size();i++){
           if(!freq[i]) {  // if not visited, only then include it in helperAns
                freq[i]=1; // to check whether it's available in helperAns.
                helperAns.push_back(nums[i]);
                helper(nums, ans, helperAns, freq);
                helperAns.pop_back(); // revert back to previous state
                freq[i]=0;  // remove the freq if not included in helperAns.
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
*/

/*Approach 2*/
class Solution {
public:
    void helper(vector<int> nums, int idx, vector<vector<int>> &ans){
        if(idx == nums.size()){
            ans.push_back(nums);
            return;
        }
        
        for(int i=idx;i<nums.size();i++){
            swap(nums[idx], nums[i]);
            helper(nums, idx+1, ans);
            swap(nums[idx], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
         vector<int> helperAns;
        vector<vector<int>> ans;
        helper(nums, 0, ans);
        return ans;
    }
};