#include <stdio.h>
#include <math.h>
int convertBinaryToDecimal(int binary) {
    int decimal = 0;
    int base = 1;
    
    while (binary > 0) {
        int lastDigit = binary % 10; 
        decimal += lastDigit * base; 
        binary = binary / 10;   
        base = base * 2;     
    }
    return decimal;
}
