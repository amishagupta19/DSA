#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &arr, int target){
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] == target) return mid;
        if(arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
int lowerBound(vector<int> &arr, int target){
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int lb = n;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] >= target){
            lb = mid;
            high = mid - 1;
        } else 
            low = mid + 1;
    }
    return lb;
}
int upperBound(vector<int> &arr, int target){
     int n = arr.size();
    int low = 0;
    int high = n - 1;
    int ub = n;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] > target){
            ub = mid;
            high = mid - 1;
        } else 
            low = mid + 1;
    }
    return ub;
}
//searchInsertPosition = lowerBound
//ceil = lowerBound
int floor(vector<int> &arr, int target){
    int low = 0;
    int high = arr.size() - 1;
    int ans = -1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] <= target){
            ans = mid;
            low = mid + 1;
        } else
            high = mid - 1;
    }
    return ans;
}
int firstOcc(vector<int> &arr, int target){
    int n = arr.size();
    int low = 0, high = n - 1, first = -1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] == target){
            first = mid;
            high = mid - 1;
        } else if(arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return first;
}
int lastOcc(vector<int> &arr, int target){
    int n = arr.size();
    int low = 0, high = n - 1, last = -1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] == target){
            last = mid;
            low = mid + 1;
        } else if(arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return last;
}
pair<int, int> firstandlastOcc(vector<int> &arr, int target){
    int n = arr.size();
    int first = firstOcc(arr, target);
    int last = lastOcc(arr, target);
    if(first == -1) return {-1, -1};
    else return {first, last};
}
// Count occurrences of a number in a sorted array with duplicates
//(lastOcc - firstOcc + 1)

//Search Element in Rotated Sorted Array - I (contains only unique elements)
int searchUnique(vector<int> &arr, int target){
    int low = 0, high = arr.size() - 1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] == target) return mid;

        if(arr[low] <= arr[mid]){
            if(arr[low] <= target && target <= arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        } else {
            if(arr[mid] <= target && target <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}
//Search Element in Rotated Sorted Araay = II (contains duplicate elements as well)
int searchDup(vector<int> &arr, int target){
    int low = 0, high = arr.size() - 1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] == target) return mid;
        if(arr[low] == arr[mid] && arr[mid] == arr[high]){
            low ++, high --;
            continue;
        }
        if(arr[low] <= arr[mid]){
            if(arr[low] <= target && target <= arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        } else {
            if(arr[mid] <= target && target <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}
int findMinInRotatedSortedArray(vector<int> &arr, int n){
    int low = 0, high = n - 1, ans = INT_MAX;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[low] <= arr[high]){
            ans = min(ans, arr[low]);
            break;
        }
        if(arr[low] <= arr[mid]){
            ans = min(ans, arr[low]);
            low = mid + 1;
        } else {
            ans = min(ans, arr[mid]);
            high = mid - 1;
        }
    }
    return ans;
}
// find out how many times array has been rotated - find out the minimum in a rotated sorted array and return its index
int singleElementInSortedArray(vector<int> &arr, int n){
    if(n == 1) return arr[0];
    if(arr[0] != arr[1]) return arr[0];
    if(arr[n - 1] != arr[n - 2]) return arr[n - 1];
    int low = 1, high = n - 2;
    while(low <= high){
        int mid = (low + high) / 2;

        if((arr[mid] != arr[mid - 1]) && (arr[mid] != arr[mid + 1]))
            return arr[mid];
        if((mid % 2 == 1 && arr[mid] == arr[mid - 1]) || (mid % 2 == 0 && arr[mid] == arr[mid + 1]))
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
int findPeakElement(vector<int>& nums, int n){
    if(n == 1) return 0;
    if(nums[0] > nums[1]) return 0;
    if(nums[n-1] > nums[n - 2]) return n - 1;

   int low = 1, high = n - 2;
    while(low <= high){
        int mid = (low + high) / 2;
        if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])
            return mid;
        if(nums[mid] < nums[mid + 1])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main(){
    int n;
    cin >> n;
    // int target;
    // cin >> target;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int res = findPeakElement(arr, n);
    cout << res;
}