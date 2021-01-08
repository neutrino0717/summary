public class CharacterTest {

   public static void main(String args[]){
      char ch = 'a';

      // Unicode for uppercase Greek omega character
      char uniChar = '\u039A'; 
      // an array of chars
      char[] charArray ={ 'a', 'b', 'c', 'd', 'e' }; 
      Character ch2 = new Character('a');

      // Here following primitive char 'a'
      // is boxed into the Character object ch
      Character ch3 = 'a';

      System.out.println(Character.isLetter('c'));
      System.out.println(Character.isLetter('5'));

      System.out.println(Character.isDigit('c'));
      System.out.println(Character.isDigit('5'));

      System.out.println(Character.isWhitespace('c'));
      System.out.println(Character.isWhitespace(' '));
      System.out.println(Character.isWhitespace('\n'));
      System.out.println(Character.isWhitespace('\t'));

      System.out.println( Character.isUpperCase('c'));
      System.out.println(Character.toUpperCase('c'));

      //to a one-character string.
      System.out.println(Character.toString('C'));

   }
}
