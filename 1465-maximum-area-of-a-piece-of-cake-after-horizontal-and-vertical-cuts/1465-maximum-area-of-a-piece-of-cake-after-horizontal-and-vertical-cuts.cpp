class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        
        
        vector<int> height{horizontalCuts[0]};
        vector<int> length{verticalCuts[0]};
        
        for(int i=1; i<horizontalCuts.size(); i++){
            height.push_back(horizontalCuts[i] - horizontalCuts[i-1]);
        }
        height.push_back(h - horizontalCuts[horizontalCuts.size()-1]);
        
        for(int i=1; i<verticalCuts.size(); i++){
            length.push_back(verticalCuts[i] - verticalCuts[i-1]);
        }
        length.push_back(w - verticalCuts[verticalCuts.size() - 1]);
        
        long long int a = *max_element(height.begin(), height.end());
        long long int b = *max_element(length.begin(), length.end());
        int mod = 1000000007;
        return (int)(a%mod*b%mod);
        a = (int)a%mod;
        b = (int)b%mod;
        return (a*b)%mod;
        
        
    }
};