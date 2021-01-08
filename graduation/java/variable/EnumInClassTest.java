class FreshJuice {
   //enums can be declared as their own or inside a class. 
   //Methods, variables, constructors can be defined inside enums as well.
   enum FreshJuiceSize{ SMALL, MEDIUM, LARGE }
   //var size's type is FreshJuiceSize
   FreshJuiceSize size;
}

public class EnumInClassTest {

   public static void main(String args[]){
      FreshJuice juice = new FreshJuice();
      juice.size = FreshJuice.FreshJuiceSize.MEDIUM ;
      System.out.println("Size: " + juice.size);

      for(FreshJuice.FreshJuiceSize f: FreshJuice.FreshJuiceSize.values()){
          System.out.println("The value is: " + f);
      }
   }
}
