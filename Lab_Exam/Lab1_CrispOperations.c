#include<stdio.h>

void printSet(int set[], int size){
    for(int i = 0; i<size-1; i++){
        printf("%d, ", set[i]);
    }
    printf("%d}\n", set[size-1]);
}

void unionOperation(int set1[], int set2[], int aSize, int bSize){
    // calculating A U B
    int x = aSize + bSize;
    int u[x];
    int unionSize = 0;

    for(int i = 0; i<aSize; i++){
        u[unionSize++] = set1[i];
    }

    for(int i = 0; i<bSize; i++){
        int flag = 0;
        for(int j = 0; j<unionSize; j++){
            if(set2[i] == u[j]){
                flag = 1;
                break;
            }
        }

        if(flag != 1){
            u[unionSize++] = set2[i];
        }
    }

    printf("A U B: {");
    for(int i = 0; i<unionSize-1; i++){
        printf("%d, ", u[i]);
    }
    printf("%d}\n", u[unionSize-1]);
}

void intersectionOperation(int set1[], int set2[], int aSize, int bSize){
    int x = aSize + bSize;
    int sizeI = 0;
    int intersection[x];

    for(int i = 0; i<aSize; i++){
        for(int j = 0; j<bSize; j++){
            if(set1[i] == set2[j]){
                intersection[sizeI++] = set1[i];
                break;
            }
        }
    }

    printf("A int B: {");
    printSet(intersection, sizeI);
}

void complementOperation(int uni[], int set[], int uSize, int aSize){
    int complement[uSize];
    int sizeU = 0;

    for(int i = 0; i<uSize; i++){
        int flag = 0;
        for(int j = 0; j<aSize; j++){
            if(uni[i] == set[j]){
                flag = 1;
                break;
            }
        }
        if(flag != 1){
            complement[sizeU++] = uni[i];
        }
    }

    printf("A`: {");
    printSet(complement, sizeU);
}

void differenceOperation(int set1[], int set2[], int aSize, int bSize){
    int difference[aSize];
    int sizeD = 0;
    
    for(int i = 0; i<aSize; i++){
        int flag = 0;
        for(int j = 0; j<bSize; j++){
            if(set1[i] == set2[j]){
                flag = 1;
                break;
            }
        }
        if(flag != 1){
            difference[sizeD++] = set1[i];
        }
    }

    printf("A - B: {");
    printSet(difference, sizeD);
}

int main(){
    int uSize, aSize, bSize;

    printf("Enter size of Universal set: ");
    scanf("%d", &uSize);

    printf("Enter size of Set1: ");
    scanf("%d", &aSize);

    printf("Enter size of Set2: ");
    scanf("%d", &bSize);

    int uni[uSize], set1[aSize], set2[bSize];

    printf("Enter the Universal Set: ");
    for(int i = 0; i<uSize; i++){
        scanf("%d", &uni[i]);
    }

    printf("Enter the Set1: ");
    for(int i = 0; i<aSize; i++){
        scanf("%d", &set1[i]);
    }

    printf("Enter the Set2: ");
    for(int i = 0; i<bSize; i++){
        scanf("%d", &set2[i]);
    }

    printf("Uni: {");
    for(int i = 0; i<uSize-1; i++){
        printf("%d, ", uni[i]);
    }
    printf("%d}\n", uni[aSize-1]);

    printf("A: {");
    for(int i = 0; i<aSize-1; i++){
        printf("%d, ", set1[i]);
    }
    printf("%d}\n", set1[aSize-1]);

    printf("B: {");
    for(int i = 0; i<bSize-1; i++){
        printf("%d, ", set2[i]);
    }
    printf("%d}\n", set2[bSize-1]);

    unionOperation(set1, set2, aSize, bSize);
    intersectionOperation(set1, set2, aSize, bSize);
    differenceOperation(set1, set2, aSize, bSize);
    complementOperation(uni, set1, uSize, aSize);
}