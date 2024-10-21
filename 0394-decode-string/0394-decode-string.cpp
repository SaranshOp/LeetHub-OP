class Solution {
public:
    string decodeString(string &s, int &index){
        string dstring;
        int num = 0;
        
        while(index < s.length()){
            char ch = s[index];
            
            if(isdigit(ch)){
                num = num * 10 + (ch - '0');
            }else if(ch == '['){
                index++;
                string nestedstring = decodeString(s, index);
                for(int i = 0; i < num; i++){
                    dstring += nestedstring;
                }
                num = 0;
            }else if(ch == ']'){
                return dstring;
            }else{
                dstring += ch;
            }
            index++;
        }
        return dstring;
    }
    string decodeString(string s) {
        int index = 0;
        return decodeString(s, index);
    }
};