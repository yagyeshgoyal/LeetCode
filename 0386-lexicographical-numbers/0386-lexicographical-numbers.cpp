class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int>v;

        for(int i=1; i<=9; i++){
            int temp1 = i;
            if(temp1>n){
                break;
            }
            else{
                v.push_back(temp1);
            }
            for(int j=0; j<=9; j++){
                int temp2 = temp1*10 + j;
                if(temp2>n){
                    break;
                }
                else{
                    v.push_back(temp2);
                }
                for(int k =0; k<=9; k++){
                   int temp3 = temp2*10 + k;
                    if(temp3>n){
                        break;
                    }
                    else{
                        v.push_back(temp3);
                    }
                    for(int l= 0; l<=9; l++){
                        int temp4 = temp3*10 + l;
                        if(temp4>n){
                            break;
                        }
                        else{
                            v.push_back(temp4);
                        }
                        for(int m= 0; m<=9; m++){
                            int temp5 = temp4*10 + m;
                            if(temp5>n){
                                break;
                            }
                            else{
                                v.push_back(temp5);
                            }
                        }
                    }
                }
            }
        }

        return v;
        
    }
};