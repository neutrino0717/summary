class Vehicle {}

public class InstanceofCar extends Vehicle {
   public static void main(String args[]){
      Vehicle a = new InstanceofCar();
      boolean result1 =  a instanceof InstanceofCar;
      boolean result2 =  a instanceof Vehicle;
      System.out.println( result1 );
      System.out.println( result2 );

      // following will return true since name is type of String
      String name = "James";
      boolean result3 = name instanceof String;  
      System.out.println( result3 );
   }
}
