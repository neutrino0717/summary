public class IfBreakContinue {

   public static void main(String args[]) {
      int [] numbers = {10, 20, 30, 40, 50};
      for(int x : numbers ) {
         if( x == 30 ) {
	      break;
         }
         System.out.print( "x = " + x );
         System.out.print("\n");
      }


      for(int y : numbers ) {
         if( y == 30 ) {
	      continue;
         }
         System.out.print( "y == " + y );
         System.out.print("\n");
      }
   }
}
