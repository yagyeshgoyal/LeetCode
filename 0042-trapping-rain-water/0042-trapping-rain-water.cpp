class Solution {
public:
    int trap(vector<int>& height) {
        
        vector<int>maxiwall(height.size());
        stack<int>st;
        int r = -1;
        for(int i=height.size()-1; i>=0; i--){
            while(!st.empty()){
                if(height[i]>height[st.top()]){
                    r = st.top();
                    st.pop();
                }
                else{
                    break;
                }
            }

            if(st.size() == 0){
                maxiwall[i] = r;
            }
            else{
                maxiwall[i] = st.top();
            }

            st.push(i);
        }

       

        int ans = 0;

        int i = 0;
        while(i<height.size()){
            int k = maxiwall[i];
            

            if(k==-1){
                i++;
            }
            
            else if(height[i] > height[k]){
                for(int j=i+1; j<k; j++){
                    ans = ans + (height[k]-height[j]);
                }
                i = k;
            }
            else{
                for(int j=i+1; j<k; j++){
                    ans = ans + (height[i]-height[j]);
                }
                i = k;
            }
        }
        return ans;
    }
};