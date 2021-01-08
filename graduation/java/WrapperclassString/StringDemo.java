//https://www.tutorialspoint.com/javaexamples/java_strings.htm
//todo
public class StringDemo{
   public static void main(String args[]){
      String str = "Hello World";
      String anotherString = "hello world";
      Object objStr = str;
      System.out.println( "--> compare: " );
      System.out.println( str.compareTo(anotherString) );
      System.out.println( str.compareToIgnoreCase(anotherString) );
      System.out.println( str.compareTo(objStr.toString()));

      System.out.println( "--> Search last occurence:" );
      String strOrig = "Hello world, Hello Reader";
      int lastIndex = strOrig.lastIndexOf("Hello");
      System.out.println(lastIndex);

      System.out.println( "--> Search substring:" );
      System.out.println( str.indexOf("Hello") );

      System.out.println( "--> get substring at position:");
      String str3 = "this-is-Java";
      System.out.println( str3.substring(0, 4) + str3.substring(8));

      System.out.println( "--> split:");
      String[] temp = str3.split("-");
      for(int i =0; i < temp.length ; i++){
         System.out.println(temp[i]);      
      }

      System.out.println( "--> replace:");
      System.out.println( str.replace( 'H','W' ) );
      System.out.println( str.replaceFirst("He", "Wa") );
      System.out.println( str.replaceAll("He", "Ha") );

      System.out.println( "--> reverse:");
      str = "Hello World";
      String reverse = new StringBuffer(str).reverse().toString();
      System.out.println( reverse );
   }
}
