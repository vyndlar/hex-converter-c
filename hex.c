#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

// hex 0x1a3 == 419

bool is_hex_char(char c) {
    return isxdigit((unsigned char)c) != 0;
}

void convert_from_hex(char* num, size_t num_len) {
    int num_dec[num_len-3];

    // convert each hexadecimal char to decimal
    for (size_t i = 2; i < num_len; i++) {
        char c = num[i];
        if (c >= '0' && c <= '9') {
            num_dec[i-2] = c - '0';
        }

        c = tolower((unsigned char)c);
        if (c >= 'a' && c <= 'f') {
            num_dec[i-2] = c - 'a' + 10;
        }

        //printf("num_dec[%zu] = %i\n", i-2, num_dec[i-2]);
    }


    int total = 0;

    for (size_t pos = 0; pos <= num_len-3; pos++) {
       size_t n_pos = (num_len-3) - pos; // the negative pos (pos from END of num_dec)
       double n = (double)num_dec[pos];

       total += (n*(pow(16,(double)n_pos)));

    }

    printf("%i\n", total);

}

int convert_from_decimal() {}

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Usage: %s <number>\n", argv[0]);
        return 1;
    }

    if (strstr(argv[1], "0x") == argv[1]) { // does it start with '0x'?

        bool isHex = true;

        for(int i = 2; i < strlen(argv[1]); i++) {
            if (is_hex_char(argv[1][i])) {
                isHex = true;
            } else {
                isHex = false;
                break;
            }
        }
        if (isHex && strlen(argv[1]) > 2) {
            //printf("Hex: %s\n", argv[1]);
            convert_from_hex(argv[1], strlen(argv[1]));
        } else {
            printf("Not hex\n");
        }

    } else {

        bool foundalpha = true;
        // not hex, check if is all num
        for(int i = 0; i < strlen(argv[1]); i++) {
            if (foundalpha = isalpha(argv[1][i])) {
                break;
            }
        }
        if (foundalpha) {
            printf("NaN: Hex numbers start with '0x'\n");
            return 1;
        } else {
            printf("Pure Number!\n");
        }
    }
}
