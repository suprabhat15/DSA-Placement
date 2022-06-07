class Solution {
public:
int maxProduct(vector<int>& nums) {
// declared ans to store the final max value till the iteraterd element of the array
int ans = nums[0];
// n is the size of the array
int n = nums.size();
// imax is the maximum product value till the iteraterd element of the array
int imax = ans;

    // imin is the minimum product value till the iteraterd element of the array
    int imin = ans;
    
    for(int i=1;i<n;i++) {
        // If the array element is negative then is multiplied with the max product till now change it to minimum value and min product valu so far to maximum value. Thus swap the max and min value so far 
        if(nums[i]<0)
            swap(imax,imin);
        imax = max(nums[i], imax*nums[i]);
        imin = min(nums[i], imin*nums[i]);
        ans = max(ans, imax);
    }
    // return the answer
    return ans;
}
};
// Time Complexity: O(n)
// Auxiliary Space: O(1)