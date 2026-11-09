class Solution {
public:
    bool find(vector<int>& nums, int sum, int idx,  vector<vector<int>>&dp){
        if(sum==0)
        return 1;

        if(idx==nums.size())
        return 0;
        

        if(sum<nums[idx])
        return dp[sum][idx]=find(nums, sum,idx+1,dp);

        if(dp[sum][idx]!=-1)
        return dp[sum][idx];

        int pick=find(nums, sum-nums[idx], idx+1,dp);
        int skip=find(nums, sum, idx+1,dp);

        return dp[sum][idx]=pick || skip;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        sum+=nums[i];

        if(sum%2!=0)
        return 0;
        vector<vector<int>>dp(sum/2+1, vector<int>(nums.size()+1,-1));
        return find(nums, sum/2,0,dp);
    }
};