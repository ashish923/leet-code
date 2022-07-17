class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        
        int number = nums[0].size(),n = nums.size();
        vector<int> ans;
        for(int i=0; i<queries.size(); i++){    
            int x = queries[i][0];
            int y = queries[i][1];                                                                                        priority_queue<pair<string,int>,vector<pair<string,int>>,greater<pair<string,int>>>p;
            int j = y;
            for(int i=0; i<n; i++){
            string s = nums[i];
            s = s.substr(number - j,j);
            
            p.push({s,i});
        }
        int z =0;
            while( x-- && !p.empty()){
                pair<string,int> pp = p.top();
                p.pop();
                z = pp.second;
            }
            ans.push_back(z);
        }
        
        return ans;
        
    }
};