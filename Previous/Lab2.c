#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void inputSet(float *arr, int size){
    for(int i = 0; i<size; i++){
        float element;
        float mValue;
        scanf("%f %f", &element, &mValue);
        arr[i] = element;
        i++;
        arr[i] = mValue;
    }
}

void displaySet(float *arr, int size){
    printf("{");
    for(int i = 0; i < size; i += 2){
        printf("(%d, %.1f)", (int)arr[i], arr[i+1]);
        if(i < size - 2){
            printf(", ");
        }
    }
    printf("}\n");
}

void unionOperation(float *set1, int size1, float *set2, int size2, float *unionSet){
    int idx = 0;
    int i = 0, j= 0;
    while(i<size1 && j < size2){
        unionSet[idx] = set1[i];
        idx++;
        i++;
        j++;
        if(set1[i] < set2[j]){
            unionSet[idx] = set2[j];
            j++;
            i++;
            idx++;
        } else{
            unionSet[idx] = set1[i];
            i++;
            j++;
            idx++;
        }
    }
}

void intersectionOperation(float *set1, int size1, float *set2, int size2, float *interSet){
    int idx = 0;
    int i = 0, j= 0;
    while(i<size1 && j < size2){
        interSet[idx] = set1[i];
        idx++;
        i++;
        j++;
        if(set1[i] > set2[j]){
            interSet[idx] = set2[j];
            j++;
            i++;
            idx++;
        } else{
            interSet[idx] = set1[i];
            i++;
            j++;
            idx++;
        }
    }
}

void complement(float *set1, int size1, float *compSet){
    for(int i = 1; i < size1; i += 2){
        compSet[i-1] = set1[i-1]; // Copying the elements
        compSet[i] = 1 - set1[i]; // Calculating the complement of membership values
    }
}

void differenceOperation(float *set1, int size1, float *set2, int size2, float *diffSet){
    float *comp2 = (float *)malloc((size2)*sizeof(float));
    complement(set2, size2, comp2);
    intersectionOperation(set1, size1, comp2, size2, diffSet);
}

int main(){
    int lUni, lA, lB;
    printf("Enter lengths of Uni, A and B: ");
    scanf("%d %d %d", &lUni, &lA, &lB);
    lUni = 2*lUni;
    lA = 2*lA; 
    lB = 2*lB;
    float *uni = (float *)malloc((lUni)*sizeof(float));
    float *A = (float *)malloc((lA)*sizeof(float));
    float *B = (float *)malloc((lB)*sizeof(float));
    
    printf("Input Universal: ");
    inputSet(uni, lUni);
    printf("Input SetA: ");
    inputSet(A, lA);
    printf("Input SetB: ");
    inputSet(B, lB);
    
    printf("Uni: ");
    displaySet(uni, lUni);
    printf("SetA: ");
    displaySet(A, lA);
    printf("SetB: ");
    displaySet(B, lB);
    
    float *unionSet = (float *)malloc((lA)*sizeof(float));
    unionOperation(A, lA, B, lB, unionSet);
    printf("Union: ");
    displaySet(unionSet, lA);
    
    float *interSet = (float *)malloc((lA)*sizeof(float));
    intersectionOperation(A, lA, B, lB, interSet);
    printf("Intersection: ");
    displaySet(interSet, lA);
    
    float *compSet = (float *)malloc((lA)*sizeof(float));
    complement(A, lA, compSet);
    printf("A Complement: ");
    displaySet(compSet, lA);
    
    float *diffSet = (float *)malloc((lA)*sizeof(float));
    differenceOperation(A, lA, B, lB, diffSet);
    printf("A-B: ");
    displaySet(diffSet, lA);
}
