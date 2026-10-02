class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        set<int> st;
        queue<int> q;
        st.insert(0);
        int n = rooms.size();
        for(auto &i:rooms[0]){
            if(st.find(i)==st.end()){
                st.insert(i);
                q.push(i);
            }
        }
        while(!q.empty()){
            for(auto &i:rooms[q.front()]){
                if(st.find(i)==st.end()){
                    st.insert(i);
                    q.push(i);
                }
            }
            q.pop();
        }
        return n==st.size();
    }
};