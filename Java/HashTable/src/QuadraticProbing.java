import java.util.ArrayList;

abstract class QuadraticProbing extends Hashing{

    private static int qp1(String name)
    {
        return h1(name)% HashTable.table_size;
    }

    private static int qp2(String name)
    {
        return h2(name)% HashTable.table_size;
    }

    private static int qp3(String name)
    {
        return Hashing.h3(name)% HashTable.table_size;
    }

    private static void insert(int key, int c, String data) {
        HashTable.DataItem item = new HashTable.DataItem(key, data);
        if(HashTable.hashtable[key] == HashTable.nonItem)
        {
            //System.out.println("Current Key: " + key);
            HashTable.hashtable[key] = item;
            HashTable.itemNum++;
        }else{
            for(int i = 1; i < 5; i++){
                item.countStep();
                key += c * i + ( 1 / c )*( i ^ 2);
                if(key < HashTable.table_size && HashTable.hashtable[key] == HashTable.nonItem){
                        HashTable.hashtable[key] = item;
                        item.setKey(key);
                        HashTable.itemNum++;
                        break;
                    }
                }
            }
    }


    static void test1(ArrayList<String> CodeNames)
    {
        System.out.print("Test1: ");
        HashTable hashtable = new HashTable(HashTable.table_size);
        hashtable.init();
        for (String CodeName : CodeNames) {
            try {
                insert(qp1(CodeName), 1,CodeName);
                //System.out.println("Insert " + CodeName);
                //if(HashTable.table_size <= HashTable.itemNum)
                {

                }
            } catch (Exception e) {
                //System.out.println("Failed to Insert " + CodeName);
                e.printStackTrace();
            }
        }
        hashtable.printTable();
    }

    static void test2(ArrayList<String> CodeNames)
    {
        System.out.print("Test2: ");
        HashTable hashtable = new HashTable(HashTable.table_size);
        hashtable.init();
        for (String CodeName : CodeNames) {
            try {
                //System.out.println("Try to Insert " + CodeName);
                insert(qp2(CodeName), 2, CodeName);
                if(HashTable.table_size <= HashTable.itemNum)
                {

                }
            } catch (Exception e) {
                //System.out.println("Failed to Insert " + CodeName);
                e.printStackTrace();
            }
        }
        hashtable.printTable();
    }

    static void test3(ArrayList<String> CodeNames)
    {
        System.out.print("Test3: ");
        HashTable hashtable = new HashTable(HashTable.table_size);
        hashtable.init();
        for (String CodeName : CodeNames) {
            try {
                //System.out.println("Try to Insert " + CodeName);
                insert(qp3(CodeName), 3,CodeName);
                if(HashTable.table_size <= HashTable.itemNum)
                {

                }
            } catch (Exception e) {
                //System.out.println("Failed to Insert " + CodeName);
                e.printStackTrace();
            }
        }
        hashtable.printTable();
    }

}
