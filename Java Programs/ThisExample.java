class ThisExample {
    int x;
    int y;
    ThisExample(int x, int y) {
        this.x = x;
        this.y = y;
        System.out.println("Before passing this to addTwo() method:");
        System.out.println("x = " + this.x + ", y = " + this.y);
        addTwo(this);
        System.out.println("After passing this to addTwo() method:");
        System.out.println("x = " + this.x + ", y = " + this.y);
    }
    void addTwo(ThisExample o){
        o.x += 2;
        o.y += 2;
    }
}
class Demo {
    public static void main( String[] args ) {
        ThisExample obj = new ThisExample(1, -2);
    }
}