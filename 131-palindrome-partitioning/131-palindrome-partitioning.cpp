class Solution {
public:
    bool isPalindrome(string s, int start, int end){
           while(start<=end){
               if(s[start++]!=s[end--])return false;
           }
        return true;
    }
    void helper(string s, int idx, vector<string> &helperAns, vector<vector<string>> &ans){
        // base case
        if(idx == s.size()){
            ans.push_back(helperAns);
            return;
        }
        
        for(int i=idx;i<s.size();i++){
            if(isPalindrome(s, idx, i)){
                helperAns.push_back(s.substr(idx, i-idx+1));
                helper(s, i+1, helperAns, ans);
                helperAns.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> helperAns;
        helper(s, 0, helperAns, ans);
        return ans;
    }
};