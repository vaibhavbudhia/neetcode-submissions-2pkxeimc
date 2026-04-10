class Solution {
public:
    bool isPerfectSquare(int num) {
     if (num==1) return true;

        int l = 0; int r = num;
     while(l<=r){
        long long mid = (l+r)/2;
        long long midSq = mid*mid;
        if(midSq>num) r = mid-1;
        else if(midSq<num) l = mid+1;
        else return true;
     }   
     return false;
    }
};