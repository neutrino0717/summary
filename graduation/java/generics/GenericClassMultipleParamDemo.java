
class Entry<K, V> {
    private final K key;
    private final V value;
    public Entry(K key, V value) {  
        this.key = key;
        this.value = value;
    }
    public K getKey() {
        return key;
    }
    public V getValue() {
        return value;
    }
    public String toString() { 
        return "(" + key + ", " + value + ")";  
    }
}

public class GenericClassMultipleParamDemo {
    public static void main(String[] arg) {
        Entry<String, String> grade = new Entry<>("Mike", "A");
        Entry<String, Integer> mark = new Entry<>("Mike", 100);
      //Entry<String, String> grade = new Entry<String, String>("Mike", "A");
      //Entry<String, Integer> mark = new Entry<String, Integer>("Mike", 100);
        System.out.println("grade: " + grade);
        System.out.println("mark: " + mark);

        Entry<Integer, Boolean> prime = new Entry<>(13, true);
      //Entry<Integer, Boolean> prime = new Entry<Integer, Boolean>(13, true);
        if (prime.getValue()) System.out.println(prime.getKey() + " is prime.");
        else System.out.println(prime.getKey() + " is not prime."); 
    }
}
