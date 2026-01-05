class Solution {
public:
    int findContentChildren(vector<int>& Student, vector<int>& Cookie) {
       sort(Student.begin(),Student.end());
        sort(Cookie.begin(),Cookie.end());
        int cnt = 0;
        int i =0;
        int j = 0;
        int n = Student.size();
        int m = Cookie.size();
        while(i<n && j<m){
            if(Student[i]<=Cookie[j]){
                i++;
                j++;
                cnt++;
            }
            else{
                j++;
            }
        }

        return cnt;
    }
};