// Open Addressing HashTable

import java.text.DecimalFormat;
import java.util.stream.IntStream;

public class HashTable {
    private static final int DEFAULT_TABLE_SIZE = 4001; //33001
    static int table_size = DEFAULT_TABLE_SIZE;
    static DataItem[] hashtable;
    static DataItem nonItem;
    static int itemNum;


    static class DataItem
    {
        private int Key;
        private String Data;
        private int Step;

        DataItem(int key, String data)
        {
            Key = key;
            Data = data;
            Step = 0;
        }
        int getKey()
        { return Key; }
        void setKey(int key)
        { Key = key; }
        String getData()
        { return Data; }
        int getStep()
        { return Step; }
        void countStep()
        { Step++; }
    }

    HashTable(int size) {
        itemNum = 0;
        table_size = size;
        hashtable = new DataItem[table_size];
        nonItem = new DataItem(-1, null);
    }

    void init()
    {
        IntStream.range(0, table_size).forEachOrdered(i -> hashtable[i] = nonItem);
    }

    void setTable_size(int size)
    {
        table_size = size;
    }

    void printTable()
    {
        //System.out.println("Hash Table: ");
        //for(int i = 0; i < table_size; i++)
        {
            //if(hashtable[i] != nonItem){
                //System.out.print(" [Key: " + hashtable[i].getKey() + " Data: " + hashtable[i].getData() + " Step(s): " + hashtable[i].getStep() + "] ");
                //System.out.print(" [" + hashtable[i].getData() + "] ");
            //}
            // else
                //System.out.print(" [null] ");
        }
        //System.out.println("\nCollision Table: ");
        /*for(int i = 0; i < table_size; i++)
        {
            if (hashtable[i] != nonItem && hashtable[i].getStep() != 0)
                System.out.print(" [Step(s): " + hashtable[i].getStep() + "] ");

        }*/

        //System.out.println();
        DecimalFormat df = new DecimalFormat("#.00");
        System.out.println("Inserted Item Number: [" + itemNum + "], Load Factor: [%" + df.format(LoadFactor()) + "], Collisions: [" + CountCollisions() + "]");
    }

    private double LoadFactor() { return  ((((double)itemNum) /(double)table_size) * 100);}

    private int CountCollisions()
    {
        int collisions = 0;
        for(int i = 0; i < table_size; i++)
        {
            if (hashtable[i] != nonItem && hashtable[i].getStep() != 0)
                collisions += hashtable[i].getStep();
        }
        return collisions;
    }

    public boolean isFull() {
        return (itemNum == table_size);
    }

    private boolean  isEmpty() {
        return (itemNum != 0);
    }

    private static long strtoi(String data)
    {
        long sum;
        char[] a = data.toCharArray();
        sum = IntStream.range(0, data.length()).mapToLong(i -> (long) a[i]).sum();
        return sum;
    }

    DataItem deleteByKey(int key)
    {
        if(isEmpty())
        {
            if(hashtable[key].getKey() == key){
                DataItem del = hashtable[key];
                hashtable[key] = nonItem;
                return del;
            }
        }
        return null;
    }

    DataItem deleteByName(String name) // incomplete, since the function varies in different methods
    {
        if(isEmpty()) {
            int key = 0;
            if (hashtable[key].getKey() == key) {
                DataItem del = hashtable[key];
                hashtable[key] = nonItem;
                return del;
            }
        }
        return null;
    }

    DataItem searchByKey(int key)
    {
        if(isEmpty())
        {
            if(hashtable[key] != nonItem && hashtable[key].getKey() == key)
                return hashtable[key];
        }
        return null;
    }

    DataItem searchByName(String name) // incomplete
    {
        if(!isEmpty())
        {
            //if (hashtable[])
        }
        return null;
    }
}
