class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> mp;
        int n  = nums.size();
        
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto x : mp){
            pq.push({x.second,x.first});
           
        }
        vector<int> ans;
        
        while(k-- && !pq.empty()){
            pair<int,int> p = pq.top();
            pq.pop();
                ans.push_back(p.second);
        }
        return ans;

    }
};