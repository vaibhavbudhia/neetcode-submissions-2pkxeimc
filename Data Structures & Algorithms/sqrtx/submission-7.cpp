class Solution {
public:
    int mySqrt(int x) {
        if(x == 1) return 1;
        int l = 0; int r = x;
        int ans = 0;

        while(l<=r){
            long long mid = (l+r)/2;
            long long midSq = mid*mid;
            if(midSq>x) r = mid-1;
            else if(midSq<x) {ans = mid; l = mid+1;}
            else return mid;
        }
        return ans;
    }
};