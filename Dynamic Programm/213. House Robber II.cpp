class Solution {
public:
    int rob(vector<int>& a) {
        int n=a.size();
        if(n==1)return a[0];
        if(n==2)return max(a[0],a[1]);
        vector<int> dp(n,0);
        dp[0]=a[0];
        dp[1]=max(a[0],a[1]);
        
        for(int i=2;i<n;i++)
        {
            dp[i]=max(dp[i-1],a[i]+dp[i-2]);
        }
        
        int ma=dp[n-2];
        
        fill(dp.begin(),dp.end(),0);
        dp[1]=a[1];
        dp[2]=max(a[1],a[2]);
        for(int i=3;i<n;i++)
            dp[i]=max(dp[i-1],a[i]+dp[i-2]);
        
        return ma=max(ma,dp[n-1]);
        
    }
};
