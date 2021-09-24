//faster than 100%
class Solution {
public:
    
    int rob(vector<int>& a) {
        int n=a.size();
        if(n==1)return a[0];
        
        int dp[n];
        dp[0]=a[0];
        dp[1]=max(a[0],a[1]);
        
        for(int i=2;i<n;i++)
        {
            dp[i]=max(dp[i-1],a[i]+dp[i-2]);
        }
        return dp[n-1];
    }
};
