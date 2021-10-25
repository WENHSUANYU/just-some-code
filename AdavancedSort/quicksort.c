#include<stdio.h>
#include<stdlib.h>
#define Max 100000
#define Sentinel 2000000000

typedef struct {
    char suit;
    int value;
}Card;


void merge(Card A[], int left, int mid, int right)
{
    int sub_arrayL = mid - left + 1;
    int sub_arrayR = right - mid;
    Card *L = (Card*)malloc((sub_arrayL + 1) * sizeof(Card));
    Card *R = (Card*)malloc((sub_arrayR + 1) * sizeof(Card));
    L[sub_arrayL].value = R[sub_arrayR].value = Sentinel;
    for (int i = 0; i < sub_arrayL; i++) {
        L[i].value = A[left + i].value;
        L[i].suit = A[left + i].suit;
    }
    for (int i = 0; i < sub_arrayR; i++) {
        R[i].value = A[mid + 1 + i].value;
        R[i].suit = A[mid + 1 + i].suit;
    }
    int index_L = 0;
    int index_R = 0;
    for (int i = left; i <= right; i++) {
        if (L[index_L].value <= R[index_R].value) {
            A[i].value = L[index_L].value;
            A[i].suit = L[index_L].suit;
            index_L++;
        } else {
            A[i].value = R[index_R].value;
            A[i].suit = R[index_R].suit;
            index_R++;
        }
    }
    free(L);
    free(R);
}

void mergeSort(Card A[], int left, int right)
{
    if (left >= right)
        return;
    int mid = (left + right) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid + 1, right);
    merge(A, left, mid, right);
}

int partition(Card B[], int p, int r)
{
    int i = p;
    Card tmp;
    for (int j = p; j < r; j++) {
        if (B[j].value <= B[r].value) {
            tmp = B[i];
            B[i] = B[j];
            B[j] = tmp;
            i++;
        }
    }
    tmp = B[i];
    B[i] = B[r];
    B[r] = tmp;
    return i;

}

void quickSort(Card B[], int p, int r)
{
    int q;
    if (p < r) {
        q = partition(B, p, r);
        quickSort(B, p, q - 1);
        quickSort(B, q + 1, r);
    }
}

int main()
{
    int n, i, v;
    scanf("%d", &n);
    Card A[n], B[n];
    char s;
    for (i = 0; i < n; i++) {
        scanf(" %c %d", &s, &v);
        A[i].suit = B[i].suit = s;
        A[i].value = B[i].value = v;
    }

    mergeSort(A, 0, n-1);
    quickSort(B, 0, n-1);

    int stable = 1;
    for (i = 0; i < n; i++) {
        if (A[i].suit != B[i].suit) {
            stable = 0;
            break;
        }
    }
    if (stable)
        printf("Stable\n");
    else
        printf("Not stable\n");
    for (i = 0; i < n; i++)
        printf("%c %d\n", B[i].suit, B[i].value);
    return 0;
}