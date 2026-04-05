class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int l = 0; 
        int r = rows-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(matrix[mid][0]>target) r = mid-1;
            else if(matrix[mid][cols-1]<target) l = mid+1;
            else {
                int first = 0;
                int last = cols-1;
                while(first<=last){
                    int key = (first+last)/2;
                    if(matrix[mid][key]<target) first = key+1;
                    else if(matrix[mid][key]>target) last = key-1;
                    else return true;
                }
                return false;
            }
        }
return false;
    }
};
