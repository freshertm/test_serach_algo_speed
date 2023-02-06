# test_search_algo_speed

Main purpose: compare 2 array search algorithms. 

The task is find nearest item in array less or equal to given.

Algorithm 1 - reverse lookup in array.
Algorithm 2 - dichotomous search.

# Build
## Prerequisites: 
 - Qt5 + Qtcreator
 - CMake

## Build
 - just open in QtCreator, choose Qt framework and build. 

# Run
There are 2 parameters required to run:
 1. maximum number of values to check (will checked x in range 0 .. argv[1])
 2. size of a array. array will randomly generate each time.

All numbers in repot in milliseconds. To get comparable value i added repeats constans. for my PC it value is 10M.

# Tests:
## Worst case for dichotomic search:
> algo_speed_test.exe 20 5

```
checking values 0 .. 20
Size of 'a' array:  5
a array: QVector(3, 5, 7, 10, 14)
v: 0  e1: 110  e2: 26 a1s 5 a2s: 0 "OK"
v: 1  e1: 112  e2: 27 a1s 5 a2s: 0 "OK"
v: 2  e1: 115  e2: 27 a1s 5 a2s: 0 "OK"
v: 3  e1: 109  e2: 145 a1s 5 a2s: 3 "OK"
v: 4  e1: 114  e2: 144 a1s 5 a2s: 3 "OK"
v: 5  e1: 89  e2: 111 a1s 4 a2s: 2 "OK"
v: 6  e1: 93  e2: 113 a1s 4 a2s: 2 "OK"
v: 7  e1: 75  e2: 82 a1s 3 a2s: 1 "OK"
v: 8  e1: 71  e2: 81 a1s 3 a2s: 1 "OK"
v: 9  e1: 69  e2: 81 a1s 3 a2s: 1 "OK"
v: 10  e1: 54  e2: 118 a1s 2 a2s: 2 "OK"
v: 11  e1: 52  e2: 117 a1s 2 a2s: 2 "OK"
v: 12  e1: 52  e2: 116 a1s 2 a2s: 2 "OK"
v: 13  e1: 54  e2: 117 a1s 2 a2s: 2 "OK"
v: 14  e1: 37  e2: 40 a1s 1 a2s: 0 "OK"
v: 15  e1: 38  e2: 39 a1s 1 a2s: 0 "OK"
v: 16  e1: 40  e2: 39 a1s 1 a2s: 0 "OK"
v: 17  e1: 39  e2: 39 a1s 1 a2s: 0 "OK"
v: 18  e1: 38  e2: 39 a1s 1 a2s: 0 "OK"
v: 19  e1: 38  e2: 38 a1s 1 a2s: 0 "OK"
v: 20  e1: 38  e2: 38 a1s 1 a2s: 0 "OK"
sum1:  1437  sum2: 1577
avg1:  68  avg2: 75
min1:  37  min2: 26
max1:  115  max2: 145
```

## Worst case for reverse search:

> algo_speed_test.exe 5 20

```
checking values 0 .. 5
Size of 'a' array:  20
a array: QVector(2, 7, 8, 10, 13, 16, 19, 22, 23, 28, 29, 31, 36, 39, 43, 47, 52, 57, 61, 66)
v: 0  e1: 435  e2: 26 a1s 20 a2s: 0 "OK"
v: 1  e1: 422  e2: 27 a1s 20 a2s: 0 "OK"
v: 2  e1: 432  e2: 230 a1s 20 a2s: 6 "OK"
v: 3  e1: 432  e2: 240 a1s 20 a2s: 6 "OK"
v: 4  e1: 457  e2: 223 a1s 20 a2s: 6 "OK"
v: 5  e1: 434  e2: 224 a1s 20 a2s: 6 "OK"
sum1:  2612  sum2: 970
avg1:  435  avg2: 161
min1:  422  min2: 26
max1:  457  max2: 240
```

