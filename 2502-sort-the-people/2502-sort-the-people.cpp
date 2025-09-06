class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<int> idx(names.size());
        iota(idx.begin(), idx.end(), 0); 

        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return heights[a] > heights[b]; 
        });

        vector<string> result;
        for (int i : idx) result.push_back(names[i]);
        return result;
    }
};
