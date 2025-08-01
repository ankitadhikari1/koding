class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int>pq;
        pq.push(a);
        pq.push(b);
        pq.push(c);
        int score = 0;
        while(!pq.empty() && pq.size()!=1){
            int sc1 = pq.top()-1;
            pq.pop();
            int sc2 = pq.top()-1;
            pq.pop();
            score ++;
            if(sc1>0){
                pq.push(sc1);
            }
            if(sc2>0){
                pq.push(sc2);
            }
        }

        return score;

    }
};