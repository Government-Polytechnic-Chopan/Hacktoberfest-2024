package Pattern_Printing;

public class Fibonacci_Triangle
{
    public static void printFibonacciTriangle(int n)
    {
        int a = 0, b = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                System.out.print(a + " ");
                int sum = a + b;
                a = b;
                b = sum;
            }
            System.out.println();
        }
    }

    public static void main(String[] args)
    {
        int n = 5;
        printFibonacciTriangle(n);
    }
}
