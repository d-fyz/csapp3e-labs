#include <stdio.h>

/* Restored c code from assembly code */
int func4(int n, int c, int m) {
    unsigned p = m - c;
    int v = (int)(p + (p >> 31)) >> 1;
    int h = v + c;
    int result = 0;
    
    if (h <= n) {            
        if (h >= n) {
            result = 0;
        } else {
            c = h + 1;
            result = func4(n, c, m);
            result = result + result + 1;
        }
    } else {
        m = h - 1;
        result = func4(n, c, m);
        result += result;
    }
    return result;
}

int main() {
    //test func4() for a range of values
    for (int i = 0; i < 15; i++)
        printf("%2d%c", i, i < 14 ? ' ' : '\n');
    for (int i = 0; i < 15; i++)    
        printf("%2d%c", func4(i, 0, 14), i < 14 ? ' ' : '\n');
        
    return 0;
}