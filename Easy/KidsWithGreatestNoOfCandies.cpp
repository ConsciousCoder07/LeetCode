class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        
        //vector of size candies and all elements initialized to false
        vector<bool> a(candies.size(), false);
        
        //get maximum element of the vector
        int max = *max_element(candies.begin(), candies.end());
        
        for(int i=0; i < candies.size(); i++)
        {
            if(candies[i] >= max - extraCandies)
                a[i] = true;
        }
        return a;
    }
};