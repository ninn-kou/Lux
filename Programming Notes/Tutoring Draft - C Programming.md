# C Programming Notes

## 1. "Hello World!"

This part is an introduction to get in touch with my notes. I tried to help a first-year beginner student from University of New South Wales to understand some foundational properties in C programming. So there is nothing deeply and many questions remaining to solve in the following study voyage.

TODO: Make sure here are some links to the following parts to explain knowledge we skip in Part 1, including
    - Preprocessor Directives
    - C Standard Libraries
    - Inner Functions
    - Type of Functions
    - ASCII Code
    - Basic Data Type
    - Return Value

### 1.1 Comments

For me, comments are my favourite part when I am writing codes. Not only for clearly reading but also for me as a proud. In C programming language, here are two ways to add your comment. Comments are used to add some sentences for the human being to understand what you think or how the code works. Besides, if we want parts of code not working temporarily, for example when we want to find the line caused the bug, we could comment them rather than delete them, unless you hate what you did.

1. `// ...`
2. `/* ... */`

The difference between these two methods is that the first one only comments to the end of its line; however, the second method would comment anything between `/*` and next `*/`. For multiple lines to comment, we could only use `/* ... */`, but for other circumstances, I recommend to use `// ...`, which is beneficial for your coding style.

### 1.2 The First C Program

Now, look at our first short executable program, and try to understand it line by line. Please put yourself as a computing scientist, not a beginner with coding. How does the compiler translate your codes to machine-readable binary codes?

```C
#include <stdio.h>
int main(void) {
    printf("Hello World!\n);
    return 0;
}
```

Here are only four lines. However, it is not an easy job to understand them 100 percent. I will try to put some self-thinking demonstration in the parts below.

### 1.3 \#include <...>

When you are writing an essay, you may need others' opinions or data to support your viewpoints. So you try to add some quotation into the article; However, if you use them, do not forget to put them on your reference list. In programming, here are some existed tools that had been written for use. For example, if you want to calculate square root for an integer, there is no need to pay attention into the complicated job, you need to do `sqrt(i)`, and then you can obtain the result you want.

However, where does the`sqrt()` function come from? How could your computer recognize this order? They are from another file called `math.h`, which is another C standard library. In conclusion, it just likes the hammer. If you tried to fix a broken table, raise your hammer on the nail, hit it. DO NOT TRY TO MAKE A HAMMER BY YOURSELF!

### 1.4 Why Do We Need the "stdio.h"?

### 1.5 What Is the "printf(...)"?

#### 1.5.1 An Inner Function in stdio.h

#### 1.5.2 What is the "\n"?

`\n` likes a mark to tell your computer that you need to print a new line here.

- `\r`: CR (Carriage Return) → Used as a new line character in Mac OS before X;
- `\n`: LF (Line Feed) → Used as a new line character in Unix/Mac OS X;
- `\r\n`: CR + LF → Used as a new line character in Windows.

### 1.6 Main Function

#### 1.6.1 `int main(void)`

#### 1.6.2 `return 0`

Here are two questions that might be confusing for beginners in C computing.

- 1. Why do we need a "return"?
- 2. Why the value we returned is "0"?

The answer to these two questions could be so easy but memorable. Here is a clear but detailed response to the first question: "Because the type of the main function is not `void`." Every function which is not a "void" **must** return at least one corresponding value type; definitely, the main function is also a function, so there has to be a `return` sentence.

However, for the second question, why do we return a unique number zero? Could we return 1, -1, 65535 or any other integer? The answer is you can, but the value you returned would not be a little effect to your program; because when the program executes the word "return" in the main function, the program will end.

Another exciting aspect is the definition of your functions. We could understand every function as a signal variable to its type. For example, look at the function below.

```C
// Calculate the distance between two points (row1, col1) and (row2, col2).
double distance(int row1, int col1, int row2, int col2) {
    int row_dist = row2 - row1;
    int col_dist = col2 - col1;
    return sqrt((row_dist * row_dist) + (col_dist * col_dist));
}
```

This is a part of my work in the first assignment for COMP1511, UNSW 19T3. No matter how many logic calculations I did in this function, it always returns a double type float number which shows the distance between two points. So to make the process of learning more comfortable, we could imagine a "magic double number", which would be changed automatically by the distance of two points.

```C
double distance = // Magic changing!;
```

Just like the explanation above, we could try to use a single data type when we are thinking, instead of a long and complicated function.

