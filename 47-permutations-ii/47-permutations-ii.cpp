class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
         vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        solve(nums,0,ans);
        return ans; 
        
    }
    
     void solve(vector<int> nums, int i,vector<vector<int>> &ans){
        if(i == nums.size()-1){
            ans.push_back(nums);
            return;
        }
        set<int> s;
        for(int j = i; j<nums.size(); j++){
            if(s.find(nums[j]) != s.end())
                continue;
            s.insert(nums[j]);
            swap(nums[j],nums[i]);
            solve(nums,i+1,ans);
            swap(nums[j],nums[i]);
        }
    }
};



   