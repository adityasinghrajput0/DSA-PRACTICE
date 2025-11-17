#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include<algorithm>
using namespace std;

class Solution {
public:
    long long hoursTaken(vector<int>& arr,long long speed) {
        long long hours=0;
        for (int i=0; i<arr.size(); i++) {
            hours+=ceil((double)arr[i]/speed);
        }
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long ans=INT_MAX;
        long long low=1;
        long long high=*max_element(piles.begin(),piles.end());
        while (low<=high) {
            long long mid=(low+high)/2;
            long long hourstaken=hoursTaken(piles,mid);
            if (hourstaken>h) low=mid+1;
            else {
                ans=mid;
                high=mid-1;
            }
        }
        return (int)ans;
    }       
    
};