import java.util.*;
class Employee {
 
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
 
}

class EmployeeSortByName implements Comparator<Employee>{
    public int compare(Employee e1, Employee e2) {
        return e1.Ename.compareTo(e2.Ename);
    }
}

class EmployeeSortBySalary implements Comparator<Employee>{
    public int compare(Employee e1, Employee e2) {
        if (e1.Sal == e2.Sal) return 0;
        else if (e1.Sal > e2.Sal)  return 1;
        else return -1;
    }
}

public class ComparatorDemo{
 
    public static void main(String[] args) {
        //List sort
        System.out.println("-->List sort by salary:");
        List ts1 = new ArrayList();
        ts1.add(new Employee ("Tom",40000.00));
        ts1.add(new Employee ("Harry",20000.00));
        ts1.add(new Employee ("Maggie",50000.00));
        ts1.add(new Employee ("Chris",70000.00));
        Collections.sort(ts1, new EmployeeSortBySalary());
        Iterator itr = ts1.iterator();
        while(itr.hasNext()){
            Object element = itr.next();
            System.out.println(element + "\n");
        }
        //Array sort
        System.out.println("-->Array sort by salary:");
        Employee[] empArr = new Employee[4];
        empArr[0] = new Employee("Tom",40000.00);
        empArr[1] = new Employee("Harry",20000.00);
        empArr[2] = new Employee("Maggie",50000.00);
        empArr[3] = new Employee("Chris",70000.00);
        Arrays.sort(empArr, new EmployeeSortBySalary());
        //System.out.println(Arrays.toString(empArr));
        for (int i=0; i<empArr.length; i++) {
            System.out.println(empArr[i] + "\n");
        }

        //sort by salary
        System.out.println("-->list sort by name:");
        Collections.sort(ts1, new EmployeeSortByName());
        for(itr = ts1.iterator(); itr.hasNext();) System.out.println(itr.next() + "\n");
        System.out.println("-->Array sort by name:");
        Arrays.sort(empArr, new EmployeeSortByName());
        for (Employee e: empArr) System.out.println(e + "\n");
    }
}
