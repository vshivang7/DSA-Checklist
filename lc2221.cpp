// You are given a 0-indexed integer array nums, where nums[i] is a digit between 0 and 9 (inclusive).
// The triangular sum of nums is the value of the only element present in nums after the following process terminates:
// Let nums comprise of n elements. If n == 1, end the process. Otherwise, create a new 0-indexed integer array newNums of length n - 1.
// For each index i, where 0 <= i < n - 1, assign the value of newNums[i] as (nums[i] + nums[i+1]) % 10, where % denotes modulo operator.
// Replace the array nums with newNums.
// Repeat the entire process starting from step 1.
// Return the triangular sum of nums.

#include<vector>
using namespace std;

// Approach 1:

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        vector<int> temp=nums;
        while(nums.size()>1){
            temp.clear();
            for(int i=1;i<nums.size();i++){
                temp.push_back((nums[i] + nums[i-1])%10);
            }
            nums=temp;
        }
        return nums[0];
    }
};

// Approach 2:

// #include <vector>

// using namespace std;

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        for (int size = n; size > 1; --size) {
            for (int i = 0; i < size - 1; ++i) {
                nums[i] = (nums[i] + nums[i + 1]) % 10;
            }
        }
        return nums[0];
    }
};