import java.util.*;
class Employee implements Comparable {
 
    int EmpID;
    String Ename;
    double Sal;
    static int i;
 
    public Employee() {
        EmpID = i++;
        Ename = "dont know";
        Sal = 0.0;
    }
 
    public Employee(String ename, double sal) {
        EmpID = i++;
        Ename = ename;
        Sal = sal;
    }
 
    public String toString() {
        return "EmpID " + EmpID + "\n" + "Ename " + Ename + "\n" + "Sal " + Sal;
    }
 
    public int compareTo(Object o1) {
        if (this.Sal == ((Employee) o1).Sal) return 0;
        else if ((this.Sal) > ((Employee) o1).Sal) return 1;
        else return -1;
    }
}

public class ComparableTypeDemo{
 
    public static void main(String[] args) {
        //List sort
        System.out.println("-->List sort by salary:");
        List<Employee> ts1 = new ArrayList<>();
        ts1.add(new Employee ("Tom",40000.00));
        ts1.add(new Employee ("Harry",20000.00));
        ts1.add(new Employee ("Maggie",50000.00));
        ts1.add(new Employee ("Chris",70000.00));
        Collections.sort(ts1);
        Iterator<Employee> itr = ts1.iterator();
        while(itr.hasNext()){
            Employee element = itr.next();
            System.out.println(element + "\n");
        }
        //Array sort
        System.out.println("-->Array sort by salary:");
        Employee[] empArr = new Employee[4];
        empArr[0] = new Employee("Tom",40000.00);
        empArr[1] = new Employee("Harry",20000.00);
        empArr[2] = new Employee("Maggie",50000.00);
        empArr[3] = new Employee("Chris",70000.00);
        Arrays.sort(empArr);
        //System.out.println(Arrays.toString(empArr));
        for (int i=0; i<empArr.length; i++) {
            System.out.println(empArr[i] + "\n");
        }
 
    }
}
