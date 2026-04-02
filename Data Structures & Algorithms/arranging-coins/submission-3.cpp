class Solution {
public:
    int arrangeCoins(int n) {
        long l = 0; long r = n; 

        while(l<=r){
            long k = (l+r)/2;
            long fits = (k*(k+1))/2;

            if(fits>n) r = k -1 ;
            else if(fits<n) l = k + 1;
            else if (fits==n) return k;
        }
return r;
    //     for(int i = 0; i<=n;i++){
    //     if(fits>n) return i-1;
    //     else if(fits==n) return i;
    //     }
    }
};