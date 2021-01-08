import java.util.*;
public class SetDemo {
   private static void elements(Set s) {
      // add elements to the set
      s.add("F");
      s.add("E");
      s.add("D");
      s.add("C");
      s.add("B");
      s.add("A");
   }
   public static void main(String args[]) {
      // create a hash set
      Set hs = new HashSet();
      elements(hs); 
      System.out.println(hs);

      Set lhs = new LinkedHashSet();
      elements(lhs);
      System.out.println(lhs);

      Set ts = new TreeSet();
      elements(ts);
      System.out.println(ts);
   }
}
