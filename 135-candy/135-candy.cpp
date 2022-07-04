class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> vc(n,1);
        
        for(int i=1; i<n; i++){
            
            if(ratings[i] > ratings[i-1]){
                vc[i] = vc[i-1] + 1;
            }   
        }
        for(int i = n-2; i >= 0 ; i--){
            
            if(ratings[i] > ratings[i+1] && vc[i+1] >= vc[i]){
                vc[i] = vc[i+1] + 1;
            }
        }
        
        long long sum = 0;
        for(int i=0; i<vc.size(); i++){
           sum += vc[i] ;
        }
        
        for(int i=0; i<n; i++){
            cout<<ratings[i]<<" ";
        }
        
        cout<<"\n";
        for(int i=0; i<n; i++){
            cout<<vc[i]<<" ";
        }
        cout<<"\n";
        // accumulate(vc.begin(),vc.end(), sum);
        
        return sum;
    }
};