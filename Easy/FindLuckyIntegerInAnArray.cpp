class Solution {
public:
    int findLucky(vector<int>& arr) {
        
        unordered_map<int, int> mp;
        int maxElement = -1;
        int n = arr.size();
        
        for(auto itr: arr)
            mp[itr]++;
        
        for(auto itr: mp){
            
            if(itr.first==itr.second){
                maxElement = max(maxElement, itr.second);
            }
        }
        
        return maxElement;
    }
};