import java.util.Date;
import java.text.SimpleDateFormat; 
public class DateDemo {

   public static void main(String args[]) {
      // Instantiate a Date object
      Date date = new Date();
      // display time and date using toString()
      System.out.println("Current Date/time: " + date.toString());
      System.out.println(String.format("Current Date/Time: %tc", date ));
      date = new Date( );
      SimpleDateFormat ft = new SimpleDateFormat("E yyyy.MM.dd 'at' hh:mm:ss a zzz");
      System.out.println("Current Date/time: " + ft.format(date));
   }
}
