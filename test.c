#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Sleeping for 3 seconds...\n");
    sleep(5); // Sleep for 3 seconds
    printf("Woke up!\n");
    return 0;
}