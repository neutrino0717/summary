//package com.tutorialspoint;
import java.io.File;
import java.lang.reflect.Method;
public class FileDemo {
   
   public static void main(String[] args) {
      //File ff = new File("aaa");
      //Class c = ff.getClass();
      Class c = File.class;
      for (Method method : c.getDeclaredMethods()) {
            System.out.println(method.getName());
      }
      File f = null;
      String[] strs = {"test1.txt", "test2.txt"};
      try {
         // for each string in string array 
         for(String s:strs ) {
            // create new file
            f = new File(s);
            // true if the file is executable
            boolean bool = f.canExecute();
            // find the absolute path
            String a = f.getAbsolutePath(); 
            // prints
            System.out.println(a + " is executable: "+ bool);
         } 
      }catch(Exception e) {
         // if any I/O error occurs
         e.printStackTrace();
      }
   }
}
