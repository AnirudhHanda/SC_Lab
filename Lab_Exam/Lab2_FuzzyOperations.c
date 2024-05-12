#include<stdio.h>

typedef struct{
    char ele;
    float mv;
} FuzzySet;

void fuzzyUnion(FuzzySet a1[], FuzzySet a2[], int n, FuzzySet result[]){
    for(int i = 0; i<n; i++){
        result[i].ele = a1[i].ele;
        result[i].mv = (a1[i].mv > a2[i].mv)?a1[i].mv:a2[i].mv;
    }
}

void fuzzyIntersection(FuzzySet a1[], FuzzySet a2[], int n, FuzzySet result[]){
    for(int i = 0; i<n; i++){
        result[i].ele = a1[i].ele;
        result[i].mv = (a1[i].mv < a2[i].mv)?a1[i].mv:a2[i].mv;
    }
}

void fuzzyComplement(FuzzySet a1[], int n, FuzzySet result[]){
    for(int i = 0; i<n; i++){
        result[i].ele = a1[i].ele;
        result[i].mv = 1-a1[i].mv;
    }
}

void fuzzyDifference(FuzzySet a1[], FuzzySet a2[], int n, FuzzySet result[]){
    FuzzySet compA2[n];
    fuzzyComplement(a2, n, compA2);
    // FuzzySet difference[n];
    fuzzyIntersection(a1, compA2, n, result);
}

void printSet(FuzzySet set[], int n){
    for(int i = 0; i<n; i++){
        printf("(%c, %.2f), ", set[i].ele, set[i].mv);
    }
    printf("\n");
}

int main(){
    int n;
    printf("Enter size: ");
    scanf("%d", &n);

    FuzzySet a1[n], a2[n];

    printf("Enter set1: \n");
    for(int i = 0; i<n; i++){
        printf("Enter ele of set1: ");
        scanf("%s", &a1[i].ele);
        printf("Enter mv of set1 :");
        scanf("%f", &a1[i].mv);
    }

    printf("Enter set2: \n");
    for(int i = 0; i<n; i++){
        printf("Enter ele of set2: ");
        scanf("%s", &a2[i].ele);
        printf("Enter mv of set2 :");
        scanf("%f", &a2[i].mv);
    }
    printf("A: ");
    printSet(a1, n);
    printf("B: ");
    printSet(a2, n);

    FuzzySet unionSet[n];
    FuzzySet intersection[n];
    FuzzySet difference[n];
    FuzzySet complement[n];

    fuzzyUnion(a1, a2, n, unionSet);
    
    printf("A U B: ");
    printSet(unionSet, n);

    fuzzyIntersection(a1, a2, n, intersection);
    printf("A ^ B: ");
    printSet(intersection, n);

    fuzzyComplement(a1, n, complement);
    printf("A`: ");
    printSet(complement, n);

    fuzzyDifference(a1, a2, n, difference);
    printf("A - B: ");
    printSet(difference, n);
    
}

