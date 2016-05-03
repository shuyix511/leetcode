import java.io.*;
import java.util.*;

public class MyHashtable<K, V> {    
    public static void main(String args[]) throws Exception {
        new TestHarness(new MyHashtable<String, String>()).run();
    }

    private static final int FILLINGRATE = 2;
    
    private static class Entry<K, V> {
		private K key;
		private V value;

		public Entry(K key, V value) {
			this.key = key;
			this.value = value;
		}

		public void setValue(V value) {
			this.value = value;
		}

		public V getValue() {
			return this.value;
		}

		public K getKey() {
			return this.key;
		}
	}

	private int capacity = 128;
	private int size = 0;
	private ArrayList<LinkedList<Entry<K, V>>> array;

	public MyHashtable() {
		this.array = new ArrayList<>();
		for (int i = 0; i < this.capacity; i++) {
			array.add(new LinkedList<Entry<K, V>>());
		}
	}
    
    public void put(K key, V value) {

      if (key == null) {
	        throw new NullPointerException("key cannot be null!");
	  }
	  
	  if (this.size == this.capacity * FILLINGRATE) {
			rehash();
	  }

      int index = (key.hashCode() & (0x7FFFFFFF)) % this.capacity;
		Entry<K, V> entry = new Entry<>(key, value);

		for (Entry<K, V> e : this.array.get(index))
			if (e.getKey() == null || e.getKey().equals(entry.getKey())) {
				e.setValue(entry.getValue());
				return;
			}

			this.array.get(index).add(entry);
			this.size++;
    }

    public V get(K key) {
    	if (key == null) {
	        throw new NullPointerException("key cannot be null!");
	    }
        int index = (key.hashCode() & (0x7FFFFFFF)) % this.capacity;

		LinkedList<Entry<K, V>> bucket = array.get(index);
	    Iterator<Entry<K, V>> iterator = bucket.iterator();
	    while (iterator.hasNext()) {
	    	Entry<K, V> entry = iterator.next();
	        if (entry.getKey().equals(key)) {
	            return entry.getValue();
	        }
	    }
	    return null;
    }

    private void rehash() {
		this.size = 0;
		this.capacity *= 2;

		ArrayList<LinkedList<Entry<K, V>>> newArray = new ArrayList<>();
		for (int i = 0; i < this.capacity; i++) {
			array.add(new LinkedList<Entry<K, V>>());
		}

		ArrayList<LinkedList<Entry<K, V>>> oldArray = new ArrayList<>(this.array);
		this.array = newArray;

		for (LinkedList<Entry<K, V>> entries : oldArray)
			for (Entry<K, V> entry : entries)
				put(entry.getKey(), entry.getValue());

	}

    /**
     * A helper class that tests MyHashtable by feeding it puts and gets from STDIN.
     */
    public static class TestHarness implements Runnable {
        final MyHashtable<String, String> hashtable;

        public TestHarness(MyHashtable<String, String> hashtable) {
            this.hashtable = hashtable;
        }

        public void run() {
            Scanner scanner = new Scanner(System.in);
            while (scanner.hasNext()) {
                String k = scanner.next();
                String v = null;
                if (k.contains("=")) {
                    String[] split = k.split("\\=");
                    k = split[0];
                    v = split[1];
                }
                if (v == null) {
                    System.out.println(hashtable.get(k));
                } else {
                    hashtable.put(k, v);
                }
            }
        }
    }
}