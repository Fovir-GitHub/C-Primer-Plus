# main() arguments

To start program from command-line,we need add arguments to main() function.
Usaually, the statement is like this:

```c
int main(int argc, char* argv[])
```

The first argument `argc` means the number of arguments.
The second argument `argv` stores the arguments.
For example, the `cp` command in Linux usually has 2 arguments:

```bash
cp test.in test.out
```

We assume the `cp` is programmed by C language, then the argc should be 3 rather than 2.
The `argv` array stores data like this:

```txt
argc = 3
argv[0] cp
argv[1] test.in
argv[2] test.out
```

# Open file and close file

To open a file, we should use `FILE` to  declare a pointer.
For example:

```c
FILE* fp;
```

If we need to open a file called "test.txt", we need `fopen()` function.
To use this function, we need `<stdio.h>` at first.
This function need 2 arguments.
The first one is the location of the file we want to open and the second one is the open mode. Both of them have the same type `const char*` .
The function returns a `FILE*` pointer.

The second argument have some option:

| Option | Mean |
| ------ | -----|
| "r" | Read mode. |
| "w" | Write mode. It will truncate an existing file to zero length, or creat the file if it does not exist. |
|"a"| Open a file for writing. It will append to the end of the existing file, or create a new file if it does not exist. |
| "r+","w+","a+"| Open a text file for update.|
|"rb","wb","ab"| "b" stand for "binary", which means opening the file in binary form.|

Looking at the following example, if we want to read a "test.in" file, it may like this:

```c
FILE* fp;
fp = fopen("test.in", "r");
```

If the file can't be opened, the function `fopen()` will return `NULL` value.

When we finish using the file, we should use the function `fclose()` to close it.
The function prototype is as follow:

```c
int fclose (FILE *__stream);
```

It receive a `FILE*` pointer. If we want to close the file "test.in" that we had opened, it may like this:

```c
#include<stdio.h>

int main(void)
{
    FILE* fp;
    fp = fopen("test.in", "r");
    fclose(fp);

    return 0;
}
```

If closing the file successfully, the function will return 0.

**Attention:**
1. Never use `fclose()` to close a file that have not opened yet.
2. If the `fopen()` return `NULL`, it means the file can't be opened, so the file doesn't open! As a result, Don't use `fclose()` to close it.