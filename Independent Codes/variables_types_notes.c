// Hao Ren
// z5237203@unsw.edu.au
// October 17, 2019
// A simple note to explain the main function, difference between int and double.

// Version 1.0  Notes created.  Need to add more variable types and change the
//              name, logic and structure more clear.

#include <stdio.h>  //This line is utlized to define function libraries.
int main(void) {    //This line is utlized to declare a main function.
                    //"int" means that the type of main function is integer,
                    //"main" means it is a main function (Every C program
                    //have one main function, the program runs line by line.
                    //"void" means that the function output nothing to program.

    int a = 5;      //The "int" here declares the type of varible "a", and
                    //"= 5" gives it a initial value which is 5.
    int b;          //"b" is also a int varible but has no initial value.
    double c = 8.5; //As same as above two lines but the type changed to "double"
    double d;       //"double" means the long float value

    int sum_of_integers;
    double sum_of_integer_lf;
    double sum_of_lfs;

    printf("Enter the number: \n");     //It is a output line to show to user
                                        //and "\n" means making a new line
    scanf("%d", &b);                    //"%d" reads the value after comma
                                        //and "&b" means to storage the value
                                        // which input by user in int varible b
    printf("Enter the LF number: \n");
    scanf("%lf", &d);                   //"%d" to the int varible
                                        //and "%lf" to the double varible

    sum_of_integers = a + b;            //gives the varible before "=" a new value
    sum_of_integer_lf = a + c;
    sum_of_lfs = c + d;

    if (sum_of_integer_lf == sum_of_lfs) {  //A simple statement
                                            //it would doing something in brace
                                            //if the condition is true
        printf("Equals.\n");
    } else {                                //if the condition is false, it
                                            //would runs the order in brace of
                                            //else statement.
        printf("Not Equals.\n");
    }

    printf("The sum of integers is %d.\n", sum_of_integers);
    printf("The sum of doubles is %lf.\n", sum_of_lfs);

    return 0;                           //The program obtains a return value
                                        //which is 0, and it means the main
                                        //function end with nothing output
}
