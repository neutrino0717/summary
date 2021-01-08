import java.util.*;
public class GenericMethodWildcardDemo {
    public static void main (String[] args){
        printMax(23,43,1);
        System.out.println("max printed in main: " + returnMax(23,43,1));
    }
    public static <T extends Comparable<T>> void printMax(T a, T b, T c){
        T m = a;
        if(b.compareTo(m)>0) m = b;
        if(c.compareTo(m)>0) m = c;
        System.out.println("max printed in function: " + m);
    }

    public static <T extends Comparable<T>> T returnMax(T a, T b, T c){
    //           ~~~~~~~~~~~~~~~~~~~~~~~~~  ~~ ~~~~~~~~~~~~~~~~~~~~~~~
    //       T must be comparable subclass  |           |
    //                                      |            \-function name and arguments
    //                                       \-return type
        T m = a;
        if(b.compareTo(m)>0) m = b;
        if(c.compareTo(m)>0) m = c;
        return m;
    }
    
}
