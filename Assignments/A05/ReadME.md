## Assignment 5 - Run Times
#### Due: 03-02-2021 (Tuesday @ 12:30 p.m.)
#### Byron Dowling


-----

- Count = 1048576
  
- Complexity = Big-O of n squared
  
```cpp
int count = 0;
int n = 1024;
for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++){
        count++;
    }
}
cout<<count<<endl;
```

-----

- Count = 523776
  
- Complexity = 1/2 Big-O of n squared which is still Big-O n squared
  
```cpp
int count = 0;
int n = 1024;
for(int i = 0; i < n; i++) {
    for(int j = 0; j < i; j++){
        count++;
    }
}
cout<<count<<endl;
```

-----

- Count = 536346624
  
- Complexity = 1/2 Big-O of n cubed which is still Big-O n cubed
  
```cpp
int count = 0;
int n = 1024;
for(int i = 0; i < n; i++) {
    for(int j = 0; j < i; j++){
        for(int k = 0; k < n; k++){
            count++;
        }
    }
}
cout<<count<<endl;
```

-----

- Count = 2048
  
- Complexity = 2 * Big-O of n which is still Big-O n
  
```cpp
int count=0;
int n = 1024;
for(int i = 0; i < 2*n; i++) {
    count++;
}
cout<<count<<endl;
```

-----

- Count = 2097152
  
- Complexity = 2 * Big-O of n squared which is still Big-O n squared
  
```cpp
int count=0;
int n = 1024;
for(int i = 0; i < n; i++) {
    for(int j = 0; j < 2n; j++){
        count++;
    }
}
cout<<count<<endl;
```

-----

- Count = 524800
  
- Complexity = 1/2 Big-O of n squared which is still Big-O n squared
  
```cpp
int count=0;
int n = 1024;
for(int i = 0; i < n; i++) {
    count++;
}
for(int j = 0; j < n; j++){
    for(int k = 0; k < j; k++){
        count++;
    }
}
cout<<count<<endl;
```

-----

- Count = 11264
  
- Complexity = Big-O of n log n
  
```cpp
int count = 0;
int n = 1024;
int i = n;

while(i>0){
    for(int j = 0; j < n; j++){
        count++;
    }
    i /= 2;
    cout<<i<<endl;
}
cout<<count<<endl;
```

-----

- Comparisons = 10
  
- Complexity = Big-O of log n
  
```cpp
bool found = 0;
int n = 1024;
int i = n;

// assume loaded with random numbers
// and in ascending order.
int *A = new int[n];

// Whats most number of comparisons?
// Whats the complexity?
found = BinarySearch(A,n);

```

-----

- Count = 0
  
- Complexity = Big-O of Log n
  
```cpp
int count = 0;
int n = 1024;

int i = n;
while(i>0){
    cout<<i<<endl;
    i /= 2;  
}
cout<<count<<endl;
```

-----
