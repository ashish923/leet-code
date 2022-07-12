class Solution {
public:
    int a = 0,b = 0 , c = 0, d = 0;
    bool makesquare(vector<int>& sticks) {
        int n = sticks.size();
        
        if(n < 4) return false;
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += sticks[i];
        }
        
        if(sum%4 != 0) return false;
        
        int s = sum/4;
         a = s,b = s , c = s, d = s;
        sort(sticks.rbegin(),sticks.rend());
        
        return solve(sticks,0);
    }
    
    bool solve(vector<int> &matchsticks, int i) {
        
        
      if(i==matchsticks.size()){
            if(a==0 && b==0 && c==0 && d==0) return true;
            else return false;
        }
    
        if(matchsticks[i]<=a){
            a-=matchsticks[i];
            if(solve(matchsticks,i+1)) return true;
            a+=matchsticks[i];    
        }
        
        if(matchsticks[i]<=b){
            b-=matchsticks[i];
            if(solve(matchsticks,i+1)) return true;
            b+=matchsticks[i];                     
        }
        
        if(matchsticks[i]<=c){
            c-=matchsticks[i];
            if(solve(matchsticks,i+1)) return true;
            c+=matchsticks[i];        
        }
        
        if(matchsticks[i]<=d){
            d-=matchsticks[i];
            if(solve(matchsticks,i+1)) return true;
            d+=matchsticks[i];       
        }
        return false;
        
    }
};