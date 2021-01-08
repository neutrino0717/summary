import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class MatchDuplicateWord {
   public static void main(String args[]) 
   throws Exception {
      String duplicatePattern = "\\b(\\w+) \\1\\b";
      Pattern p = Pattern.compile(duplicatePattern);
      int matches = 0;
      String phrase = "this is real real";
      Matcher m = p.matcher(phrase);
      String val = null;
      while (m.find()) {
         val = ":" + m.group() + ":";
         matches++;
      }
      System.out.println(val);
   }
}
