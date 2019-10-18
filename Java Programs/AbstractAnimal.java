abstract class Animals {
    public void displayInfo() {
        System.out.println("I am an animal.");
    }
}
class dog extends Animals {

}
class Relation2 {
    public static void main(String[] args) {
        dog d1 = new dog();
        d1.displayInfo();
    }
}