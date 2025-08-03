/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int n = employees.size();
        unordered_map<int,vector<int>>mp;
        unordered_map<int,int>Importance(n);
        for(auto & it : employees){
            mp[it->id]=it->subordinates;
            Importance[it->id] = it->importance;
        }

        int total = 0;
        queue<int>q;
        q.push(id);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            total+=Importance[node];
            for(auto & it : mp[node]){
                q.push(it);
            }
        }

        return total;
    }
};