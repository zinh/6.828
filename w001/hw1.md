Command:

```
(gdb) br * 0x0010000c
(gdb) x/24x $esp
```

Explanation of stack values:

```
...                 # bios memory
[0x7C00] 0x8ec031fa # before reset
[0x7BFC] 0x00007c4d # return address(when bootmain return, should not happen)
[0x7BF8] 0x00000000 # ebp before jumping to bootmain (EIP = 0x7d3b)
[0x7BF4] 0x00000000 # save edi when enter bootmain
[0x7BF0] 0x00000000 # save esi when enter bootmain
[0x7BEC] 0x00000000 # save ebx when enter bootmain
[0x7be0] local variables (12 bytes) of bootmain
[0x7bdc] 0x00007d8d # return address(if kernel return)
```
