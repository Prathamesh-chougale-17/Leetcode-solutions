class Solution {
public:
    vector<int> brute(vector<int> &temp){
        vector<int> sol;
        int n = temp.size();
        for(int i=0;i<n;i++){
            int maxi = 0;
            for(int j=i;j<n;j++){
                if(temp[j]>temp[i]){
                    maxi = j-i;
                    break;
                }
            }
            sol.push_back(maxi);
        }
        return sol;
    }
    vector<int> op(vector<int> &temp){
        int n = temp.size();
        vector<int> sol(n);
        stack<int> st;
        for(int i=0;i<n-1;i++){
            if(temp[i]<temp[i+1]){
                sol[i] = 1;
                while(!st.empty() && temp[i+1]>temp[st.top()]){
                    sol[st.top()]=i-st.top()+1;
                    st.pop();
                }
            }else{
                st.push(i);
            }
        }
        return sol;
    }
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        return op(temperatures);
    }
};