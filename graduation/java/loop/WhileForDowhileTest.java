public class WhileForDowhileTest {

   public static void main(String args[]) {
      int x = 10;
      while( x < 20 ) {
         System.out.print("value of x : " + x );
         x++;
         System.out.print("\n");
      }


      for(int y = 10; y < 20; y = y+1) {
         System.out.print("value of y : " + y );
         System.out.print("\n");
      }

      int z = 10;
      do{
         System.out.print("value of z : " + z );
         z++;
         System.out.print("\n");
      }while( z < 20 );
   }
}
