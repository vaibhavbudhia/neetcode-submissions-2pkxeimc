class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> records;
    int top;
        for(int i = 0; i< operations.size(); i++){
            if(operations[i]=="+"){
                top = records.back();
                records.pop_back();
                int addition = top + records.back();

                records.push_back(top); 
                records.push_back(addition); 
            }
            
            else if(operations[i]=="D"){
                records.push_back(2 * records.back()); 
            }
                        
            else if(operations[i]=="C"){
                records.pop_back();
            }
            
            else {records.push_back(stoi(operations[i]));}
        }

        return accumulate(records.begin(), records.end(), 0);
    }
};