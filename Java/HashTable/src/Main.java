//Main
/*
   Open Addressing Methods Test
 */

import java.util.ArrayList;

public class Main extends HashTable {

    Main(int size) {
        super(size);
    }

    public static void main(String[] args) {
	    // System.out.println(HashTable.hash("abc"));
        int num = 4000;
        String filepath = "src\\HOTNCU_potential_codenames_2018F.txt";
        ArrayList<String> CodeNames = proc.getNameCodes(filepath, num);
        System.out.println("Double Hashing");
        DoubleHashing.test1(CodeNames);
        DoubleHashing.test2(CodeNames);
        DoubleHashing.test3(CodeNames);
        System.out.println("\nQuadratic Probing");
        QuadraticProbing.test1(CodeNames);
        QuadraticProbing.test2(CodeNames);
        QuadraticProbing.test3(CodeNames);
    }
}

