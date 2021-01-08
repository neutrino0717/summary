public class ConstructorPuppy{

   public ConstructorPuppy(String name){
      // This constructor has one parameter, name.
      System.out.println("Passed Name is :" + name ); 
   }
   
   public static void main(String []args){
      // Following statement would create an object myConstructorPuppy
      ConstructorPuppy myPuppy = new ConstructorPuppy( "tommy" );
   }
}
