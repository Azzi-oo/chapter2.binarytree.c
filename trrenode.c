#include "print_module.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    time_t now = time(0);
    struct tm* tm_struct = localtime(&now);
    char* message = (char*)malloc(sizeof(char) * 100);
    int hour = tm_struct->tm_hour;
    int minute = tm_struct->tm_min;
    int sec = tm_struct->tm_sec;
    if (message != NULL) {
        sprintf(message, "[LOG] %d:%d:%d H&CO TEAM", hour, minute, sec);
        print_log(print_char, message);
    } else
        printf("n/a");
    free(message);
    return 0;
}

void print_log(char (*print)(char), char* message) {
    int count = 0;
    while (message[count] != '\0') {
        print(message[count]);
        count++;
    }
}

char print_char(char ch) { return putchar(ch); }
