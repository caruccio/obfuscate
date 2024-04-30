Usage

```
$ make PASSWORD=onetimepass

$ ./obfuscate
onetimepass

$ ls -l obfuscate
-rwxr-xr-x 1 mateus mateus 34544 abr 30 19:25 obfuscate

$ TOKEN_IN_KMS=$(make encrypt TOKEN=mysecretpass)

$ echo $TOKEN_IN_KMS
U2FsdGVkX1/0obGdlAlZ0Fa6652ssSu905uPrSIOVW4=

$ make clean-decrypt TOKEN=$TOKEN_IN_KMS
mysecretpass

$ ls -l obfuscate
ls: cannot access 'obfuscate': No such file or directory
```

