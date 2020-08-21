class Solution {
public:
    string defangIPaddr(string address) {
        
        string defangedIP;
        for (auto i : address)
        {
            if( i == '.')
                defangedIP += "[.]";
            else
                defangedIP += i;
        }
        
        return defangedIP;
        
        //Alternative 
        
        /*
        
        for(int i=0; i<address.size(); i++)
        {
            if(address[i]=='.')
            {
                defangedIP.push_back('[');
                defangedIP.push_back('.');
                defangedIP.push_back(']');
            }
            else
                defangedIP.pushback(address[i]);    
        }
        
        */
    }
};