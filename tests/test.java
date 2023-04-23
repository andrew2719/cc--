import java.util.Scanner;
import java.util.TreeMap;
import java.util.Collections;

public class temp1 {
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        int t =sc.nextInt();
        sc.nextLine();
        while(t-- > 0){
            String s = sc.nextLine();
            TreeMap<Character,Integer> tm = new TreeMap<>(Collections.reverseOrder());
            for(int i=0;i<s.length();i++){
                if(tm.containsKey(s.charAt(i))){
                    tm.put(s.charAt(i),tm.get(s.charAt(i))+1);
                }else{
                    tm.put(s.charAt(i),1);
                }
            }
            int p = 0;
            int ret = 0;
            for(char c:tm.keySet()){
                if(p==0){
                    p = tm.get(c);
                    ret+=p;
                }
                else{
                    if(tm.get(c)<=p){
                        tm.put(c,p+1);
                        p++;
                        
                    }
                    else{
                        p = tm.get(c);
                    }
                    ret+=p;
                }
            }
            System.out.println(ret-s.length());
            
        }
        sc.close();
    }
}