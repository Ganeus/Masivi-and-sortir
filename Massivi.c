#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    char* surname;
} MyStruct;

typedef int (*PredicateFunc)(MyStruct, MyStruct);

void SortArray(MyStruct* arr, size_t arrSize, PredicateFunc predicate);

int PredicateName(MyStruct s1, MyStruct s2) {
    return strcmp(s1.name, s2.name);
}

int main() {
    MyStruct* data = (MyStruct*)malloc(3 * sizeof(MyStruct));

    data[0].name = "Semen";
    data[0].surname = "Kalimaga";

    data[1].name = "Alica";
    data[1].surname = "Snith";

    data[2].name = "Vasia";
    data[2].surname = "Petushkov";

    SortArray(data, 3, PredicateName);

    for (int i = 0; i < 3; i++) {
        printf("%s %s\n", data[i].name, data[i].surname);
    }

    free(data);
    return 0;
}

void SortArray(MyStruct* arr, size_t arrSize, PredicateFunc predicate) {
    int i, j;
    MyStruct temp;

    for (i = 0; i < arrSize - 1; i++) {
        for (j = 0; j < arrSize - i - 1; j++) {
            if (predicate(arr[j], arr[j + 1]) > 0) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
