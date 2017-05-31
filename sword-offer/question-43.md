## 面试题43 n个骰子的点数

<!-- TOC -->

- [面试题43 n个骰子的点数](#面试题43-n个骰子的点数)
- [题目](#题目)
    - [思路1](#思路1)
    - [实现](#实现)
    - [思路2](#思路2)

<!-- /TOC -->

## 题目
把n个骰子扔在地上，所有骰子朝上一面的点数之和为s，输入n，打印出s所有可能的值出现的概率

### 思路1
1. 基于递归求骰子的点数
2. 把n个骰子分为两堆，第一堆只有1个，第二堆有n-1个，单独的一个可能出现1-6的点数，将从1-6的没中可能和剩下n-1个骰子出现的点数相加，类似于求所有可能的组合。递归推出的条件是只剩下一个骰子。

### 实现

```cpp
int g_maxValue = 6;
void Probability(int number, int current, int sum, vector<int> &probabilities)
{
    if (current == 1)
    {
        probabilities[sum - number]++;
    }
    else
    {
        for (int i = 1; i <= g_maxValue; ++i)
            Probability(number, current - 1, i + sum, probabilities);
    }
}
// number==1时，递归推出
void Probability(int number, vector<int> &probabilities)
{
    for (int i = 1; i <= g_maxValue; ++i)
        Probability(number, number, i, probabilities);
}
void PrintProbability(int number)
{
    if (number < 1)
        return;
    int maxSum = number * g_maxValue;
    vector<int> probabilities(maxSum - number + 1, 0);
    Probability(number, probabilities);

    int total = pow(g_maxValue, number);
    for (int i = number; i <= maxSum; ++i)
    {
        double ratio = (double)probabilities[i - number] / total;
        cout << i << " : " << ratio << endl;
    }
}
``` 

### 思路2
1. 用两个数组来存储骰子点数的每个总和出现的次数
2. 在一次循环中第一个数组的第n个数字表示骰子和为n出现的次数，下次循环时，加上一个新的骰子，则此时和为n的骰子出现次数应该是上一次循环中骰子点数和为n-1、n-2、n-3、n-4、n-5、n-6次数的总和。
3. 每次循环从k开始，k是当前骰子的个数


```cpp
int g_maxValue = 6;
void PrintProbability(int number)
{
    if (number < 1)
        return;
    vector<vector<int>> probabilities(2, vector<int>(g_maxValue * 6 + 1, 0));
    int flag = 0;
    for (int i = 1; i <= g_maxValue; ++i)
        probabilities[flag][i] = 1;
    for (int k = 2; k <= number; ++k)
    {
        // k个骰子的和最小为k
        for (int i = 0; i <= g_maxValue * k; ++i)
            probabilities[1 - flag][i] = 0;
        for (int i = k; i <= g_maxValue * k; ++i)
        {
            // f(n)=f(n-1)+f(n-2)+f(n-3)+f(n-4)+f(n-5)+f(n-6)
            probabilities[1 - flag][i] = 0;
            for (int j = 1; j <= i && j <= g_maxValue; ++j)
                probabilities[1 - flag][i] += probabilities[flag][i - j];
        }
        flag = 1 - flag;
    }
    int total = pow(g_maxValue, number);
    for (int i = number; i <= g_maxValue * number; ++i)
    {
        double ratio = (double)probabilities[flag][i] / total;
        cout << i << " : " << ratio << endl;
    }
}
``` 
