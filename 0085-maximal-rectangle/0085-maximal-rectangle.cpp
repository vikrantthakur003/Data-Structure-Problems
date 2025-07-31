#include<bits/stdc++.h>
class Solution {
public:
    vector<int> nextSmallerElement(vector<int> &arr, int n){
        
        vector<int> ans(n);
        stack<int> st;
        st.push(-1);
        
        for(int i = n - 1; i>= 0; i--){
            while(st.top() != -1 && arr[st.top()] >= arr[i]){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        
        return ans;
    }
    
    vector<int> previousSmallerElement(vector<int>&arr, int n){
        vector<int> ans(n);
        stack<int> st;
        st.push(-1);
        
        for(int i = 0; i<n; i++){
            while(st.top() != -1 && arr[st.top()] >= arr[i]){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    int getMaxArea(vector<int> &arr) {
        
        int n = arr.size();
        vector<int> next(n);
        next = nextSmallerElement(arr, n);
        
        vector<int> prev(n);
        prev = previousSmallerElement(arr, n);
        
        int area = INT_MIN;
        for(int i = 0; i<n; i++){
            int l = arr[i];
            
            if(next[i] == -1){
                next[i] = n;
            }
            
            int b = next[i] - prev[i] - 1;
            area = max(area, l*b);
        }
        
        return area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int>arr(m, 0);
        int maximumArea = 0;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(matrix[i][j] == '1'){
                    arr[j] += matrix[i][j] - '0';
                } else {
                    arr[j] = 0;
                }
            }

            int area = getMaxArea(arr);
            maximumArea = max(maximumArea, area);
        }

        return maximumArea;
    }
};