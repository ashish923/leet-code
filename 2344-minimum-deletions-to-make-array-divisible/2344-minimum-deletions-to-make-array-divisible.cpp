class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        
        priority_queue<int,vector<int>,greater<int>>pq;
        unordered_map<int,int>mp;
        int n  = nums.size();
        for(int i=0; i<n; i++){
            if(mp.find(nums[i]) == mp.end())
                pq.push(nums[i]);
            mp[nums[i]]++;
        }
        int gd = numsDivide[0];
        for(int i=1; i<numsDivide.size(); i++){
            gd = __gcd(gd,numsDivide[i]);
        }
        int s =0;
        while(!pq.empty()){
            int z = pq.top();
            pq.pop();
            if(gd % z == 0)
                return s;
            else{
                s += mp[z];
            }
        }
        
        return -1;  
    }
};