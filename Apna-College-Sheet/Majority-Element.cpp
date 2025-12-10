#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
-----------------------------------------------------------
Problem: Majority Element
-----------------------------------------------------------
Given an array nums of size n, return the majority element.
The majority element is the element that appears more than n/2 times.

You may assume that the majority element always exists.
*/

/* [O(n^2)]
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            int count = 0;
            for(int j=0; j<nums.size(); j++){
                if(nums[i]==nums[j]){
                    count++;
                }
            }
            if(count > nums.size()/2){
                return nums[i];
            }else{
                continue;
            }
        }
        return -1;
    }
};
*/

//OPTIMISED [O(nlog n)]
/*
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n =nums.size();
        //sort
        sort(nums.begin(),nums.end());
        int freq = 1,ans = nums[0];
        for(int i =1; i<n; i++){
            if(nums[i]==nums[i-1]){
                freq++;
            }else{
                freq = 1;
                ans = nums[i];  //make current element as majority element
            }
            if(freq > n/2){
                return nums[i];
            }
        }
        return ans;
    }
};
*/

//Moor's Voting [O(n)]
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n =nums.size();
        int freq = 0, ans = 0;
        for(int i=0; i<n; i++){
            if(freq == 0){
                ans = nums[i];
            }
            if(ans == nums[i]){
                freq++;
            }else{
                freq--;
            }
        }
        return ans;
    }
};
int main(){
    Solution solution;
    vector<int>arr = {1,2,3,4,5,1,1,1,4,1,1,1};
    int ans = solution.majorityElement(arr);
    cout<<"Majority Element is: "<< ans<<endl;
    return 0;
}