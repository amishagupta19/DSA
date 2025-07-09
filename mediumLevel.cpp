#include<bits/stdc++.h>
using namespace std;

// Two sum
pair<int, int> twoSumBruteForce(vector<int> &arr, int n, int target){
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(arr[i] + arr[j] == target){
                return {i, j};
            }
        }
    }
    return {-1, -1};
}
vector<int> twoSumHashing(vector<int> &arr, int n, int target){
    map<int, int> mpp;
    for(int i = 0; i < n; i++){
        int a = arr[i];
        int moreReq = target - a;
        if(mpp.find(moreReq) != mpp.end()){
            return {mpp[moreReq], i};
        }
        mpp[a] = i;
    }
    return {-1, -1};
}
vector<int> twoSumOptimal(vector<int> &arr, int n, int target){
    int left = 0;
    int right = n - 1;
    sort(arr.begin(), arr.end());
    while(left <= right){
        int sum = arr[left] + arr[right];
        if(sum == target) return {arr[left], arr[right]};
        else if (sum < target) left++;
        else right++;
    }
    return {-1, -1};
}
// Sort an array of 0's, 1's and 2's
vector<int> dutchNationalFlagAlogo(vector<int> &arr, int n){
    int low = 0;
    int mid = 0;
    int high = n - 1;
    while(mid <= high){
        if(arr[mid] == 0){ 
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        } else if(arr[mid] == 1){
            mid++;
        } else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
    return arr;
}
// Majority Element : Element that occurs more than N/2 times in an array
int mooresVotingAlgorithm(vector<int> &arr, int n){
    int cnt = 0;
    int el;
    for(int i = 0; i < n; i++){
        if(cnt == 0){
            cnt = 1;
            el = arr[i];
        } else if(arr[i] == el) cnt++;
        else cnt--;
    }
    int cnt1 = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == el) cnt1++;
    }
    if(cnt1 > (n/2)) return el;
    return -1;
}
// Maximum subarray 
// for returning maximum sum
int kadanesAlgorithm(vector<int> &arr, int n){
    long long sum = 0;
    long long maxi = LONG_MIN;
    for(int i = 0; i < n; i++){
        sum += arr[i];
        if(sum > maxi) maxi = sum;
        if(sum < 0) sum = 0;
    }
    return maxi;
}
// for returning subarray with max sum
pair<int, int> kadanesAlgo(vector<int> &arr, int n){
    long long sum = 0;
    long long maxi = LONG_MIN;
    int start, ansStart, ansEnd;
    for(int i = 0; i < n; i++){
        if(sum == 0) start = i;
        sum += arr[i];
        if(sum > maxi){
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }
        if(sum < 0) sum = 0;
    }
    return {ansStart, ansEnd};
}
// rearrange array elements by sign
vector<int> rearrangeArray(vector<int> &arr, int n){
    vector<int> ans(n, 0);
    int posIndex = 0;
    int negIndex = 1;
    for(int i = 0; i < n; i++){
        if(arr[i] < 0){
            ans[negIndex] = arr[i];
            negIndex += 2;
        } else {
            ans[posIndex] = arr[i];
            posIndex += 2;
        }
    }
    return ans;
}



int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    // pair<int, int> res = twoSumBruteForce(arr, n, t);
    // if (res.first == -1) {
    //     cout << "No pair found\n";
    // } else {
    //     cout << res.first << " " << res.second << "\n";
    // }

    // pair<int, int> res = kadanesAlgo(arr, n);
    // for(int i = res.first; i < res.second; i++){
    //     cout << arr[i] << " ";
    // }

    vector<int> res = rearrangeArray(arr, n);
    for(int i = 0; i < n; i++){
        cout << res[i] << " ";
    }
    
}