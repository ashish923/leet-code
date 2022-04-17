class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        
        unordered_map<int,int> mp;
        int s=0,n = tasks.size();
        for(int i=0; i<n; i++){
        mp[tasks[i]]++;    
        }
        
        for(auto x : mp){
            if(x.second==1)
                return -1;
            else{
               int e1 = x.second/3;
               int  e2 =  x.second%3;
                cout<<e1<<e2;
                if(e2==0)
                    s += e1;
                else
                    s=s+e1+1;
            }
        }

        
      return s;  
}
        
   
        
    
};