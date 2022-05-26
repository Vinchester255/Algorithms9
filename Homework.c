#include <stdio.h>
#include <stdlib.h>

#define T char
#define SIZE 10
#define true 1 == 1
#define false 1 != 1

int pre[SIZE];
int end = -1;

typedef struct {
    int pr;
    int dat;
} Node;

Node* arr[SIZE];
int head;
int tail;
int items;

void swap(int* a, int* b)
{
    int t;
    t = *b;
    *b = *a;
    *a = t;
}

void sdvig(int k)
{
    if (k < end)
    {

        for (int i = k; i <= end - 1; ++i)
        {
            arr[i] = arr[i + 1];
        }

    }
    else {

    }
}

void init() {
    for (int i = 0; i < SIZE; ++i) {
        arr[i] = NULL;
    }
    head = 0;
    items = 0;
    tail = 0;
}

void sortBuble(int* pre1, int left)
{
    if (left < SIZE)
    {
        for (int i = 0; i <= left; ++i)
        {
            for (int j = 0; j <= left - 1; ++j)
            {
                if (pre1[j] > pre1[j + 1])
                {
                    swap(&pre1[j], &pre1[j + 1]);

                }
            }
        }
    }
}

void ins(int pr, int dat) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->dat = dat;
    node->pr = pr;
    int flag;

    if (items == 0) {
        arr[tail++] = node;
        items++;
    } else if (items == SIZE) {
        printf("%s \n", "Queue is full");
        return;
    } else {
        int i = 0;
        int idx = 0;
        Node *tmp;
        for (i = head; i < tail; ++i) {
            idx = i % SIZE;
            if (arr[idx]->pr > pr)
                break;
            else
                idx++;
        }
        flag = idx % SIZE;
        i++;
        while (i <= tail) {
            idx = i % SIZE;
            tmp = arr[idx];
            arr[idx] = arr[flag];
            arr[flag] = tmp;
            i++;
        }
        arr[flag] = node;
        items++;
        tail++;
    }

    


}

Node* rem() {
    if (items == 0) {
        return NULL;
    } else {
        int idx = head++ % SIZE;
        Node *tmp = arr[idx];
        arr[idx] = NULL;
        items--;
        return tmp;
    }
}

void enqueue(int pr1, int node1)
{

    Node* node = (Node*)malloc(sizeof(Node));
    node->dat = node1;
    node->pr = pr1;

    if (end < SIZE)
    {
        ++end;
        arr[end] = node;
        pre[end] = pr1;
    }
    else {
        printf("% s \n", "Queue is full");
    }

}
// Перевод из десятичной в двоичную
void binary(int n) {
	int arr[8] = {0};
	for(int i = 7; i >= 0; --i){
		arr[i] = n%2;
		n /= 2;
	}
	printf("\n");
	for(int i = 0; i < 8; ++i){
		printf("%d ", arr[i]);
	}
}

void dequeue()
{
    int a;
    int k;
    k = 0;
    sortBuble(pre, end);
    a = pre[end];
    for (int i = 0; i <= end; ++i)
    {
        if (a == arr[i]->pr)
        {
            k = i;
            break;
        }
    printf("[%d, %d]", arr[k]->pr, arr[k]->dat);
    printf(" ]\n");
    sdvig(k);
    --end;
    }
}

void PrintQueue() {
    printf("[ ");
    for (int i = 0; i < SIZE; ++i) {
        if (arr[i] == NULL)
            printf("[*, *]");
        else
            printf("[%d, %d] ", arr[i]->pr, arr[i]->dat);
    }
    printf("\n");
}



int main(const int argc, const char **argv) {
    init();
    enqueue(1,111);
    enqueue(3,52);
    enqueue(5,23);
    enqueue(2,14);
    enqueue(3,45);
    enqueue(4,76);
    enqueue(7,37);
    enqueue(5,58);
    
    PrintQueue();
    for (int i = 0; i < 5; ++i) {
        dequeue();
    }
    PrintQueue();

    binary(122);
    return 0;
}