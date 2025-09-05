class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string>st(bank.begin(),bank.end());
        queue<pair<string,int>>q;
        q.push({startGene,0});
        char arr[] = {'A','C','G','T'};
        while(!q.empty()){
            string node = q.front().first;
            int step = q.front().second;
            q.pop();
            if(node == endGene)return step;
            for(int i=0;i<node.size();i++){
                char org = node[i];
                for(int j=0;j<4;j++){
                    node[i] = arr[j];
                    if(st.count(node)){
                        q.push({node,step+1});
                        st.erase(node);
                    }
                }
                node[i] = org;
            }
        }
        return -1;
    }
};