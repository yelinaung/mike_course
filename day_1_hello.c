#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int square(int x)
{
    return x * x;
}

void say_hello(void)
{
    printf("hello!\n");
}

void countdown_recursion(int n)
{
    assert(n >= -1 && "n was not greater than 0");
    // base
    if (n < 0) {
        return;
    }
    printf("recursively counting down - %d\n", n);
    countdown_recursion(n - 1);
}

void setValue1(int newValue)
{
    printf("[Before] newValue is is %d\n", newValue);
    newValue = 9999;
    printf("[After] newValue is is %d\n", newValue);
}

void setValue2(int* newValue)
{
    // this will actually modify the value
    // *(..) dereferences it
    *newValue = 9999;
}

struct Student {
    int age;
    int id;
    char averageGrade;
};

typedef struct student2 {
    int age;
    int id;
    char averageGrade;
} student2;

typedef struct node {
    int data;
    struct node* next;
} node_t;

void printStudent2(student2 s)
{
    printf("[normal] \ts.age %d\n", s.age);
}

void printStudent3(student2* s)
{
    // -> is doing dereferencing the pointer
    // to the struct and then access the field
    // it's the same as (*s).age
    printf("[pointer] \ts.age %d\n", s->age);
    printf("[pointer] \ts.id %d\n", (*s).id);
}

int main()
{
    printf("Hello, World!\n");
    int x = 32;
    x = 33;
    printf("x is %d\n", x);

    float pi = 3.124f;
    printf("pi is %f\n", pi);

    int my_array[5];
    my_array[0] = 44;
    my_array[1] = 45;
    my_array[2] = 46;
    my_array[3] = 47;
    my_array[4] = 49;
    printf("my_array[3] is %d\n", my_array[3]);

    for (int i = 0; i < 5; i = i + 1) {
        printf("my_array [%d] = %d\n", i, my_array[i]);
    }

    int count_down = 10;
    while (count_down > 0) {
        printf("countdown [%d]\n", count_down);
        count_down = count_down - 1;
    }

    {
        int y = 42;
        printf("this variable only exists in this scope %d", y);
    }
    // this won't work
    // printf("y is %d\n", y);

    printf("square(7)=%d\n", square(7));

    say_hello();

    countdown_recursion(4);

    int a = 42;
    // &something prints out 'address' of 'something'
    printf("address of a %p\n", &a);

    printf("value of a %d\n", *(&a));

    // pointer pointing to an address of a
    int* px = &a;
    printf("px is %p\n", px);

    // dereferencing = getting the value of the thing we point to
    printf("*px, the thing that we point to is %d\n", *px);

    // malloc and free
    int* dynamicArray = malloc(sizeof(int) * 5);
    dynamicArray[0] = 33;
    dynamicArray[1] = 12;
    dynamicArray[2] = 53;
    dynamicArray[3] = 83;
    dynamicArray[4] = 93;
    free(dynamicArray);

    // int sizeOfArray = 0;
    // scanf("Enter the size : %d", &sizeOfArray);
    // int* dynamicArr = malloc(sizeof(int) * sizeOfArray);
    // for (int i = 0; i < sizeOfArray; i++) {
    //     dynamicArr[i] = 0;
    // }
    // free(dynamicArr);

    int c = 3333;
    printf("[Before setValue1] c is %d\n", c);
    setValue1(c);
    printf("[After  setValue1] c is %d\n", c);

    printf("[Before setValue2] c is %d\n", c);
    setValue2(&c);
    printf("[After  setValue2] c is %d\n", c);

    // string literal
    // they are a series of characters
    // we point to that series of chracters with a 'char*'
    // string literals do not get modified, they are read-only
    // **** immutable strings ***** //
    char* d = "hello";
    puts(d);
    printf("d[3] = %c\n", d[3]);

    // we get segfault if we do this
    // d[0] = 'b';

    // string array
    // **** mutable strings ***** //
    char e[] = "hello\0";
    puts(e);
    printf("e[0] = %c\n", e[0]);
    e[0] = 'b';
    puts(e);
    printf("e[0] = %c\n", e[0]);

    // ld = long unsigned
    printf("length of string e is %ld\n", strlen(e));

    // structures
    struct Student yelin;
    yelin.age = 32;
    printf("yelin.age %d\n", yelin.age);

    student2 mike;
    mike.age = 30;
    printStudent2(mike);
    printStudent3(&mike);

    // dynamically allocating the struct
    student2* dynamicStudents = malloc(sizeof(student2) * 300);
    free(dynamicStudents);

    // Linked List
    node_t one;
    node_t two;
    node_t three;
    one.data = 1;
    one.next = &two;

    two.data = 2;
    two.next = &three;

    three.data = 3;
    three.next = NULL;

    // looping through it
    // temp node
    node_t* iter = &one;
    // follow through the node until it finds NULL
    while (iter != NULL) {
        printf("data %d\n", iter->data);
        // point the current node to the next node
        iter = iter->next;
    }
    return 0;
}
