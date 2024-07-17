# Chapter 13 File Input & Output

## main() arguments

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

## Open file and close file

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

## Pointers to the Standard Files

In `<stdio.h>`, there are 3 file pointer, `stdin`, `stdout` and `stderr` .

| Pointer | Normally |
|----|---|
|stdin|Keyboard|
|stdout|Screen|
|stderr|Screen|

## getc() & putc()

The two functions are similar to `getchar()` and `putchar()` .

When the `getc()` function get the End-of-File, it will return a value called `EOF` . We can use this to see whether it read to the end of the file.

## fprintf() & fscanf()

`fprintf()` output to its first argument, which can be stdout, stderr or a file pointer.
`fscanf()` get input from its first argument, which can be stdin or a file pointer.

The `fscanf()` stop reading till `\n` or space. And it does not store `\n` and space.

## fgets() & fputs()

They are similar to `gets()` and `puts()`. 

The `fgets()` function prototype is:


```c
fgets(buf, STLEN, fp);
```

It stops reading till EOF (or end of a line) or one fewer than the `STLEN` limit.
Its reading includes `\n` .

However, `fputs()` doesn't add `\n` at the end of output.
That makes `fgets()` and `fputs()` be used together better.

## fseek() & ftell()

The two function allow us to treat a file like an array.
We can use `fseek()` to go to the target place and `ftell()` to get where we are.

The `fseek()` function prototype is:

```c
fseek (FILE *__stream, long int __off, int __whence);
```

The last argument can be set to 3 values:

| Mode | Offset form |
| --- | --- |
| SEEK_SET | Beginning of file. |
| SEEK_CUR | Current position. |
| SEEK_END | End of file. |

This argument defines the start point.

And the second argument is a `long` type which is used to set the offset. It can be positive or negative. The positive means moving forward and the negative means moving backward.