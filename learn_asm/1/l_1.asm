assume cs:code

    code segment
        mov ax,32
        inc ax
        dec ax
        db 'hello'
        mov al,ss:5
        mov ss:[10],al
        mov ax,4c100h
        mov bx,[4]
        int 21h
    code end

end
