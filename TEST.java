// Addition program that displays the sum of two numbers.
import java.util.Scanner; // program uses class Scanner

public class Main
{
// main method begins execution of Java application
public static void main( String args[] )
{
// create Scanner to obtain input from command window
Scanner input = new Scanner( System.in );

int number1; // first number to add

while(1)
{
number1 = input.nextInt(); // read first number from user
if(number1!=42)
{
System.out.printf("%d\n",number1); // display sum
}
} 

}
} 
