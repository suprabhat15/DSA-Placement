class Solution {
public:
    int dp[601][101][101];
    pair<int,int> count_zero_one(string s){
        int one = 0,zero = 0;
        for(int i=0;i<s.length();i++){
            if(s[i] == '0') zero++;
            else one++;
        }
        return {zero,one};
    }
    
    int solve(vector<string>& strs, int &max_zero, int &max_one,int one,int zero,int idx){
        
        if(idx >= strs.size()) return 0;
        
        if(one > max_one || zero > max_zero) return 0;
        
        if(dp[idx][one][zero] != -1){
            return dp[idx][one][zero];
        }
        
        pair<int,int>p = count_zero_one(strs[idx]);
        int res1 = 0,res2 = 0,res3 = 0;
        if(zero + p.first <= max_zero && one + p.second <= max_one){
            res1 = 1 + solve(strs,max_zero,max_one,one + p.second,zero + p.first,idx + 1);
            res2 = solve(strs,max_zero,max_one,one ,zero,idx + 1);
        }
        else{
            res3 = solve(strs,max_zero,max_one,one ,zero,idx + 1); 
        }
        
        return dp[idx][one][zero]= max({res1,res2,res3});
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        int max_zero = m; 
        int max_one = n;
        memset(dp,-1,sizeof(dp));
        return solve(strs,max_zero,max_one,0,0,0);

    }
};