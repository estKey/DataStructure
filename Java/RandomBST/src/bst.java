/**
 *
 * @ClassName:
 * @Discription:
 *
 */
public class bst {
    bstNode root;

    public void setRoot(bstNode root) {
        this.root = root;
    }

    public bstNode getRoot() {
        return root;
    }

    static void insert(bst tree, int key){
        bstNode newNode = new bstNode(key);

        if(tree.root == null){
            tree.root = newNode;
            tree.root.setLeftChild(null);
            tree.root.setRightChild(null);
        }
        else{
            bstNode current = tree.root;
            bstNode parent;
            while(true){
                parent = current;
                if(newNode.getKey()>current.getKey()){
                    current = current.getRightChild();
                    if(current==null){
                        parent.setRightChild(newNode);
                        return;
                    }
                }
                else {
                    current = current.getLeftChild();
                    if(current == null){
                        parent.setLeftChild(newNode);
                        return;
                    }
                }
            }
        }
    }

    static void printBST(bst tree){
        if(tree.root == null) System.out.println("EMPTY TREE");
        else{
            preorder(tree.root);
            System.out.println();
        }
    }

    private static void preorder(bstNode root){
        if(root == null) return;
        System.out.print(root.getKey()+" ");
        preorder(root.getLeftChild());
        preorder(root.getRightChild());
    }

    static int height(bstNode root){
        if(root == null) return 0;
        int leftHeight = height(root.getLeftChild());
        int rightHeight = height(root.getRightChild());
        return (leftHeight>rightHeight?leftHeight:rightHeight)+1;
    }

    @Override
    public boolean equals(Object obj) {
        return super.equals(obj);
    }
}
