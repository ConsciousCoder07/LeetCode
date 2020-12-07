# Problem Description
```
You are given an m x n integer grid accounts where accounts[i][j] is the amount of money the i​​​​​​​​​​​th​​​​ customer has in the j​​​​​​​​​​​th​​​​ bank. Return the wealth that the richest customer has.

A customer's wealth is the amount of money they have in all their bank accounts. The richest customer is the customer that has the maximum wealth.

Example:
Input: accounts = [[1,5],[7,3],[3,5]]
Output: 10
```


# Code

## C++
```c++
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int result = 0;
        for(int i = 0; i < accounts.size(); i++){
            int sum= 0;
            for(int j = 0; j < accounts[0].size(); j++){
                sum += accounts[i][j];
            }
            result = max(result, sum);
        }
        return result;
    }
};
```

## Python
```py
class Solution:
    def maximumWealth(self, accounts: List[List[int]]) -> int:
        return max(sum(account) for account in accounts)


class Solution:
    def maximumWealth(self, accounts: List[List[int]]) -> int:
        return max(map(sum, accounts))
```

