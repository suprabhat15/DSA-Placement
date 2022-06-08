class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n==0)return 0;
        vector<int> lis(nums.size(),1);
        lis[0]=1;
        for(int i=1;i<n;i++){
            lis[i]=1;
            for(int j=i-1;j>=0;j--){
                if(nums[j] >= nums[i]) continue;
                int possibleAns = lis[j] +1;
                if(possibleAns > lis[i]) lis[i]=possibleAns;
            }
        }
        int res = 0;
        for(int i=0;i<n;i++){
            if(res<lis[i]) res = lis[i];
        }
        return res;
    }
};