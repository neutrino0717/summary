abstract class Employee {
   private String name;
   private String address;
   private int salary;

   public Employee(String name, String address, int salary) {
      System.out.println("Constructing an Employee");
      this.name = name;
      this.address = address;
      this.salary = salary;
   }   
   public abstract int computePay();
   // Remainder of class definition
   public int getSalary(){
      return salary;
   }
}

/* File name : Salary.java */
class Salary extends Employee {
   public Salary(String name, String address, int salary) {
      super(name,address,salary);
   }

   public int computePay() {
      return getSalary()*12;
   }
   // Remainder of class definition
}

/* File name : AbstractDemo.java */
public class AbstractDemo {

   public static void main(String [] args) {
      Salary s = new Salary("John Adams", "Boston, MA", 9999);
      Employee e = new Salary("John Adams", "Boston, MA", 9999);
      System.out.println("salary: " + s.computePay());
      System.out.println("salary: " + e.computePay());
   }
}
