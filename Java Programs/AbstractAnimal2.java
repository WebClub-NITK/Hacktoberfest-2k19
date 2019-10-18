abstract class Animals2 {
    abstract void makeSound();
    public void eat() {
        System.out.println("I can eat.");
    }
}

class dogs extends Animals2 {
    public void makeSound() {
        System.out.println("Bark bark");
    }
}

class Relation4 {
    public static void main(String[] args) {
        dogs d1 = new dogs();
        d1.makeSound();
        d1.eat();
    }
}