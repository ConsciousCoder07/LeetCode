class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        
        vector<int> a;
        int freq, val;
        
        for(int i=0; i<nums.size(); i+=2){
            
            freq = nums[i];
            val = nums[i+1];
            
            while(freq--)
                a.push_back(val);             
        }
        return a;
    }
};