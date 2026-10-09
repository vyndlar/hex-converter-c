# Hex Converter written in C

This project was used to help me learn C, including memory management, input cleansing, etc. It takes an input and converts it from hexadecimal to decimal. It cleanses the input to avoid any errors from trying to parse incorrectly formatted text.

## Examples
### Hex must start with '0x'

``` shell
$ ./hex 07c0h
# NaN: Hex numbers start with '0x'
```

### Hex numbers must be correct

```shell
$ ./hex 0x07c0h
# Not hex
```
This 'hex' number is invalid

### Working example:

``` shell
$ ./hex 0x1a3
# 419
```

## Compiling
Use this command to compile using GCC:

``` shell
$ gcc -o hex hex.c -lm
```

And then run it (assuming you're in the same directory as the 'hex' file the compiler outputs):

``` shell
$ ./hex 0x1a3
# 419
```
