class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int l = 0;

        int whites = 0;
        
        for(int i = 0; i<k; i++){
            if(blocks[i]=='W') whites++;
        }

        int countW = whites;

        for(int r = k; r<blocks.length(); r++){
            
            if(blocks[l] == 'W') whites--; l++;
            
            if(blocks[r] == 'W') whites++;
            
            countW = min(countW, whites); 
        }
    return countW;
    }

};