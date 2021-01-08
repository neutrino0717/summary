import java.util.*;
public class GregorianCalendarDemo {

   public static void main(String args[]) {
      String months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", 
         "Oct", "Nov", "Dec"};
      
      int second;
      // Create a Gregorian calendar initialized
      // with the current date and time in the
      // default locale and timezone.
      
      GregorianCalendar gcalendar = new GregorianCalendar();
      
      // Display current time and date information.
      System.out.println("Month: " + Calendar.MONTH);
      System.out.println("Month: " + gcalendar.get(Calendar.MONTH));
      System.out.println("Month: " + months[gcalendar.get(Calendar.MONTH)]);
      System.out.println("Date: " + gcalendar.get(Calendar.DATE));
      System.out.println("Year: " + gcalendar.get(Calendar.YEAR));
      System.out.println("Hour: " + gcalendar.get(Calendar.HOUR));
      System.out.println("Min: "  + gcalendar.get(Calendar.MINUTE));
      System.out.println("Sec: "  + (second = gcalendar.get(Calendar.SECOND)));
   }
}
