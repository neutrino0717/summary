/*
public static <Type> Entry<Type, Type> twice(Type value) {
    return new Entry<Type, Type>(value, value);
}
*/

public class GenericMethodDemo {
   // generic method printArray
   // E is a type parameter such as String, Double, Character
   public static < E > void printArray( E[] inputArray ) {
      // Display array elements
      for(E element : inputArray) {
         System.out.printf("%s ", element);
      }
      System.out.println();
   }

   public static void main(String args[]) {
      // Create arrays of Integer, Double and Character
      Integer[] intArray = { 1, 2, 3, 4, 5 };
      printArray(intArray);   // pass an Integer array

      Double[] doubleArray = { 1.1, 2.2, 3.3, 4.4 };
      printArray(doubleArray);   // pass a Double array

      Character[] charArray = { 'H', 'E', 'L', 'L', 'O' };
      printArray(charArray);   // pass a Character array
   }
}
