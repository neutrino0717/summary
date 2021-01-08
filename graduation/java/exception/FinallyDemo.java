public class FinallyDemo {
   public static void main(String[] argv) {
      new FinallyDemo().doTheWork();
   }
   public void doTheWork() {
      Object o = null;
      for (int i=0; i<5; i++) {
         try {
            o = makeObj(i);
         }
         catch (IllegalArgumentException e) {
            System.err.println
            ("Error: ("+ e.getMessage()+").");
            return;   
         }
         finally {
            System.err.println("All done with " + i);
            if (o==null)
            System.exit(0);
        }
        System.out.println("Obj created:" + o); 
      }
   }

   public Object makeObj(int type)  throws IllegalArgumentException {
      if (type == 4)  
      throw new IllegalArgumentException
      ("Don't like type " + type);
      return new Object();
   }
}
