## Base Projects Diary

### 1. Bin2Dec

- [Readme Document](https://github.com/flying-yogurt/Lux/blob/master/My%20Base%20Projects/Bin2Dec/Bin2Dec-App.md)
- [Codes in C](https://github.com/flying-yogurt/Lux/blob/master/My%20Base%20Projects/Bin2Dec/Bin2Dec.c)

#### 1.1 Aim

Read a string-type binary number and output a decimal number in command line. $$\text{Input}_{2} = \text{Output}_{10}$$.

**Example:**

```
Input: 10101010
Output: Binary : 10101010
 Reverse: 01010101
 Decimal: 170
```

#### 1.2 Ideas

In mathematics we use the follow algorithm to convert $n$ bits binary number:
$$\text{Decimal}=d_{1}\times2^{n-1}+d_{2}\times2^{n-2}+\cdots+d_{n-1}\times2^{1}+d_{n}\times2^{0}\text{.}$$
For example,
$$111001_{2}=1\times2^{5}+1\times2^{4}+1\times2^{3}+0\times2^{2}+0\times2^{1}+1\times2^{0}=57_{10}\text{.}$$

To apply this algorithm into programming, we need to reverse the given string first, then count the products and sum as a decimal number.

#### 1.3 Notes

1. Bonus for the project:
   - Try to use `Python` to rewrite for the object-oriented programming.
   - Try to add the inverse part which could convert decimal to binary.
2. How about transformation this "program" to a "module"? For example, we could write a function and use it in other programs.
3. When `int decimal` exceed $2^{31}-1$ but not too large, the output would show as a negative number. However, when the result is too large to display, there is an error. No matter if we change the `int` to `long long`, this problem still exists. It might be caused by the operating system limit.
4. Is there any higher efficiency algorithm but not the brute force one?
5. More boundary cases should be added for testing.
6. Large-number calculations. E.g. `1E1024`.
