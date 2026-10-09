
class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        int need = 0;

        for (char c : s) {
            if (c == '(') {
                
                if (need % 2 == 1) {
                    ans++;
                    need--;
                }

                need += 2;
            } 
            else {
                need--;

                if (need < 0) {
                    ans++;
                    need = 1;
                }
            }
        }

        return ans + need;
    }
};


//   ( ) ) ( ( ) ) ) )
// 0 2 1 0 2 4 3 2 1 0

//   ( ( ) ) )
// 0 2 4 3 2 1

//   )   )  (  )  )  (
// 0 -1 -2  2  1  0  2

//   ( ( ) ) ) ( ) ) )
// 0 2 4 3 2 1 2 1 0 -1

//   ( ( ( ) ) ) ( ) ) ) -> ((   )   ) -> im -> ) gra
// 0 2 4 6 5 4 3 2 1 0 -1

//   ( ( ) ( ) ) )
// 0 2 4 3 2 1 0 1