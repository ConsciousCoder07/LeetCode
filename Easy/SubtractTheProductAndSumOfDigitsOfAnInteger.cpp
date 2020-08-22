class Solution {
public:
    int subtractProductAndSum(int n) {
        
        int digit, sum = 0, product = 1;
        
        while(n!=0)
        {
            digit = n%10;
            sum += digit;
            product *= digit;
            n /= 10;     
        }
        
        return (product-sum);
    }
};