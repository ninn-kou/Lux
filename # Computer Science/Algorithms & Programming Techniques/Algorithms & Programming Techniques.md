## Algorithms and Programming Techniques

This file is the personal notes of Hao Ren which is based on the course COMP3121 in 2021 Term 3, UNSW.

[TOC]

### 1.Introduction

#### What is an algorithm?

An **algorithm** is **a collection of precisely defined steps** that are executable using certain specified mechanical methods.

By “mechanical” we mean the methods that do not involve any creativity, intuition or even intelligence. Thus, algorithms are specified by detailed, easily repeatable “recipes”.

#### Algorithm Example: n-thieves divide the loot fairly

**Two Thieves:**

> Two thieves have robbed a warehouse and have to split a pile of items without price tags on them. Design an algorithm to split the pile so that each thief **believes** that they have got at least half the loot.

> Solution: One of the two thieves splits the pile into two parts so that they believe that both parts are of equal value. The other thief then chooses the part that they believe is no worse than the other.

**Three Thieves:**

> Three thieves have robbed a warehouse and have to split a pile of items without price tags on them. How do they do this in a way that ensures that each thief believes that they have got at least one-third of the loot?

**3-Thieves Algorithm:**

```
T1 makes a pile P1 which T1 believes is 1/3 of the whole loot;
T1 proceeds to ask T2 if they agree that P1 ≤ 1/3;

If      T2 says YES, then T1 asks T3 if T3 agrees that P1 ≤ 1/3;

        If      T3 says YES, then T1 takes P1;
                T2 and T3 split the rest as in Problem 1.

        Else    if T3 says NO, then T3 takes P1;
                T1 and T2 split the rest as in Problem 1.

Else    if T2 says NO, then T2 reduces the size of P1 to P2 < P1
        such that T2 thinks P2 = 1/3;
        T2 then proceeds to ask T3 if they agree that P2 ≤ 1/3;

        If      T3 says YES, then T2 takes P2;
                T1 and T3 split the rest as in Problem 1.

        Else    if T3 says NO, then T3 takes P2;
                T1 and T2 split the rest as in Problem 1.
```

**But what happens if there are n thieves?**

For $n$ thieves $(n > 3)$, the problem would be solved if we could reduce the situation into $n \leq 3$ cases.

$T_1$ makes a pile $P_1$ which $T_1$ believes $P_1 \geq \frac{1}{n} \mathbb{P}$, and if first $m$ thieves agree with the method that $T_1$ take $P_1$, obviously they believe that $P_1 \leq \frac{1}{n} \mathbb{P}$. For the $T_{m+1}$ do not agree with the strategy, the only reason is because he thinks $P_1 > \frac{1}{n} \mathbb{P}$, then $T_{m+1}$ reduces the size of $P_1$ into $P_2$ and he would take $P_2$ if every thieve agree with him. Because of $P_2 < P_1$, the first $m$ thieves would also agree with this strategy because they would agree with $P_2 \leq \frac{1}{n} \mathbb{P}$.

And the problem becomes to "There are $n - m$ thieves, if they agree with $P_2 \leq \frac{1}{n} \mathbb{P}$ ? If so, the thieve $T_{m+1}$ would get this pile $P_2$." It is very similar to the initial question, but we do not care about the first $m$ thieves. So we could repeat this process if someone disagrees with the strategy and reduces the size of thieves.

If no one disagrees with the last strategy, the thieve who raise this strategy would get the corresponding pile, and the size of thieves would be $n - 1$, and the remaining loot would be $\mathbb{P} - P_{m}$, it would becomes an initial status for a new dividing problem.
