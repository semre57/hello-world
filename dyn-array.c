//
// Created by Emre Ağan on 29.12.2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct intArray {
    int* Array;
    int size;
    int capacity;
}intArray;

intArray* init() {
    intArray* dynamic = malloc(sizeof(intArray));

    if (dynamic == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }

    dynamic->capacity = 16;
    dynamic ->size = 0;

    dynamic->Array = malloc(sizeof(int)*dynamic->capacity);

    if (dynamic->Array == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }

    return dynamic;
}

void add(intArray* dynamic, int value) {
    if (dynamic->capacity == dynamic->size) {
        dynamic->capacity *= 2;

        dynamic->Array = realloc(dynamic->Array,sizeof(int)*dynamic->capacity);

        if (dynamic->Array == NULL) {
            fprintf(stderr, "Memory reallocation failed!\n");
            exit(1);
        }
    }

    dynamic->Array[dynamic->size++] = value; // using dynamic->size++'s return value as index and side effect increases size's value.
    printf("The element %d added in array successfully!\n\n",value);
}

void del(intArray* dynamic, int index) {
    int i;

    if (!(index < dynamic->size)) {
        printf("The index is out of range! Try again!\n");
    }

    else {
        for(i = index; i <dynamic->size; i++) {
            dynamic->Array[i] = dynamic->Array[i+1];
        }

        dynamic->size--;
        printf("The index %d removed in array successfully!\n",index);
    }
}

int get(intArray* dynamic, int index) {
    if (!(index < dynamic->size)) {
        printf("The index is out of range! Try again!\n");
    }

    else {
        printf("%d.Index = %d\n",index,dynamic->Array[index]);
        return dynamic->Array[index];
    }
}

void set(intArray* dynamic, int index, int value) {
    if (!(index < dynamic->size)) {
        printf("The index is out of range! Try again!\n");
    }

    else {
        dynamic->Array[index] = value;
        printf("%d. index's value changed with %d!\n",index,dynamic->Array[index]);
    }
}

void contains(intArray* dynamic, int value) {
    int i;
    int flag =0;

    for(i=0; i<dynamic->size; i++) {
        if(dynamic->Array[i] == value) {
            printf("The element %d found at index %d!\n",value,i);
            flag = 1;
        }
    }

    if(!flag) {
        printf("The element %d is not found in array!\n",value);
    }
}

void size(intArray* dynamic) {
    printf("The size of array is %d!\n",dynamic->size);
}

void capacity(intArray* dynamic) {
    printf("The capacity of array is %d!\n",dynamic->capacity);
}

void shrink(intArray *dynamic) {
    if(dynamic->capacity > dynamic->size) {

        if(!(dynamic->size==0)) {
            dynamic->capacity = dynamic->size;
            dynamic->Array = realloc(dynamic->Array, sizeof(int)*dynamic->capacity);
            printf("Array shrinked succesfully!\n");
        }

        else {
            fprintf(stderr,"Because of size equal to 0 capacity automatically set equal to 16!\n");
            dynamic->capacity = 16;
        }
    }
}

void clear(intArray* dynamic) {
    dynamic->size = 0;
    printf("Array cleared succesfully!\n");
    shrink(dynamic);
}

void printArray(intArray *dynamic) {
    int i;

    if(!(dynamic->size == 0)) {

        for(i=0; i< dynamic->size; i++) {
            printf("Arr[%d] = %d\n",i,dynamic->Array[i]);
        }
    }

    else {
        printf("Array is empty!\n");
    }
}

void clearLoc(intArray *dynamic) {
    free(dynamic->Array);
    free(dynamic);
    printf("Allocated memory cleared succesfully!\n");
    fprintf(stderr,"Array destroyed! Exit automatically...!\n");
    exit(1);
}

int main() {
    intArray *p = init();
    int i,l,value,value2,choice;
    printf("Please enter the length of your Array: ");
    scanf("%d",&l);

    for(i = 0; i<l; i++) {
        printf("Please enter the %d. element of your array: ",i+1);
        scanf("%d",&value);
        add(p,value);
    }

    do {
        printf("\nPlease choose operation for your array:"
               "\n------------------------------------------------------------\n"
               "\nPress 1 to add new element"
               "\nPress 2 to delete element"
               "\nPress 3 to get the value of choosen index"
               "\nPress 4 to change the value of choosen index"
               "\nPress 5 to check choosen element exist in the array"
               "\nPress 6 to get size of array"
               "\nPress 7 to get capacity of array"
               "\nPress 8 to clear your array"
               "\nPress 9 to shrink memory usage automatically"
               "\nPress 10 to print elements of your array"
               "\nPress 11 to clear allocated memory (EXIT AUTOMATICALLY!)"
               "\nPress 12 to exit program\n"
               "\n------------------------------------------------------------\n"
               "\nEnter your choice: " );

        scanf("%d",&choice);

        switch(choice) {

            case 1 : {
                printf("\nEnter the value: ");
                scanf("%d",&value);
                add(p,value);
                sleep(3);
                break;
            }

            case 2 : {
                printf("\nEnter the index you want to delete: ");
                scanf("%d",&value);
                del(p,value);
                sleep(3);
                break;
            }

            case 3 : {
                printf("\nEnter the index: ");
                scanf("%d",&value);
                get(p,value);
                sleep(3);
                break;
            }

            case 4 : {
                printf("\nEnter the new element: ");
                scanf("%d",&value);
                printf("\nEnter the index of the element you want to change: ");
                scanf("%d",&value2);
                set(p,value2,value);
                sleep(3);
                break;
            }

            case 5 : {
                printf("\nEnter the value of the element to check if it exists in the array: ");
                scanf("%d",&value);
                contains(p,value);
                sleep(3);
                break;
            }

            case 6 : {
                size(p);
                sleep(3);
                break;
            }

            case 7 : {
                capacity(p);
                sleep(3);
                break;
            }

            case 8 : {
                clear(p);
                sleep(3);
                break;
            }

            case 9 : {
                shrink(p);
                sleep(3);
                break;
            }

            case 10 : {
                printArray(p);
                sleep(3);
                break;
            }

            case 11 : {
                clearLoc(p);
                sleep(3);
                break;
            }

            case 12 : {
                exit(1);
            }

            default : {
                printf("\nWrong choice, try again!");
                break;
            }
        }
    }while(choice != 12);

    free(p->Array);
    free(p);

    return 0;
}
