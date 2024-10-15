#include <stdio.h>
#include <limits.h>

int reverse(int x) {
    int rev = 0, a;

    while (x != 0) {
        a = x % 10;
        if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && a > 7)) {
            return 0;
        }
        if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && a < -8)) {
            return 0;
        }

        rev = rev * 10 + a;
        x = x / 10;
    }

    return rev;
}

int main() {
    int x;
    
    
    printf("Enter an integer: ");
    scanf("%d", &x);

    int result = reverse(x);
    if (result == 0) {
        printf("Overflow occurred. Cannot reverse the number.\n");
    } else {
        printf("Reversed: %d\n", result);
    }

    return 0;
}
