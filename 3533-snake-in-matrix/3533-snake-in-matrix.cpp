class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int h = 0;
        int v = 0;
        for(int i = 0; i < commands.size();i++)
        {
            if (commands[i] == "RIGHT")
            {
                h++;
            }
            else if (commands[i] == "DOWN")
            {
                v++;
            }
            else if (commands[i] == "UP")
            {
                v--;
            }
            else if(commands[i] == "LEFT")
            {
                h--;
            }
        }
        return ((v * n) + h);
    }
};