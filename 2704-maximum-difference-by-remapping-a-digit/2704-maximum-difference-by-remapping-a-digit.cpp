class Solution {
public:
    int minMaxDifference(int num) {
        string temp = to_string(num);
        string temp2 = to_string(num);
        char v = 'k';

        for(int i = 0; i<temp.size(); i++){
            if(v=='k' && temp[i] != '9'){
                v = temp[i];
                temp[i] = '9';
                
            }
            else if(temp[i] == v){
                temp[i] = '9';
               
            }
        }
        v= 'k';
        for(int i = 0; i<temp.size(); i++){
            if(v=='k' && temp2[i] != '0'){
                v = temp2[i];
                temp2[i] = '0';
                
            }
            else if(temp2[i] == v){
                temp2[i] = '0';
               
            }
        }

        int num1 = stoi(temp);
        int num2 = stoi(temp2);

        cout<<num1<<endl;
        cout<<num2<<endl;

        return num1 - num2;

        
    }
};