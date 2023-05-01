# Fraudulent Activity Notification
> C++
## Description
[Hackerrank Problem](https://www.hackerrank.com/challenges/fraudulent-activity-notifications/problem)

Find a median value among ```d``` values.<br>
Remove expired data.

## Input
1 <= n <= 2 * 10^5<br>
1 <= d <= n<br>
0 <= expenditure[i] <= 200~~~~

## Example
Sample Input
```
STDIN               Function
-----               --------
9 5                 expenditure[] size n =9, d = 5
2 3 4 2 3 6 8 4 5   expenditure = [2, 3, 4, 2, 3, 6, 8, 4, 5]
```

Sample Output<br>
```2```

## How to solve
1. get countsort array to sort recent ```d``` data.
2. get median value from the countsort array
3. compare current input to the median x 2
4. remove expired data by taking away 1 from the countsort array.

```cpp
for (i = 0 to d)
    countsort[data[i]]++;

for (i = d to n)
    med = getMedianX2();
    if (data[i] >= med) res++;
    
    countsort[data[i-d]]--;
    countsort[data[i]]++;
    
return res;
```

# References
- https://www.geeksforgeeks.org/counting-sort/
- https://www.programiz.com/dsa/counting-sort

## Compiler
C++98