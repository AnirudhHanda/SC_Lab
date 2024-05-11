#include <stdio.h>

typedef struct {
    char ele;
    float mv;
} FuzzySet;
nm
int main() {
    int n;
    printf("Enter size of relation: ");
    scanf("%d", &n);

    // float rel[n][n]; // Cartesian product matrix

    float rel[n][n] = [ [1.0, 1.0, 0.0, 0.0, 0.0],
                        [1.0, 1.0, 0.0, 0.0, 1.0],
                        [0.0, 0.0, 1.0, 0.0, 0.0],
                        [0.0, 0.0, 0.0, 1.0, 0.0],
                        [0.0, 1.0, 0.0, 0.0, 1.0]
                        ];

    // Input fuzzy sets
    printf("\nEnter rel matrix: \n");
    for(int i = 0; i < n; i++) {
        printf("Enter row %d: ", i);
        for(int j = 0; j<n; j++){
            scanf("%f ", &rel[i][j]);
        }
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

    // Compute Max-Min Composition
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < p; j++) {
            // For Max-Min Composition, find maximum of the minimum values
            float max = -1.0; // Initialize to a value that is less than any membership value
            for(int k = 0; k < m; k++) {
                float min_val = (rel1[i][k] < rel2[k][j]) ? rel1[i][k] : rel2[k][j];
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