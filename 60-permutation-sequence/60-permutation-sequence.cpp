class Solution {
public:
    string getPermutation(int n, int k) {
        int fact=1;
        vector<int> numbers; 
        string s="";
        for(int i=1;i<n;i++){
            fact = fact * i;
            numbers.push_back(i);
        }
         numbers.push_back(n);
        
        k = k-1;  // 0th based indexing    
        while(true){
            int idx = k / fact;   // 16 / 6 = 2
            s = s + to_string(numbers[idx]);  // add 2nd index of numbers vector to string s.
            numbers.erase(numbers.begin() + idx); // remove idx index from numbers vector.
            if(numbers.size() == 0) break;
            
            k = k % fact;  // 16 % 6 = 4
            fact = fact / numbers.size();  // 6 / 3 = 2           
        }
        return s;
    }
};