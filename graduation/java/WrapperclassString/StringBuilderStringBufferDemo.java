import java.io.*;
/*
----------------------------------------------------------------------------------
               String                    StringBuffer         StringBuilder
----------------------------------------------------------------------------------                
Storage Area | Constant String Pool      Heap                 Heap
Modifiable   | No (immutable)            Yes( mutable )       Yes( mutable )
Thread Safe  | Yes                       Yes                  No
Performance  | Fast                      Very slow            Fast
-----------------------------------------------------------------------------------
*/
public class StringBuilderStringBufferDemo{  
    public static void main(String[] args) throws IOException{  
        long startTime = System.currentTimeMillis();  
        StringBuffer sb = new StringBuffer("Java");  
        for (int i=0; i<1000000; i++){  
            sb.append("Tpoint");  
        }  
        System.out.println("Time taken by StringBuffer: " + (System.currentTimeMillis() - startTime) + "ms");  

        startTime = System.currentTimeMillis();  
        StringBuilder sb2 = new StringBuilder("Java");  
        for (int i=0; i<1000000; i++){  
            sb2.append("Tpoint");  
        }  
        System.out.println("Time taken by StringBuilder: " + (System.currentTimeMillis() - startTime) + "ms");  

        test(new StringBuffer("Java"));
        test(new StringBuilder("Java"));
    }  

    public static <T extends Appendable> void test(T sb)  throws IOException{
        long startTime = System.currentTimeMillis();
        T t = sb;
        for (int i=0; i<1000000; i++){
           // #System.out.println(t);
            t.append("Tpoint");
        }
        System.out.println("Time taken by " + t.getClass().getName() + ": "  + (System.currentTimeMillis() - startTime) + "ms");

    }

}
