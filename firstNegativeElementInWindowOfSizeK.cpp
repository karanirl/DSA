//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        
     //step 1> check each element if it is negative if yes, push it into a 
     // step 2>> once window size is achieved we will return an answer, 
     // step3>> check if the storing list is empty or not if empty return 0
     // if not return first element of list
     // step4>> before sliding the window, we will check if the first element of the 
     // negative list is the i'th element which is going to be out of window if incremented
     // if yes then, remove the first elemnt from list and slide the window
     vector<int> answer;
     list<int> negative;
     int i=0;
     int j=0;
     int n=arr.size();
     while(j<n){
         if(arr[j]<0){
             negative.push_back(arr[j]);
         }
         if(j-i+1<k){
             j++;
         }
         else if(j-i+1==k){
             if(negative.size()==0){
                 answer.push_back(0);
             }
             else{
                 answer.push_back(negative.front());
                 if(arr[i]==negative.front()){
                 negative.pop_front();// if condition is inside this else block because 
                 // so that we do not try to access negative.front when it is empty.
                 
             }
             }
             
             i++;
             j++;
         }
     }
     return answer;
}
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.firstNegInt(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
