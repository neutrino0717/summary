//T is type parameter
public class GenericClassDemo<T> {
   private T t;

   public void add(T t) {
      this.t = t;
   }

   public T get() {
      return t;
   }

   public static void main(String[] args) {
      //T is replaced by a Class 
      GenericClassDemo<Integer> iDemo = new GenericClassDemo<Integer>();
      GenericClassDemo<String> sDemo = new GenericClassDemo<String>();
    
      iDemo.add(new Integer(10));
      sDemo.add(new String("Hello World"));

      System.out.printf("Integer Value :%d\n\n", iDemo.get());
      System.out.printf("String Value :%s\n", sDemo.get());
   }
}
