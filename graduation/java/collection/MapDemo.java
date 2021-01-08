import java.util.*;
public class MapDemo {
   public static void elements(Map m) {
      System.out.println(m.getClass().getName());
      // Put elements to the map
      m.put("Zara", new Double(3434.34));
      m.put("Mahnaz", new Double(123.22));
      m.put("Ayan", new Double(1378.00));
      m.put("Daisy", new Double(99.22));
      m.put("Qadir", new Double(-19.08));
      
      // Get a set of the entries
      Set set = m.entrySet();
      
      // Get an iterator
      Iterator i = set.iterator();
      
      // Display elements
      while(i.hasNext()) {
         Map.Entry me = (Map.Entry)i.next();
         System.out.print(me.getKey() + ": ");
         System.out.println(me.getValue());
      }
      
      // Deposit 1000 into Zara's account
      double balance = ((Double)m.get("Zara")).doubleValue();
      m.put("Zara", new Double(balance + 1000));
      System.out.println("Zara's new balance: " + m.get("Zara"));
      System.out.println("\n");
   }
   public static void main(String args[]) {
       
      // Create a hash map
      HashMap hm = new HashMap();
      elements(hm); 

      LinkedHashMap lhm = new LinkedHashMap();
      elements(lhm);

      TreeMap tm = new TreeMap();
      elements(tm);
  }
}
