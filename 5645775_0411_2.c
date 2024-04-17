#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 5          

typedef int element;

typedef struct Stacktype {
    element* data;
    int capacity;
    int top;
} StackType;

void init(StackType* sptr) {
    sptr->capacity = INITIAL_CAPACITY; 
    sptr->data = (element*)malloc(sizeof(element) * sptr->capacity);  
    sptr->top = -1;  
}

int is_empty(StackType* sptr) {
    return (sptr->top == -1);
}

int is_full(StackType* sptr) {
    return (sptr->top == sptr->capacity - 1);
}

void push(StackType* sptr, element item) {
    if (is_full(sptr)) {
        int new_capacity = sptr->capacity + (sptr->capacity / 2); // 현재 용량의 절반을 추가
        sptr->data = (element*)realloc(sptr->data, sizeof(element) * new_capacity); 
        sptr->capacity = new_capacity; // 새로운 용량을 스택에 반영
    }
    sptr->data[++(sptr->top)] = item;
    printf("Push: %d\n", item);
    printf("Stack elements: ");
    for (int i = 0; i <= sptr->top; i++) {
        printf("%d ", sptr->data[i]);
    }
    printf("\n");
}

element pop(StackType* sptr) {
    if (is_empty(sptr)) {
        fprintf(stderr, "Stack Underflow\n"); 
        return -1;
    }
    else {
        element temp = sptr->data[(sptr->top)--];
        printf("Pop: %d\n", temp);
        if (is_empty(sptr)) {
            printf("Stack Underflow\n"); 
        }
        else {
            printf("Stack elements: ");
            for (int i = 0; i <= sptr->top; i++) {
                printf("%d ", sptr->data[i]);
            }
            printf("\n");
        }
        return temp;
    }
}

int main() {
    StackType s;
    int rand_num;

    srand(time(NULL));

    init(&s);

    for (int i = 0; i < 30; i++) {
        rand_num = rand() % 100 + 1;
        printf("\n");
        printf("Current rand_num: %d | %s\n", rand_num, (rand_num % 2 == 0) ? "Even" : "Odd");
        if ((rand_num % 2) == 0) {
            push(&s, rand_num);
        }
        else {
            pop(&s);
        }
    }

    free(s.data); 
    return 0;
}

/*
malloc 함수로 실행 시간에 메모리를 할당 받고 스택을 생성함
realloc 함수로 malloc을 통해 할당된 메모리의 크기를 축소하거나 확장함
*/