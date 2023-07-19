import java.io.*;

// Base class
class Animal {
    String name;

    Animal(String name) {
        this.name = name;
    }

    void makeSound() {
        System.out.println("Generic animal sound");
    }
}

// Derived class
class Dog extends Animal {
    Dog(String name) {
        super(name);
    }

    @Override
    void makeSound() {
        System.out.println("Woof! Woof!");
    }
}

// Interface
interface Flyable {
    void fly();
}

// Another derived class implementing the interface
class Bird extends Animal implements Flyable {
    Bird(String name) {
        super(name);
    }

    @Override
    void makeSound() {
        System.out.println("Tweet! Tweet!");
    }

    @Override
    public void fly() {
        System.out.println(name);
        System.out.println(": is flying.");
    }
}

public class maluco {
    public static void main(String[] args) {
        Dog dog = new Dog("Buddy");
        Bird bird = new Bird("Sparrow");

        System.out.println("---- Animals making sounds ----");
        dog.makeSound();
        bird.makeSound();

        System.out.println("\n---- Animals flying ----");
        bird.fly();
    }
}
