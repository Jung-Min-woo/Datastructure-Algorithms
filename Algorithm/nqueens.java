class nqueens{
    public static void main(String[] args) {
        
    }
}
class Checkerboard{
    private final int size;
    private final boolean[][] elem;
    //Constructor
    Checkerboard(){ 
        size = 2;
        elem = new boolean[size][size];
    }
    Checkerboard(int size) {
        this.size = size;
        elem = new boolean[size][size];
    }
    void solveNqueens(){
        //try1
        for(int i = 0; i < size ; i++){

        }

    }
    public boolean checkColumn(Position criterion){
        int x = criterion.getX();
        int y = criterion.getY();
        if(this.elem[x][y] 
        return true;
    }
}
class Position{
    private int x, y;
    Position(){
        x = 0;
        y = 0;
    }
    Position(int x, int y){
        this.x = 0;
        this.y = 0;
    }
    public int getX() {
        return x;
    }
    public int getY() {
        return y;
    }
    public void setX(int x) {
        this.x = x;
    }
    public void setY(int y) {
        this.y = y;
    }
}