    SECTION .data               ; 包含已经初始化的数据段
    
EatMsg: db "Hello World!", 10   ; 10 代表 ASCII回车等同于c语言"\n"
EatLen: equ $-EatMsg            ; 计算EatMsg的串长度
    
    SECTION .bss                ; 包含未初始化的数据段
    SECTION .text               ; 包含代码段

    global _start               ; 连接器根据此寻找程序入口点
    
_start:
    nop                         ; 方便gdb调试
    mov eax, 4                  ; 系统调用编号: sys_write
    mov ebx, 1                  ; 指定文件描述符为1, 标准输出
    mov ecx, EatMsg             ; 传递打印信息
    mov edx, EatLen             ; 传递打印信息的长度
    int 80H                     ; 中断执行系统调用
    mov eax, 1                  ; 系统调用编号: Exit
    mov ebx, 0                  ; 返回一个0代表运行成功
    int 80H                     ; 中断执行系统调用
