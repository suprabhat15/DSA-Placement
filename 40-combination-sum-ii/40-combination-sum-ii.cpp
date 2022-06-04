class Solution {
public:
    void solve(vector<int>& arr, vector<vector<int>> &ans, vector<int> helperAns, int idx, int target){
        // base case
        if(target<0)return;
        if(idx >= arr.size()){
            if(target == 0){
                 ans.push_back(helperAns);
                }
                return;
        }
        
       
        helperAns.push_back(arr[idx]);
        solve(arr, ans, helperAns, idx+1, target-arr[idx]);
        helperAns.pop_back();
        
        while(idx+1 <arr.size() && arr[idx] == arr[idx+1]) idx+=1; // for skipping repeated values.
        
        solve(arr, ans, helperAns, idx+1, target);
        
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        vector<int> helperAns;
        solve(arr, ans, helperAns, 0, target);
        return ans;
    }
};