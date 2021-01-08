import java.util.*;
public class SleepDemo {

   public static void main(String args[]) {
      try { 
         System.out.println(new Date( )); 
         System.out.println("sleep 3 seconds");
         Thread.sleep(3000); 
         System.out.println(new Date( )); 
      }catch (Exception e) {
         System.out.println("Got an exception!"); 
      }
   }
}
