# C Programming Notes

## 1. "Hello World!"

This part is an introduction to get in touch with my notes. I tried to help a first-year beginner student from UNSW to understand some foundational properties in C programming. So there is nothing deeply and many questions remaining to solve in the following study voyage.

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

### 1.4 Why Do We Need the "stdio.h"?

### 1.5 What Is the "printf(...)"?

#### 1.5.1 An Inner Function in stdio.h

#### 1.5.2 What is the "\n"?

### 1.6 Main Function

#### 1.6.1 int ...

#### 1.6.2 ... main(void) ...

#### 1.6.3 "return 0;"