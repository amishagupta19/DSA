#include<bits/stdc++.h>
using namespace std;

int largest(vector<int> &arr, int n){
  int max = arr[0];
  for(int i = 0; i < n; i++){
    if(arr[i] > max){
      max = arr[i]; 
    }
  }
  return max;
}
int secondlargest(vector<int> &arr, int n){
  int maxi = largest(arr, n);
  int smax = -1;
  for(int i = 0; i < n; i++){
    if(arr[i] > smax && arr[i] != maxi){
      smax = arr[i];
    }
  }
  return smax;
}
int seclargest(vector<int> &arr, int n){
  int largest = arr[0];
  int secondlargest = -1;
  for(int i = 0; i < n; i++){
    if(arr[i] > largest){
      secondlargest = largest;
      largest = arr[i];
    } 
    else if (arr[i] < largest && arr[i] > secondlargest ){
      secondlargest = arr[i];
    }
  }
  return secondlargest;
}
int isSorted(vector<int> &arr, int n){
  for(int i = 1; i < n; i++){
    if(arr[i] >= arr[i-1]){
      
    }else{
      return false;
    }
    return true;
  }
}
int removeDuplicates(vector<int> &arr, int n){
     set<int> st;
     for(int i = 0; i < n; i++){
      st.insert(arr[i]);
     }
     int index = 0;
     for(auto it: st){
      arr[index] = it;
      index++;
     }

     return index;
}
int removeDuplicatesOptimal(vector<int> &arr, int n){
  int i = 0;
  for(int j = 1; j < n; j++){
    if(arr[i] != arr[j]){
      arr[i+1] = arr[j];
      i++;
    }
  }
  return i + 1;
}
int leftrotatebyOnePlace(vector<int> &arr, int n){
  int temp = arr[0];
  for(int i = 1; i < n; i++){
    arr[i - 1] = arr[i];
  }
  arr[n - 1] = temp;
  return n;
}
void reverse(vector<int> &arr, int start, int end){
  while(start <= end){
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    start++;
    end--;
  }
}
int leftRotateByDplaces(vector<int> &arr, int n, int d){
  d = d % n;
  reverse(arr, 0, d-1);
  reverse(arr, d, n-1);
  reverse(arr, 0, n-1);
  return n;
}
int moveZeroes(vector<int> &arr, int n){
  int j = -1;
  for(int i = 0; i < n; i++){
    if(arr[i] == 0){
      j = i;
      break;
    }
  }
  if( j == -1) return false;
  for(int i = j+1; i < n; i++){
    if(arr[i] != 0){
      swap(arr[i], arr[j]);
      j++;
    }
  }
  return n;
}
vector<int> unionUsingSet(vector<int> &a1, vector<int> &a2, int n1, int n2){
  set<int> st;
  vector<int> Union;

  for(int i = 0; i < n1; i++){
    st.insert(a1[i]);
  }
  for(int i = 0; i < n2; i++){
    st.insert(a2[i]);
  }
  for (auto & it: st)
    Union.push_back(it);

  return Union;
}
vector<int> Union(vector<int> &a1, vector<int> &a2, int n1, int n2){
  int i = 0; 
  int j = 0;
  vector<int> unionArr;
  while(i < n1 && j < n2){
    if(a1[i] <= a2[j]){
      if(unionArr.size() == 0 || unionArr.back() != a1[i]){
        unionArr.push_back(a1[i]);
      }
      i++;
    } else {
      if(unionArr.size() == 0 || unionArr.back() != a2[j]){
        unionArr.push_back(a2[j]);
      }
      j++;
    }
  }
  while(i < n1){
    if(unionArr.size() == 0 || unionArr.back() != a1[i]){
      unionArr.push_back(a1[i]);
    }
    i++;
  }
  while(j < n2){
    if(unionArr.size() == 0 || unionArr.back() != a2[j]){
      unionArr.push_back(a2[j]);
    }
    j++;
  }
  return unionArr;
}
int findMissingNumber(vector<int> &arr, int n){
  int sum = (n*(n+1)) / 2;
  int sumArr = 0;
  int missingNum;
  for(int i = 0; i < n - 1; i++){
    sumArr += arr[i];
  }
  missingNum = sum - sumArr;
  return missingNum;
}
int findMissingNumUsingXorr(vector<int> &arr, int n){
  int xor1 = 0;
  int xor2 = 0;
  int N = n - 1;
  for(int i = 0; i < N; i++){
    xor2 = xor2 ^ arr[i];
    xor1 = xor1 ^ (i+1);
  }
  xor1 = xor1 ^ n;
  int res = xor1 ^ xor2;
  return res;
}
int findMaxConscOnes(vector<int> &arr, int n){
  int cnt = 0, maxi = 0;
  for(int i = 0; i < n; i++){
    if(arr[i] == 1){
      cnt++;
      maxi = max(cnt, maxi);
    } else {
      cnt = 0;
    }
  }
  return maxi;
}




int main(){
  int n;
  cin >> n;
  vector<int> arr(n);
  for(int i = 0; i < n - 1; i++){
    cin >> arr[i];
  }
  // int res = moveZeroes(arr, n);
  // for(int i = 0; i < res; i++){
  //   cout << arr[i] << " ";
  // }

  // int n1, n2;
  // cin >> n1 >> n2;
  // vector<int> a1(n1), a2(n2);
  // for(int i = 0; i < n1; i++){
  //   cin >> a1[i];
  // }
  // for(int i = 0; i < n2; i++){
  //   cin >> a2[i];
  // }
  // vector<int> res = Union(a1, a2, n1, n2);
  // for (auto &val: res)
  //   cout << val << " ";
  int res = findMaxConscOnes(arr, n);
  cout << res;
}
