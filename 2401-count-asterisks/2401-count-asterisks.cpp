class Solution {
public:
    int countAsterisks(string s) {
        int length = s.length();
        int count = 0;      
        int counter = 0;    
        
        for (int i = 0; i < length; i++) {
            if (s[i] == '|') {
                counter++;
            } 
            else if (s[i] == '*' && counter % 2 == 0) {
                count++;
            }
        }
        
        return count;
    }
};