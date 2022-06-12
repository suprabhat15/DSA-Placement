------------------------------------------------
With Recursion - 
class Solution {
public:
     int ed(int i , int j , string word1, string word2,vector<vector<int>>&v){
        if(i==-1) return j+1;
        if(j==-1) return i+1;
      if(v[i][j]!=-1) return v[i][j];
        if(word1[i]==word2[j]){
          v[i][j]= ed(i-1,j-1,word1,word2,v); //this is for matching of the last character if they match directly move backward.
        }
        else{
          v[i][j]=1+min(ed(i-1,j-1,word1,word2,v)//this is for the replacement part.
                    ,min(ed(i-1,j,word1,word2,v)// this is for the deletion part
                         ,ed(i,j-1,word1,word2,v)));//this is for the insertion
        }
        return v[i][j];
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>>v(word1.size()+1,vector<int>(word2.size()+1, -1));
        
        return ed(word1.size(),word2.size(),word1,word2,v);
    }
};
