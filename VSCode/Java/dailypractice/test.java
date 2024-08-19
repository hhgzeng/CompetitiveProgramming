
import java.util.Scanner;

class A {

    public void print() {
        System.out.println("Hello java!");
    }
}

class B {

    public int sum(int a, int b) {
        return a + b;
    }

    public int max(int a, int b) {
        return a > b ? a : b;
    }

}

public class test {

    public int sum(int a, int b) {
        return a + b;
    }

    public int max(int a, int b) {
        return a > b ? a : b;
    }

    public int min(int a, int b) {
        return a < b ? a : b;
    }


    public static void main(String []args) {

        int x, y;
        try (Scanner input = new Scanner(System.in)) {
            x = input.nextInt();
            y = input.nextInt();
        }

        test T = new test();

        System.out.println(T.sum(x, y));
        System.out.println(T.max(x, y));
        System.out.println(T.min(x, y));


        // A a = new A();
        // a.print();
        
        // B t = new B();
        // System.out.println(t.sum(x, y));
        // System.out.println(t.max(x, y));
    }
}
