//while loop and for loop

import java.util.*;

public final class IteratorDemo {

  public static void main(String... aArguments) {
    List<String> flavours = new ArrayList<>();
    flavours.add("chocolate");
    flavours.add("strawberry");
    flavours.add("vanilla");
    useWhileLoop(flavours);
    useForLoop(flavours);
  }

  private static void useWhileLoop(Collection<String> aFlavours) {
    System.out.println("--> in while loop:");
    Iterator<String> flavoursIter = aFlavours.iterator();
    while (flavoursIter.hasNext()){
      System.out.println(flavoursIter.next());
    }
  }

  /**
  * Note that this for-loop does not use an integer index.
  */
  private static void useForLoop(Collection<String> aFlavours) {
    System.out.println("--> in for loop:");
    for (Iterator<String> flavoursIter = aFlavours.iterator(); flavoursIter.hasNext();){
      System.out.println(flavoursIter.next());
    }
  }
} 
