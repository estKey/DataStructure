/**
 *
 */
public class bstNode {
    private int key;
    private bstNode leftChild;
    private bstNode rightChild;

    private boolean isdel;

    private bstNode(int key, bstNode leftChild, bstNode rightChild){
        super();
        this.key = key;
        this.leftChild = leftChild;
        this.rightChild = rightChild;
    }

    bstNode(int key){
        this(key,null,null);
    }

    void setLeftChild(bstNode leftChild) {
        this.leftChild = leftChild;
    }

    bstNode getLeftChild(){
        return leftChild;
    }

    void setRightChild(bstNode rightChild) {
        this.rightChild = rightChild;
    }

    bstNode getRightChild() {
        return rightChild;
    }

    public void setIsdel(boolean isdel) {
        this.isdel = isdel;
    }

    public boolean isIsdel() {
        return isdel;
    }

    public void setKey(int key) {
        this.key = key;
    }

    int getKey() {
        return key;
    }
}
