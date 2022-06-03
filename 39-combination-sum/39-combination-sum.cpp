class Solution {
public:
    //Striver's General Code for Recursion
    // https://www.youtube.com/watch?v=OyZFFqQtu98&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=8 24:21 for CPP code.
    
    void helper(vector<int> arr, vector<vector<int>> &ans, vector<int> helperAns, int idx, int target, int n){
        if(idx >= n){
            //base case
            if(target == 0){
                ans.push_back(helperAns);
                return;
            }
            return;
        }
        
        if(arr[idx]<= target){
            helperAns.push_back(arr[idx]);
            target -= arr[idx];
            helper(arr, ans, helperAns, idx, target, n);  // taking same index
            target += arr[idx];
            helperAns.pop_back();
        }
        helper(arr, ans, helperAns, idx+1, target, n);  // ignoring the index and moving forward to pick another one.
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> ans;
        vector<int> helperAns;
        
        helper(arr, ans, helperAns, 0, target, n);
        return ans;
    }
};