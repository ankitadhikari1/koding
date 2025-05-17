class Solution {
public:

    int func(int num){
        if(num<10)return num;
        int sum = 0;
        while(num){
            int r = num %10;
            sum+=r;
            num/=10;
        }
        return func(sum);

    }


    int addDigits(int num) {
        return func(num);
    }
};