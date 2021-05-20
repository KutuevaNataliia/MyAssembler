#include <iostream>

void toUpper(char* _str, int _length) {
    __asm {
        mov edx, _str
        mov ecx, _length
        Upper:
            jecxz Finish
            mov al, [edx]
            cmp al, 61h
            jb Next
            cmp al, 7ah
            ja Next
            sub al, 20h
            mov [edx], al
        Next :
            inc edx
            loop Upper
        Finish:
           xor edx, edx
    }
}

int countSpaces(char* _str, int _length) {
    int result = -1;
    __asm {
        mov edx, _str
        mov ecx, _length
        xor ebx, ebx
        Repeat:
            jecxz Finish
            mov al, [edx]
            cmp al, 20h
            jnz Next
            inc ebx
        Next:
            inc edx
            loop Repeat
        Finish:
            mov result, ebx
    }
    return result;
}

int16_t lastSlash(char* _str, int16_t _length) {
    int16_t result = -1;
    int32_t l = _length;
    __asm {
        std
        mov edi, _str
        mov al, 5ch
        mov cx, _length
        add edi, l
        rep scasb
        jz Found
        Found:
           mov result, cx
    }
    return result;
}

int main()
{
    /*char str[] = "Hello World!";
    toUpper(str, 12);
    std::cout << "String in Uppercase " << str << std::endl;
    char str2[] = "Hello World !";
    std::cout << "Spaces' number in str2 " << countSpaces(str2, 13) << std::endl;*/
    char str3[] = "Hello \\ World\\!";
    int16_t x = lastSlash(str3, 15);
    std::cout << "Last slash if found on position " << x << std::endl;
}