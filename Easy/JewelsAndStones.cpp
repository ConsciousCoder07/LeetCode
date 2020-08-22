class Solution {
public:
int numJewelsInStones(string J, string S) {
    
    int count = 0;
    for(auto ch : S)
    {
        int found = J.find(ch);
        if(found!=string::npos)
            count++;
    }
    return count;
    
}
};