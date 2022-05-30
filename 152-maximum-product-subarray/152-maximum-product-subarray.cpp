class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int n=arr.size();
        int mx=arr[0];
        int mn=arr[0];
        int res=arr[0];
        for(int i=1;i<n;i++){
            int v1 = arr[i]*mx;
            int v2 = arr[i]*mn;
            mx=max(arr[i],max(v1,v2));
            mn=min(arr[i],min(v1,v2));
            // cout<<mx<<" "<<mn<<endl;
            res=max(res,mx);
        }
        return res;        
    }
   };