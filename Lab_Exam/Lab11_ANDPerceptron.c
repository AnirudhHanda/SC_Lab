#include <stdio.h>

typedef struct {
    char ele;
    float mv;
} FuzzySet;

int main() {
    int inp_vec[4][2] = {{1, 1},
                          {1, -1},
                          {-1, 1},
                          {-1, -1}
                                };

    int tar_vec[4] = {1, -1, -1, -1};

    // int e = 2;
    float theta = 0;
    float alpha = 1;

    int c_out[4];
    float net_inp[4];
    float w_updation[4][3];
    float w_new[4][3];

    for(int e = 0; e<2; e++){
        for(int i = 0; i<4; i++){
            // calculating net input
            if(i == 0 && e == 0){
                net_inp[i] = (inp_vec[i][0] * 0) + (inp_vec[i][1] * 0) + 0;
            }else{
                net_inp[i] = (inp_vec[i][0] * w_new[i-1][0]) + (inp_vec[i][1] * w_new[i-1][1]) + w_new[i-1][2];
            }

            // calculated output
            if(net_inp[i] > theta){
                c_out[i] = 1;
            } else if(net_inp[i] < (-theta)){
                c_out[i] = -1;
            } else{
                c_out[i] = 0;
            }

            // if calculated output is not equal to target
            // weights change
            if(c_out[i] != tar_vec[i]){
                w_updation[i][0] = alpha * tar_vec[i] * inp_vec[i][0];
                w_updation[i][1] = alpha * tar_vec[i] * inp_vec[i][1];
                w_updation[i][2] = alpha * tar_vec[i];
            } else{
                w_updation[i][0] = 0;
                w_updation[i][1] = 0;
                w_updation[i][2] = 0;
            }

            // weight updation
            if(i == 0 && e == 0){
                w_new[i][0] = 0 + w_updation[i][0];
                w_new[i][1] = 0 + w_updation[i][1];
                w_new[i][2] = 0 + w_updation[i][2];
            } else{
                w_new[i][0] = w_new[i-1][0] + w_updation[i][0];
                w_new[i][1] = w_new[i-1][1] + w_updation[i][1];
                w_new[i][2] = w_new[i-1][2] + w_updation[i][2];
            }
        }
    }

    printf("\nx1\tx2\tt\tYin\tY\tdW1\tdW2\tdB\tW1\tW2\tB\n");
    for(int i = 0; i<4; i++){
        printf("%d\t%d\t%d\t%.1f\t%d\t%.1f\t%.1f\t%.1f\t%.1f\t%.1f\t%.1f\n", inp_vec[i][0], inp_vec[i][1], tar_vec[i], net_inp[i], c_out[i], w_updation[i][0], w_updation[i][1], w_updation[i][2], w_new[i][0], w_new[i][1], w_new[i][2]);
    }

    return 0;
}
