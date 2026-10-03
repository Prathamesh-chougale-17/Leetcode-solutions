use std::collections::{HashSet, VecDeque};

impl Solution {
    pub fn can_visit_all_rooms(rooms: Vec<Vec<i32>>) -> bool {
        let n = rooms.len();

        let mut st: HashSet<i32> = HashSet::new();
        let mut q: VecDeque<i32> = VecDeque::new();

        st.insert(0);

        for &key in &rooms[0] {
            if !st.contains(&key) {
                st.insert(key);
                q.push_back(key);
            }
        }

        while let Some(room) = q.pop_front() {
            for &key in &rooms[room as usize] {
                if !st.contains(&key) {
                    st.insert(key);
                    q.push_back(key);
                }
            }
        }

        st.len() == n
    }
}