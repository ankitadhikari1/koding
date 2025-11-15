class Solution {
public:
    int myAtoi(string s) {
    
        int output=0; 
        int len = s.size(); 
        int neg = false;

        if (len ==0 )
            return 0; 

        int idx = 0;
        while (idx < len && s[idx] == ' '){
            idx++;
        }

        if (idx < len){
            if (s[idx] == '-'){
                neg = true; 
                idx++;
            } else if ( s[idx] == '+'){
                idx++;
            }
        }

        while (idx < len && isdigit(s[idx])){
            int digit = s[idx] - '0';

            if (output > INT_MAX /10 || output == INT_MAX/10 && digit > 7){
                return neg ? INT_MIN : INT_MAX;
            }

            output = output * 10 + digit; 
            idx++;
        }

        if (neg)
            output = -output; 

        return output;
    }
};