All in all, the question of the second question is very incredible. Because the main function is an `int` function, so computer scientists put a value '0' into it, just in case.

## 2. C Foundations

### 2.1 Basic Data Types

### 2.2 If Statements

```C
if (expression_1) {
    // Statements would be executed if the expression_1 is TRUE.
} else if (expression_2) {
    // Statements would be executed if the expression_1 is FALSE but the expression_2 is TRUE.
} else {
    // Statements would be executed if both the expression_1 and the expression_2 are FALSE.
}
```

### 2.3 Loop Statements

Here are two options if you need a loop: a `while` statement or a `for` statement. However, before I show the syntax of them, we need to know some basic properties of a loop. Most C programming cases, we need a variable "counter" to calculate the number we execute this loop, and by comparing the value of the counter and the condition to control statements. However, if there is another easy way to determine if the loop is required to continue, we definitely do not need the counter. One most important thing is if you used a counter, **DO NOT FORGET to operate it after each loop!** Otherwise, you might fall into the mire, which is a forever-running program. A `while` loop just like this:

```C
while (expression) {
    // Statements would be executed multiple times until the expression become FALSE.
    // Because of this, do not forget to do some operation to change your comparison.
    // Such as an `i++;` or an 'i--;` if the expression looks like the type `i < VALUE`.
}
```

In addition, when you try to use a `for` loop, be careful with what you wrote. The first part in the pair of brackets `()` is used to initialize the loop. You can declare a variable here, or just put a new value into an existed variable. The second part is a condition, just like what we do in the `while` part. And the last part is used to change the variable, an `i++;' is commonly appeared here. If you want to change several values at once, try to use a comma `,` to separate them.

```C
for (init; expression; increment) {
 // Do something repeat until the expression become FALSE.
}
```

**Hint: The symbol you used to separate these three parts is a `;` rather than a ','.**

### 2.4 Switch, `continue` And `break`

### 2.5 Struct

## 3. Functions in C Standard Libraries

## 4. Pointers and Addresses

### 4.1 A Pointer Example

To create a pointer, we need to **declare it with a \***. **Also, all pointers should be initialized with an address to any data or put it empty with a `NULL`.**

```C
int num = 65535;
int *pointer = &num;
printf("The value at %p is %d.\n", pointer, *pointer);
```

**Output on my MacBook Pro:**

```
The value at 0x7ffee3559928 is 65535.
```

### 4.2 Demonstrations

When we declare a pointer, we need a star mark '\*' to tell the computer that the variable is a pointer, which contains the address of the other variable we want. **After declaration**, the pointer variable without star `pointer` express the address, but the pointer with a star '*' `*pointer` define the value of the variable which was pointed to.

```C
// Pointer declaration.
// The '*' here means that the data "pointer" is a pointer to an integer (int value).
// The '&' here means the address of the variable.
int *pointer = &value.

// After declaration.
// "Pointer" is a variable which stores the address of another variable.
// The below printf function would print an address (0x7ffee3559928) in memory.
printf("%p\n", pointer);
```

Besides, we could know that the pointer aims to the same address with the original variable. If we could visit and change the content of the variable which was aimed at? Here is an example with a declared pointer.

```C
*pointer = 32767;
```

**Output on my MacBook Pro:**

```
The value at 0x7ffeeb706928 is 32767.
```

### 4.3 No Dangling Pointer

If the pointed object has been freed or deleted, but no change to the pointer itself, we caused a "dangling pointer". This is a dangerous behavior when computing because even the content changed, the address stayed here. We don't know what would be allocated into this address, and then, if we do anything to the pointer, something might be wrong.

Here are two tips to avoid this situation. The first one is, never leaves a pointer alone. When we declare it, it is better to link it with an address; but if there is not a suitable object for this pointer, we also need to put it as `NULL`. Otherwise, the pointer would point to an address randomly, and any operation is dangerous for this time.

Secondly, every pointer should be a `NULL` after using. It is beneficial, and it could avoid most memory leak errors by incorrect addresses.

## 5. Multiple Files and Arguments

```C
int main(int argc, char *argv[]) {
    return 0;
}
```

## 6. Arrays and Strings

Pointers and arrays are **similar** but **not same**. Just refer to *Chapter 4, Expert C Programming* by Peter van der Linden for more details.

```C
int array[][];
int *array[];
int **array;
```

## 7. Linked Lists

## 8. Two ADTs

### 8.1 Stacks

### 8.2 Queues
