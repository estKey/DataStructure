import java.util.Random;

public class bstGenerator {

    private static int getRandomNumberInRange(int max) {
        Random r = new Random();
        return r.ints(1, (max + 1)).findFirst().getAsInt();
    }

    static int[] setKeySet(int n){
        int[] keyset = new int[n];
        for(int i = 0; i < n; i++){
            keyset[i] = getRandomNumberInRange(n);
        }
        return keyset;
    }

    public static void printKeySet(int[] keyset){
        for (int aKeyset : keyset) {
            System.out.print(aKeyset+" ");
        }
        System.out.println();
    }

    static bst bstConverter(int[] keyset){
        bst new_tree = new bst();
        for (int aKeyset : keyset) {
            bst.insert(new_tree, aKeyset);
        }
        //bst.printBST(new_tree);
        return new_tree;
    }

}
