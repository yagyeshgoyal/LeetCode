class Solution {
public:
    int maxDiff(int num) {
        string temp = to_string(num);
        char c = '#';
        string temp2 = "";
        for(int i = 0; i<temp.size(); i++){
            if(temp[i] != '9'){
                c = temp[i];
                break;
            }
        }
        for(int i = 0; i<temp.size(); i++){
            if(temp[i] == c){
                temp2.push_back('9');
            }
            else{
                temp2.push_back(temp[i]);
            }
        }

        c = '#';
        string temp3 = "";
        for(int i = 0; i<temp.size(); i++){
            if(temp[i] != '1' && temp[i] != '0'){
                c = temp[i];
                break;
            }
        }
        for(int i = 0; i<temp.size(); i++){
            if(temp[i] == c && temp[0] != c){
                temp3.push_back('0');
            }
            else if(temp[i] == c){
                temp3.push_back('1');
            }
            else{
                temp3.push_back(temp[i]);
            }
        }
        int val = stoi(temp3);
        // if(val == 0){
        //     for(int i = 0; i<temp3.size(); i++){
        //         temp3[i] = '1';
        //     }
        // }
        // for(int i = 0; i<temp3.size(); i++){
        //     if(temp3[i] == '0'){
        //         temp3[i] = '1';
        //     }
        //     else{
        //         break;
        //     }
        // }
        int v = stoi(temp2) - stoi(temp3);

        return v;
    }
};