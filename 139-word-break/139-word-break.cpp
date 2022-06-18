class Solution {
public:
int dp[301];
int help(int index, string s,unordered_set<string> &wordDict,vector<int> &dp)
{
if(index==s.length())
return 1;

    if(dp[index]!=-1)
        return dp[index];
    
    string temp="";
    for(int i=index;i<s.size();i++)
    {
        temp+=s[i];
        if(wordDict.find(temp)!=wordDict.end())
        {
            if(help(i+1,s,wordDict,dp))
                return dp[index]=1;
        }
    }
    
    return dp[index]=0;
}
bool wordBreak(string s, vector<string>& wordDict) 
{
    unordered_set<string> st;
    vector<int> dp(s.size()+1,-1);
    
    for(auto x:wordDict)
        st.insert(x);
    
    return help(0,s,st,dp);
    
}
};