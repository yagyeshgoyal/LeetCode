class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        map<int,int>even;
        map<int,int>odd;
        int zero = 0;

        for(auto i : digits){
            if(i == 0){
                zero++;
            }
            else if(i&1){
                odd[i]++;
            }
            else{
                even[i]++;
            }
        }
        vector<int>ans;

        for(auto i : even){
            int a = i.first;
            int b = i.second;

            for(auto j : odd){

                for(auto k : odd){
                    int temp = 0;
                    temp = temp*10 + j.first;
                    if(j.first == k.first && j.second>=2){
                        
                        temp = temp * 10 + k.first;
                    }
                    else if(j.first != k.first){
                        
                        temp = temp *10  + k.first;
                    }

                    
                    temp = temp * 10 + a;

                    if(temp > 99){
                        ans.push_back(temp);
                    }
                }

                for(auto k : even){
                    int temp = 0;
                    temp = temp*10 + j.first;
                    if(i.first == k.first && i.second>=2){
                        
                        temp = temp * 10 + k.first;
                    }
                    else if(i.first != k.first){
                        
                        temp = temp * 10 + k.first;
                    }

                    
                    temp = temp * 10 + a;

                    if(temp > 99){
                        ans.push_back(temp);
                    }
                }

                if(zero>0){
                    int temp = 0;
                    temp = temp*10 + j.first;
                    
                    temp = temp * 10 + 0;
                    
                    temp = temp * 10 + a;
                    ans.push_back(temp);
                }

            }

            for(auto j : even){
                

                for(auto k : odd){
                    int temp = 0;
                    if(a == j.first && j.second >= 2)
                    temp = temp * 10 + j.first;
                    else if(a != j.first){
                        temp = temp * 10 + j.first;
                    }
                    
                    // temp.push_back(k.first);
                    temp = temp * 10 + k.first;
                    

                    // temp.push_back(a);
                    temp = temp * 10 + a;

                    if(temp > 99){
                        ans.push_back(temp);
                    }
                }

                for(auto k : even){
                    int temp = 0;
                    if(a == j.first && j.second >= 2)
                    temp = temp * 10 + j.first;
                    else if(a != j.first){
                        temp = temp * 10 + j.first;
                    }
                    if(i.first == k.first && i.second>=3 && a == j.first){
                        // temp.push_back(k.first);
                        temp = temp * 10 + k.first;
                    }
                    else if(i.first == k.first && k.second>=2 && a != j.first){
                        temp = temp * 10 + k.first;
                    }
                    else if(i.first != k.first && j.first == k.first && k.second>1){
                        // temp.push_back(k.first);
                        temp = temp * 10 + k.first;
                    }
                    else if(i.first != k.first && j.first != k.first){
                        // temp.push_back(k.first);
                        temp = temp * 10 + k.first;
                    }

                    // temp.push_back(a);
                    temp = temp * 10 + a;

                    if(temp > 99){
                        ans.push_back(temp);
                    }
                }

                if(zero>0){
                    int temp = 0;
                    if(a == j.first && j.second >= 2)
                    temp = temp * 10 + j.first;
                    else if(a != j.first){
                        temp = temp * 10 + j.first;
                    }
                    // temp.push_back('0');
                    temp = temp * 10 + 0;
                    // temp.push_back(a);
                    temp = temp * 10 + a;
                    if(temp>99)
                    ans.push_back(temp);
                }

            }
        }

        
        if(zero > 0){
            int a = 0;
            for(auto j : odd){
                
                // temp.push_back(j.first);

                for(auto k : odd){
                    int temp = 0;
                    temp = temp*10 + j.first;
                    if(j.first == k.first && j.second>=2){
                        // temp.push_back(k.first);
                        temp = temp * 10 + k.first;
                    }
                    else if(j.first != k.first){
                        // temp.push_back(k.first);
                        temp = temp *10  + k.first;
                    }

                    // temp.push_back(a);
                    temp = temp * 10 + a;

                    if(temp > 99){
                        ans.push_back(temp);
                    }
                }

                for(auto k : even){
                    int temp = 0;
                    temp = temp*10 + j.first;
                    if(a == k.first && zero>=2){
                        // temp.push_back(k.first);
                        temp = temp * 10 + k.first;
                    }
                    else if(a != k.first){
                        // temp.push_back(k.first);
                        temp = temp * 10 + k.first;
                    }

                    // temp.push_back(a);
                    temp = temp * 10 + a;

                    if(temp > 99){
                        ans.push_back(temp);
                    }
                }

                if(zero>1){
                    int temp = 0;
                    temp = temp*10 + j.first;
                    // temp.push_back('0');
                    temp = temp * 10 + 0;
                    // temp.push_back(a);
                    temp = temp * 10 + a;
                    ans.push_back(temp);
                }

            }

            for(auto j : even){
                

                for(auto k : odd){
                    int temp = 0;
                    // if(a == j.first && j.second >= 2)
                    temp = temp * 10 + j.first;
                    
                    // temp.push_back(k.first);
                    temp = temp * 10 + k.first;
                    

                    // temp.push_back(a);
                    temp = temp * 10 + a;

                    if(temp > 99){
                        ans.push_back(temp);
                    }
                }

                for(auto k : even){
                    int temp = 0;
                    
                    temp = temp * 10 + j.first;

                    if(j.first == k.first && j.second>=2){
                        // temp.push_back(k.first);
                        temp = temp * 10 + k.first;
                    }
                    else if(j.first != k.first){
                        // temp.push_back(k.first);
                        temp = temp * 10 + k.first;
                    }

                    // temp.push_back(a);
                    temp = temp * 10 + a;

                    if(temp > 99){
                        ans.push_back(temp);
                    }
                }

                if(zero>1){
                    int temp = 0;
                    
                    temp = temp * 10 + j.first;
                    // temp.push_back('0');
                    temp = temp * 10 + 0;
                    // temp.push_back(a);
                    temp = temp * 10 + a;
                    ans.push_back(temp);
                }

            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};