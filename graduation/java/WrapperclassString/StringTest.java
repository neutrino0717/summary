//A string is a representation of a char sequence but not a 'wrapper' of char[]. 
//It doesn't wrap one of the eight primitives, but I don't think it would hurt to call it this.
public class StringTest{

   public static void main(String args[]){
      char[] helloArray = { 'h', 'e', 'l', 'l', 'o', '.'};
      String helloString = new String(helloArray);  
      System.out.println( helloString );

      int len = helloString.length();
      System.out.println( "String Length is : " + len );
      System.out.println(helloString.charAt(1));

      System.out.println(helloString.compareTo("hello."));
      System.out.println(helloString.compareToIgnoreCase("Hello."));
   }
}
