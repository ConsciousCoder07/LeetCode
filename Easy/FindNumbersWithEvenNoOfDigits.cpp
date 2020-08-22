class Solution {
public:
    int findNumbers(vector<int>& nums) {
        
        int count = 0;
        
        for(int i=0; i<nums.size(); i++)
        {
            //Method 1: digits = floor(log10(n))+1
            nums[i]=floor(log10(nums[i]))+1;
            
            /* 
                
               Method 2: Using to_string()
            
               string str = to_string(nums[i]);
               nums[i] = str.size();   
               
               Method 3: Conventional way
               
               while(n!=0)
               {
                 n = n/10;
                 digits++;
               } 
              
              
             */
               
        }
        
        for(auto n : nums)
        {
            if(n%2==0)
                count++;
        }
        
        
        return count;
    }
};