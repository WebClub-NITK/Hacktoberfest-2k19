class Animal {
    public void eat() {
        System.out.println("I can eat");
    }
    public void sleep() {
        System.out.println("I can sleep");
    }
}

class Dog extends Animal {
    public void bark() {
        System.out.println("I can bark");
    }
}

class Relation {
    public static void main(String[] args) {
        Dog dog1 = new Dog();
        dog1.eat();
        dog1.sleep();
        dog1.bark();
    }
}