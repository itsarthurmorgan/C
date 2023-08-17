#include <stdio.h>
#include <stdbool.h>

void calculateChecksum(const int *bits1, const int *bits2, int n, int *checksum) {
    int carry = 0;

    for (int i = n - 1; i >= 0; i--) {
        int sum = bits1[i] + bits2[i] + carry;
        checksum[i] = sum % 2;
        carry = sum / 2;
    }

    // Add carry if present
    for (int i = n - 1; carry && i >= 0; i--) {
        int sum = checksum[i] + carry;
        checksum[i] = sum % 2;
        carry = sum / 2;
    }
}

void printBinaryArray(const int *array, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", array[i]);
    }
}

int main() {
    int n;

    printf("Enter length of bits: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input.\n");
        return 1;
    }

    char dup_bits1[100], dup_bits2[100];
    int bits1[100], bits2[100];

    printf("Enter Subnet 1: ");
    scanf("%s", dup_bits1);

    printf("Enter Subnet 2: ");
    scanf("%s", dup_bits2);

    for (int i = 0; i < n; i++) {
        bits1[i] = dup_bits1[i] - '0';
        bits2[i] = dup_bits2[i] - '0';
    }

    printf("Subnet 1: %s\n", dup_bits1);
    printf("Subnet 2: %s\n", dup_bits2);

    int checksum[100];
    calculateChecksum(bits1, bits2, n, checksum);

    printf("1's Sum: ");
    printBinaryArray(checksum, n);
    printf("\n");

    printf("Checksum: ");
    for (int i = 0; i < n; i++) {
        printf("%d", !checksum[i]);
    }
    printf("\n");

    return 0;
}
