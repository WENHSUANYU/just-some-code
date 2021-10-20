/*
* Input
* n: int
* command: string(insert|find)
* str: string(The input string only consists of four letters: A, C, G, and T. And the length is no more than 12)
* Output
* the result of find command: Yes | No
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//prime number;
#define M 1000003
#define LEN 13
#define ll long long 

int getChar(char ch)
{
    switch (ch) {
    case 'A':
        return 1;
    case 'C':
        return 2;
    case 'G':
        return 3;
    case 'T':
        return 4;
    default:
        return 0;
    }
}

long long getKey(char str[])
{
    ll sum = 0;
    ll p = 1;
    ll i;
    for (i = 1; i < strlen(str); i++) {
        sum += p * (getChar(str[i]));
        p *= 5;
    }
    return sum;
}   

int h1(int key)
{
    return key % M;
}

int h2(int key)
{
    return 1 + (key % (M - 1));
}

int insert(char str[],char **hash_table)
{
    long long key, i , h;
    key = getKey(str);
    for ( i = 0; ;i++) {
        h = (h1(key) + i * h2(key)) % M;
        if (strcmp(hash_table[h], str) == 0) {
            return 1;
        } else if (strlen(hash_table[h]) == 0) {
            strcpy(hash_table[h],str);
            return 0;
        }
    }
    return 1;
}

int find(char str[], char **hash_table)
{
    ll key, i, h;
    key = getKey(str);
    for (i = 0; ;i++) {
        h = (h1(key) + i * h2(key)) % M;
        if (strcmp(hash_table[h], str) == 0)
            return 1;
        else if (strlen(hash_table[h]) == 0)
            return 0;
    }
    return 0;
}

int main() {

    int i, n, h;
    char **hash_table = (char **)malloc(M * sizeof(char *));
    for (i = 0; i < M; i++) {
        hash_table[i] = (char *)malloc(LEN *sizeof(char));
    }
    
    for (i =0; i < M; i++) {
        hash_table[i][0] = '\0';
    }
    scanf("%d",&n);
    char str[LEN];
    char command[6];
    for (i = 0; i < n; i++) {
        scanf("%s %s",command,str);
        if (command[0] == 'i') {
            insert(str,hash_table);
        } else {
            if (find(str,hash_table)) 
                printf("Yes\n");
            else 
                printf("No\n");
        }
    }

    return 0;
}