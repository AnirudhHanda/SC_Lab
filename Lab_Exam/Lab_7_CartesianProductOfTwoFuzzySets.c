#include<stdio.h>

typedef struct{
    char ele;
    float mv;
} FuzzySet;

int main(){
    int n, m;
    printf("Enter size of set1: ");
    scanf("%d", &n);
    printf("Enter the size of set2: ");
    scanf("%d", &m);

    FuzzySet set1[n], set2[m];
    float rel[n][m];

    printf("\nEnter set1: \n");
    for(int i = 0; i<n; i++){
        printf("Enter the element of set1: ");
        scanf("%s", &set1[i].ele);
        printf("Enter the mv of set1: ");
        scanf("%f", &set1[i].mv);
    }

    printf("\nEnter set2: \n");
    for(int i = 0; i<m; i++){
        printf("Enter the element of set2: ");
        scanf("%s", &set2[i].ele);
        printf("Enter the mv of set2: ");
        scanf("%f", &set2[i].mv);
    }

    printf("\nSet1: ");
    for(int i = 0; i<n; i++){
        printf("(%c, %.2f)", set1[i].ele, set1[i].mv);
    }

    printf("\nSet2: ");
    for(int i = 0; i<m; i++){
        printf("(%c, %.2f)", set2[i].ele, set2[i].mv);
    }

    // Finding Cartesian product (relation) and storing into rel
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            rel[i][j] = (set1[i].mv < set2[j].mv)?set1[i].mv:set2[j].mv;
        }
    }

    // printing the cartesian product
    printf("\n\n----Cartesian Product----\n");
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            printf("%.2f  ", rel[i][j]);
        }
        printf("\n");
    }

    printf("\n\n");
}