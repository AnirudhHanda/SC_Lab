#include <stdio.h>

typedef struct {
    char ele;
    float mv;
} FuzzySet;

int main() {
    int n, m, p;
    printf("Enter size of set1: ");
    scanf("%d", &n);
    printf("Enter the size of set2: ");
    scanf("%d", &m);
    printf("Enter the size of set3: ");
    scanf("%d", &p);

    FuzzySet set1[n], set2[m], set3[p];
    float rel1[n][m]; // Cartesian product matrix
    float rel2[m][p];
    float composition[n][p]; // Max-Min Composition matrix   (rel3)

    // Input fuzzy sets
    printf("\nEnter set1: \n");
    for(int i = 0; i < n; i++) {
        printf("Enter the element of set1: ");
        scanf(" %c", &set1[i].ele);
        printf("Enter the mv of set1: ");
        scanf("%f", &set1[i].mv);
    }

    printf("\nEnter set2: \n");
    for(int i = 0; i < m; i++) {
        printf("Enter the element of set2: ");
        scanf(" %c", &set2[i].ele);
        printf("Enter the mv of set2: ");
        scanf("%f", &set2[i].mv);
    }

    printf("\nEnter set3: \n");
    for(int i = 0; i < p; i++) {
        printf("Enter the element of set3: ");
        scanf(" %c", &set3[i].ele);
        printf("Enter the mv of set3: ");
        scanf("%f", &set3[i].mv);
    }
    printf("\n");
    // printing sets
    printf("set1: ");
    for(int i = 0; i<n; i++){
        printf("(%c, %.2f)", set1[i].ele, set1[i].mv);
    }
    printf("\n");
    
    printf("set1: ");
    for(int i = 0; i<m; i++){
        printf("(%c, %.2f)", set2[i].ele, set2[i].mv);
    }
    printf("\n");
    
    printf("set1: ");
    for(int i = 0; i<p; i++){
        printf("(%c, %.2f)", set3[i].ele, set3[i].mv);
    }
    printf("\n");
    
    // Compute Cartesian product
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            // For Cartesian product, use the minimum membership value
            rel1[i][j] = (set1[i].mv < set2[j].mv) ? set1[i].mv : set2[j].mv;
        }
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < p; j++) {
            // For Cartesian product, use the minimum membership value
            rel2[i][j] = (set2[i].mv < set3[j].mv) ? set2[i].mv : set3[j].mv;
        }
    }

    // Compute Max-Product Composition
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < p; j++) {
            // For Max-Min Composition, find maximum of the minimum values
            float max = -1.0; // Initialize to a value that is less than any membership value
            for(int k = 0; k < m; k++) {
                float min_val = (rel1[i][k] * rel2[k][j]);
                max = (min_val > max) ? min_val : max;
            }
            composition[i][j] = max;
        }
    }

    // Print Cartesian product matrix
    printf("\n---- Cartesian Product set1 X set2 ----\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("%.2f\t", rel1[i][j]);
        }
        printf("\n");
    }

    printf("\n---- Cartesian Product set2 X set3 ----\n");
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < p; j++) {
            printf("%.2f\t", rel2[i][j]);
        }
        printf("\n");
    }

    // Print Max-Min Composition matrix
    printf("\n---- Max-Min Composition rel1 o rel2----\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < p; j++) {
            printf("%.2f\t", composition[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    return 0;
}