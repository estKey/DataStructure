import java.text.DecimalFormat;
import java.util.Arrays;

public class Main {
    /**
     *
     * CISC 235
     * Assignment 1
     * 2018 Fall
     *
     */
    public static void main(String[] args) {
        int[] n = {100,200,300,400,500,600,700,800,900,1000};
        double[] avgHeight = new double[10];
        for (int i = 0; i < n.length; i++) {
            int[] HeightSet= new int[500];
            for (int trial = 0; trial < 500; trial++) {
                int[] KeySet = bstGenerator.setKeySet(n[i]);
                //System.out.println("Key Set" + (trial + 1) + ":");
                //bstGenerator.printKeySet(KeySet);
                bst tree = bstGenerator.bstConverter(KeySet);
                //bst.printBST(tree);
                HeightSet[trial] = bst.height(tree.root);
                System.out.print(HeightSet[trial]+" ");
            }
            System.out.println();
            avgHeight[i] = calculateAVG((HeightSet));
        }
        DecimalFormat df = new DecimalFormat("#.00");
        for (double anAvgHeight : avgHeight) System.out.println(df.format(anAvgHeight));
    }

    private static double calculateAVG(int[] HeightSet){
        int sum = 0;
        for (int aHeightSet : HeightSet) sum += aHeightSet;
        return (double)sum/HeightSet.length;
    }
}
