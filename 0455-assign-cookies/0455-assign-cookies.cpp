class Solution {
public:
    int findContentChildren(vector<int>& Student, vector<int>& Cookie) {
        sort(Student.begin(),Student.end());
        sort(Cookie.begin(),Cookie.end());
        int count = 0;
        int n = Student.size();
        int m = Cookie.size();
        int i=0,j=0;
        while(i<n && j<m){
            if(Student[i]<=Cookie[j]){
                i++;
                j++;
                count++;
            }
            else{
                j++;
            }
        }
        return count;
    }
};