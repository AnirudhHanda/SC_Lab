#include <stdio.h>

typedef struct {
    char ele;
    float mv;
} FuzzySet;

int main() {
    // int n = 5;
    // printf("Enter size of relation: ");
    // scanf("%d", &n);

    // float rel[n][n]; // Cartesian product matrix

    float rel[5][5] = { {1.0, 1.0, 0.0, 0.0, 0.0},
                        {1.0, 1.0, 0.0, 0.0, 1.0},
                        {0.0, 0.0, 1.0, 0.0, 0.0},
                        {0.0, 0.0, 0.0, 1.0, 0.0},
                        {0.0, 1.0, 0.0, 0.0, 1.0}
                      };

    // Input fuzzy sets
    // printf("\nEnter rel matrix: \n");
    // for(int i = 0; i < n; i++) {
    //     printf("Enter row %d: ", i);
    //     for(int j = 0; j<n; j++){
    //         scanf("%f ", &rel[i][j]);
    //     }
    // }

    // printing the relation
    printf("\n----Tolerance Relation----\n");
    for(int i = 0; i<5; i++){
        for(int j = 0; j<5; j++){
            printf("%.2f\t", rel[i][j]);
        }
        printf("\n");
    }


    // Compute Max-Min Composition
    for(int  p= 0; p<5-1; p++){
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                // For Max-Min Composition, find maximum of the minimum values
                float max = -1.0; // Initialize to a value that is less than any membership value
                for(int k = 0; k < 5; k++) {
                    float min_val = (rel[i][k] < rel[k][j]) ? rel[i][k] : rel[k][j];
                    max = (min_val > max) ? min_val : max;
                }
                rel[i][j] = max;
            }
        }
    }


    // Print Max-Min Composition matrix
    printf("\n----rel^%d: Equivalence Relation----\n", 5-1);
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            printf("%.2f\t", rel[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    return 0;
    
}