import java.util.ArrayList;

import static java.lang.Math.abs;

abstract class DoubleHashing extends Hashing{

        private static int dh1(String data, int i)
        {
            return abs((h1(data) + h2(data) * i)% HashTable.table_size);
        }


        private static int dh2(String data, int i)
        {
            return abs((h1(data) + h3(data) * i)% HashTable.table_size);
        }


        private static int dh3(String data, int i)
        {
            return abs((h2(data) + h3(data) * i)% HashTable.table_size);
        }

        static void test1(ArrayList<String> CodeNames)
        {
            System.out.print("Test1 :");
            HashTable hashtable = new HashTable(HashTable.table_size);
            hashtable.init();
            for (String CodeName : CodeNames) {
                try {
                    //System.out.println("Try to Insert " + CodeName);
                    HashTable.DataItem item = new HashTable.DataItem(-1, CodeName);
                    for (int i = 1; i < 5; i++) {
                        int key = dh1(CodeName, i);
                        if (HashTable.hashtable[key] == HashTable.nonItem && key < HashTable.table_size) {
                            HashTable.hashtable[key] = item;
                            item.setKey(key);
                            HashTable.itemNum++;
                            break;
                        }
                        item.countStep();
                    }
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

        static void test2(ArrayList<String> CodeNames)
        {
            System.out.print("Test2: ");
            HashTable hashtable = new HashTable(HashTable.table_size);
            hashtable.init();
            for (String CodeName : CodeNames) {
                try {
                    //System.out.println("Try to Insert " + CodeName);

                    HashTable.DataItem item = new HashTable.DataItem(-1, CodeName);
                    for (int i = 1; i < 5; i++) {
                        int key = dh2(CodeName, i);
                        if (HashTable.hashtable[key] == HashTable.nonItem && key < HashTable.table_size) {
                            HashTable.hashtable[key] = item;
                            item.setKey(key);
                            HashTable.itemNum++;
                            break;
                        }
                        item.countStep();
                    }
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
                    HashTable.DataItem item = new HashTable.DataItem(-1, CodeName);
                    for (int i = 1; i < 5; i++) {
                        int key = dh3(CodeName, i);
                        if (HashTable.hashtable[key] == HashTable.nonItem && key < HashTable.table_size) {
                            HashTable.hashtable[key] = item;
                            item.setKey(key);
                            HashTable.itemNum++;
                            break;
                        }
                        item.countStep();
                    }
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