class Solution {
    public int countDaysTogether(String arriveAlice, String leaveAlice, String arriveBob, String leaveBob) {
        int[] monthDays = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        Pair<Integer,Integer> Aa = new Pair<>(Integer.parseInt(arriveAlice.split("-")[0]),Integer.parseInt(arriveAlice.split("-")[1]));
        Pair<Integer,Integer> Al = new Pair<>(Integer.parseInt(leaveAlice.split("-")[0]),Integer.parseInt(leaveAlice.split("-")[1]));
        Pair<Integer,Integer> Ba = new Pair<>(Integer.parseInt(arriveBob.split("-")[0]),Integer.parseInt(arriveBob.split("-")[1]));
        Pair<Integer,Integer> Bl = new Pair<>(Integer.parseInt(leaveBob.split("-")[0]),Integer.parseInt(leaveBob.split("-")[1]));

        if(Ba.getKey()<Aa.getKey() || (Ba.getKey()==Aa.getKey() && Ba.getValue()<Aa.getValue())){
            // System.out.println(Aa.getKey()+" " +Ba.getKey());
            return countDaysTogether(arriveBob,leaveBob,arriveAlice,leaveAlice);
        }
        if(Al.getKey()<Ba.getKey() || (Al.getKey()==Ba.getKey() && Al.getValue()<Ba.getValue())){
            return 0;
        }
        Pair<Integer,Integer> mini;
        if(Al.getKey()<Bl.getKey() || (Al.getKey()==Bl.getKey() && Al.getValue()<Bl.getValue())){
            mini = Al;
        }else{
            mini = Bl;
        }

        int sol = 0;
        if(Ba.getKey()==mini.getKey()){
            return mini.getValue()-Ba.getValue()+1;
        }else{
            int diff = mini.getKey()-Ba.getKey()-1;
            sol += (monthDays[Ba.getKey()]-Ba.getValue());
            for(int i=0;i<diff;i++){
                sol+=monthDays[Ba.getKey()+1+i];
            }
            sol+= mini.getValue();
        }

        return sol+1;
    }
}