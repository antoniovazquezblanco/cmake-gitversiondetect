#include <stdio.h>

int main() {
    printf("Example program using GitVersionDetect\n");
    printf("Version: %s\n", VERSION_STRING);
    printf("Major: %d\n", VERSION_MAJOR);
    printf("Minor: %d\n", VERSION_MINOR);
    printf("Patch: %d\n", VERSION_PATCH);
    return 0;
}
