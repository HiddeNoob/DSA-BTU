/*
 * ex1_lifo_demo.c
 *
 * Simple demo that pushes a few Student structs into the generic stack
 * API from stack.c and prints them using the provided helpers.
 */

#include <stdio.h>
#include <stdlib.h>

#include "stack.c"

typedef struct {
    int id;
    float gpa;
} Student;

static Student* newStudent(int id, float gpa) {
    Student* student = (Student*)malloc(sizeof(Student));

    student->id = id;
    student->gpa = gpa;

    return student;
}

static void printStudent(void* data) {
    Student* student = (Student*)data;
    if (student == NULL) {
        printf("{NULL}");
        return;
    }
    printf("{id=%d, gpa=%.2f}, ", student->id, student->gpa);
}

static void freeStudent(void* data) {
    free(data);
}

int main(void) {
    struct Stack* stack = createStack();

    const int ids[] = {101, 102, 103};
    const float gpas[] = {3.4f, 3.1f, 2.8f};

    for (size_t i = 0; i < sizeof(ids) / sizeof(ids[0]); ++i) {
        Student* student = newStudent(ids[i], gpas[i]);

        push(stack, student);
    }

    printStack(stack, printStudent);

    printf("\n");
    
    while (!isEmpty(stack)) {
        Student* student = (Student*)pop(stack);
        if (student == NULL) {
            continue;
        }
        printf("  <- id %d, gpa %.2f ", student->id, student->gpa);
        free(student);
    }

    printf("\n");
    destroyStack(stack, freeStudent);
    return 0;
}