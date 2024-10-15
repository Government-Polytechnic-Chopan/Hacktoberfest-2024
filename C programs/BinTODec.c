#include <stdio.h>
#include <math.h>

// Function to convert binary number to decimal
int convertBinaryToDecimal(int binary) {
    int decimal = 0;  // Initialize decimal result to 0
    int base = 1;     // Base value for binary, starts with 2^0 = 1

    // Loop until all digits of the binary number are processed
    while (binary > 0) {
        // Extract the last digit of the binary number
        int lastDigit = binary % 10;

        // Convert binary digit to decimal equivalent and add to the result
        decimal += lastDigit * base;

        // Update the binary number by removing the last digit
        binary = binary / 10;

        // Update the base to the next power of 2 (i.e., 2^1, 2^2, etc.)
        base = base * 2;
    }
    return decimal;
}

int main() {
    int binary;

    // Input binary number from the user
    printf("Enter a binary number: ");
    scanf("%d", &binary);

    // Call the function and print the decimal result
    int decimal = convertBinaryToDecimal(binary);
    printf("The decimal equivalent is: %d\n", decimal);

    return 0;
}
