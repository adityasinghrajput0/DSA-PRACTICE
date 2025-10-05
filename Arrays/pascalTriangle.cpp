#include <iostream>
#include <vector>
using namespace std; 

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        int n=numRows;
        for (int i=0; i<n; i++) {
            vector<int> row;
            for (int j=0; j<=i; j++) {
                if (j==0 || j==i) {
                    row.push_back(1);
                }
                else {
                   int num=result[i-1][j-1]+result[i-1][j];
                   row.push_back(num);
                }
            }
            result.push_back(row);
        }
        return result;
    }
};