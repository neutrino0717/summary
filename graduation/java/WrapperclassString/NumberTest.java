public class NumberTest{ 

   public static void main(String args[]){
      Integer x = 5;
      // Returns byte primitive data type
      System.out.println( x.byteValue() );
      // Returns double primitive data type
      System.out.println(x.doubleValue());
      // Returns long primitive data type
      System.out.println( x.longValue() );      

      Integer y = 5;
      System.out.println(y.compareTo(3));
      System.out.println(y.compareTo(5));
      System.out.println(y.compareTo(8)); 

      System.out.println(x.equals(y));  

      Float a = Float.valueOf("80");               
      Integer b = Integer.valueOf(16);
      Double c = Double.valueOf(5);
      System.out.println(a);
      System.out.println(b);
      System.out.println(c);

      Integer d = 12;
      System.out.println(d.toString());  
      System.out.println(Integer.toString(12)); 

      int e =Integer.parseInt("9");
      double f = Double.parseDouble("5");
      //0x100 = 256
      int g = Integer.parseInt("100",16);

      System.out.println(e);
      System.out.println(f);
      System.out.println(g);
   }
}


