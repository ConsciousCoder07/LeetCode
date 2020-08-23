class Solution {
public:
    
    int countPrimes(int n){
        
      // Sieve of Eratosthene  
        bool isPrime[n+1];
        
        for(int i=2; i<n; i++) 
            isPrime[i] = true;
        
        //traverse only upto squareroot of the number and mark the multiples as false
        for(int i=2; i*i<=n; i++){
           
            if(isPrime[i])
            {
                 for(int j=i*i; j<n; j=j+i)
                     isPrime[j] = false;
            }
        }
        
        int count = 0;
        for(int i=2; i<n; i++){
            if(isPrime[i]) count++;
        }
        
        return count;
    } 
};


 /*
        ALTERNATIVE: It works great but sieve of eratosthene is best for this problem and less time consuming than this method
        
    int countPrimes(int n) {
        
        int count=0;
        for(int i=1; i<n; i++){
            if(isPrime(i))
                count++;            
        }  
        return count;
    }
    
    bool isPrime(int n){
        
        if(n<=1) return false;
        if(n==2 || n==3) return true;
        if(n%2==0 || n%3==0) return false;
        
        for(int i=5; i*i<=n; i+=6)
            if(n%i==0 || n%(i+2)==0)
                return false;
          
        return true;   
    }*/