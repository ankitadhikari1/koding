struct Node{
    Node * links[2];

    bool contains(int bit){
        return (links[bit]!=NULL);
    }

    Node * get(int bit){
        return links[bit];
    }

    void put(int bit, Node * node){
        links[bit] = node;
    }
};

class Trie{
    private:
    Node * root;

    public:


        Trie(){
            root = new Node();
        }

        void insert(int num){
            Node * node = root;

            for(int i=31;i>=0;i--){
                int bit = (num>>i) & 1;
                if(!node->contains(bit)){
                    node->put(bit,new Node());
                }
                node = node->get(bit);
            }

        }

        int getMax(int num){
            Node * node = root;
            int Max = 0;
            for(int i=31;i>=0;i--){
                int bit = (num>>i) & 1;
                if(node->contains(1-bit)){
                    Max = Max | (1<<i);
                    node = node->get(1-bit);
                }
                else{
                    node = node->get(bit);
                }
            }
            return Max;
        }
};





class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie trie;

        sort(nums.begin(),nums.end());

        vector<pair<int,pair<int,int>>>oq;

        for(int i=0;i<queries.size();i++){
            int mi = queries[i][1];
            int xi = queries[i][0];
            int ind = i;
            oq.push_back({mi,{xi,ind}});
        }

        sort(oq.begin(),oq.end());

        vector<int>ans(queries.size());

        int ind = 0;
        
        for(int i=0;i<oq.size();i++){
            int mi = oq[i].first;
            int xi = oq[i].second.first;
            int idx = oq[i].second.second;

            while(ind < nums.size() && nums[ind] <= mi) {
                trie.insert(nums[ind]);
                ind++;
            }


            if(ind==0)ans[idx]=-1;
            else ans[idx] = trie.getMax(xi);



        }


        return ans;
    }
};