class Solution {
public:
    vector<vector<int>> sol;
    void fun(int ind,int n,vector<int> &a,vector<int> ans,int target,int sum)
    {
        if(sum>target)return ;
        if(sum==target)
        {
            sol.push_back(ans);
            return ;
        }
        
        for(int i=ind;i<n;i++)
        {
            if(i>ind && a[i]==a[i-1])continue;  //only diff in this line in combination sum and combination sum II
            ans.push_back(a[i]);
            fun(i+1,n,a,ans,target,sum+a[i]);
            ans.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& a, int target) {
        vector<int> ans;
        int n=a.size();
        sort(a.begin(),a.end());  // and also sort
        
        fun(0,n,a,ans,target,0);
        return sol;
    }
};
