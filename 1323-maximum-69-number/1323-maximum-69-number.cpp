class Solution {
public:
    int maximum69Number (int num) {
        
        string str = to_string(num);
        
        for(int i = 0 ; i < str.size() ; i++){
            if(str[i] == '6'){
                str[i] = '9'; break;
            }
        }
        
        num = stoi(str);
        
        return num;
//         int ans = num;
//         while(num){
//             int cur = num;
//             int ch = (char)(num%10);
//             num = num / 10;
            
            
//             if(cur > ans){
//                 ans = cur;
//             }
//         }
    }
};