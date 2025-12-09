#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//Return Pair in sorted array with targeted sum


/////brute force
/*
vector<int>pairSum(vector<int>arr, int target){
    vector<int>ans;
    int n = arr.size();
    for(int i=0; i<n; i++){
        for(int j =i+1; j<n; j++){
            if(arr[i]+arr[j]==target){
                ans.push_back(arr[i]);
                ans.push_back(arr[j]);
                return ans;
            }
        }
    }
    return ans;
}
*/
//////OPTIMISED
vector<int>pairSum(vector<int>arr, int target){
    vector<int>ans;
    int n = arr.size();
    int i =0, j =n-1;
    while(i < j){
        int pairSum = arr[i]+arr[j];
        if(pairSum < target){
            i++;
        }else if(pairSum > target){
            j--;
        }else{
            ans.push_back(arr[i]);
            ans.push_back(arr[j]);
            return ans;
        }
    }
    return ans;
}
int main(){
    vector<int>arr = {1,2,3,4,5,6,7,8,9,10};
    int target = 9;
    vector<int>ans = pairSum(arr,target);
    if(ans.size() == 2) {
        cout << ans[0] << "," << ans[1] << endl;
    } else {
        cout << "No pair found\n";
    }
    return 0;
}