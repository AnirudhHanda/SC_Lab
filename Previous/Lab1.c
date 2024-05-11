// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void initSet(int *arr, int size){
    for(int i = 0; i<size+1; i++){
        arr[i] = INT_MAX;
    }
}

void displaySet(int *arr, int size){
    for(int i = 0; arr[i]!=INT_MAX; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void inputSet(int *arr, int size){
    
    for(int i = 0; i<size; i++){
        int found = 0;
        int element;
        scanf("%d", &element);
        for(int j = 0; j<=i; j++){
            if(arr[j] == element){
                found = 1;
                break;
            }
        }
        if(found == 0){
            int prev = i-1;
            while(prev>=0 && arr[prev] > element){
                arr[prev+1] = arr[prev];
                prev--;
            }
            arr[prev+1] = element;
        }
    }
}

void unionOperation(int *set1, int size1, int *set2, int size2, int *unionSet, int size){
    int idx = 0;
    int i = 0, j = 0;
    
     while(i<size1 && j<size2){
            if(set1[i] < set2[j]){
                unionSet[idx] = set1[i];
                i++;
                idx++;
            } else if(set2[j] < set1[i]){
                unionSet[idx] = set2[j];
                idx++;
                j++;
            } else{
                unionSet[idx] = set1[i];
                i++;
                j++;
                idx++;
            }
        }
        while(i<size1){
            unionSet[idx] = set1[i];
            idx++;
            i++;
        }
        while(j<size2){
            unionSet[idx] = set2[j];
            idx++;
            j++;
        }
}

void intersectionOperation(int *set1, int size1, int *set2, int size2, int *intersectionSet){
    int idx = 0;
        int i =0, j = 0;
        while(i<size1 && j<size2){
            if(set1[i] == set2[j]){
                intersectionSet[idx] = set1[i];
                i++;
                j++;
                idx++;
            } else if(set1[i] < set2[j]){
                i++;
            } else{
                j++;
            }
        }
}

void complementOperation(int *set1, int size1, int *uni, int size2, int *complementSet){
    int idx = 0;
        int i = 0, j = 0;

        while(i<size2 && j<size1){
            if(uni[i] < set1[j]){
                complementSet[idx] = uni[i];
                i++;
                idx++;
            } else if(uni[i] == set1[j]){
                i++;
                j++;
            } else{
                j++;
            }
        }
        while(i<size2){
            complementSet[idx] = uni[i];
            i++; 
            idx++;
        }
}

void differenceOperation(int *set1, int size1, int *set2, int size2, int *diffSet){
    int idx = 0;
        int i = 0, j=0;

        while(i<size1 && j<size2){
            if(set1[i] < set2[j]){
                diffSet[idx] = set1[i];
                i++;
                idx++;
            } else if( set1[i] == set2[j]){
                i++;
                j++; 
            } else{
                j++;
            }
        }

        while(i < size1){
            diffSet[idx] = set1[i];
            i++; 
            idx++;
        }
}

int main() {
    int lUni;
    int lA;
    int lB;
    
    printf("Enter the length of Uni, A and B: ");
    scanf("%d %d %d", &lUni, &lA, &lB);
    
   int *uni;
   int *A;
   int *B;
   
   uni = (int *)malloc((lUni+1) * sizeof(int));
   A = (int *)malloc((lA+1) * sizeof(int));
   B = (int *)malloc((lB+1) * sizeof(int));
   
   initSet(uni, lUni);
   initSet(A, lA);
   initSet(B, lB);
    
    printf("Input the Uni Set: ");
    inputSet(uni, lUni);
    printf("Input SetA: ");
    inputSet(A, lA);
    printf("Input SetB: ");
    inputSet(B, lB);
   
   printf("Uni Set: ");
   displaySet(uni, lUni);
   printf("SetA: ");
   displaySet(A, lA);
   printf("SetB: ");
   displaySet(B, lB);
   
   int lUnion = lA+lB+1;
   int *unionSet = (int *)malloc((lUnion)*sizeof(int));
   initSet(unionSet, lUnion);
   
   int lInter = lA+lB;
   int *interSet = (int *)malloc((lInter)*sizeof(int));
   initSet(interSet, lInter);
   
   int lComp = lUni+1;
   int *compSet = (int *)malloc((lComp)*sizeof(int));
   initSet(compSet, lComp);
   
   int lDiff = lA+1;
   int *diffSet = (int *)malloc((lDiff)*sizeof(int));
   initSet(diffSet, lDiff);
   
   printf("Union: ");
   unionOperation(A,lA, B, lB, unionSet, lUnion);
   displaySet(unionSet, lUnion);
   
  printf("Intersection: ");
  intersectionOperation(A, lA, B, lB, interSet);
  displaySet(interSet, lInter);
   
  printf("A complement: ");
  complementOperation(A, lA, uni, lUni, compSet);
  displaySet(compSet, lComp);
   
  printf("A - B: ");
  differenceOperation(A, lA, B, lB, diffSet);
  displaySet(diffSet, lDiff);
   
}