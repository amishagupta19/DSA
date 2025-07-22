#include<bits/stdc++.h>
using namespace std;

int totalHours(vector<int> &arr, int hrs){
    int totalhrs = 0;
    for(int i = 0; i < arr.size(); i++){
        totalhrs += ceil((double)arr[i] / (double)hrs);
    }
    return totalhrs;
}
int kokoEatingBananas(vector<int> &arr, int h){
    int n = arr.size();
    int high = *max_element(arr.begin(), arr.end());
    int low = 1;
    int ans = INT_MAX;
    while(low <= high){
        int mid = (low + high) / 2;
        int totalhrs = totalHours(arr, mid);
        if(totalhrs <= h){
            ans = mid; 
            high = mid - 1;
        } else
            low = mid + 1;
    }
    return ans;
}

int main(){
    int n, h;
    cin >> n >> h;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    } 

    int res = kokoEatingBananas(arr, h);
    cout << res;
}