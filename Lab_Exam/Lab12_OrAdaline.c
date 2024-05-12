#include<stdio.h>
#define EPOCHS 50

void train(int inp_vec[4][2], int tar_vec[4], float *w1, float *w2, float *w3){
    // theta is not considered here
    float alpha = 0.1;
    float net_inp[4];
    float tm_yin[4];
    float w_updation[4][3];
    float mse;
    float sumMSE;
    float threshold = 1.4;

    for(int e = 0; e<EPOCHS; e++){
        sumMSE = 0.0;
        printf("EPOCH %d\n", e+1);
        printf("x1\tx2\t t\t  Yin\t  (t-Yin)\t  dW\t  dW2\t  db\t  W1\t  W2\t  b\tE(t-Yin^2)\n");
        for(int i = 0 ; i<4; i++){

            // calculating the net input
            net_inp[i] = (inp_vec[i][0] * (*w1)) + (inp_vec[i][1] * (*w2)) + *w3;

            // error term
            tm_yin[i] = tar_vec[i] - net_inp[i];

            // weight change
            w_updation[i][0] = alpha * inp_vec[i][0] * (tm_yin[i]);
            w_updation[i][1] = alpha * inp_vec[i][1] * (tm_yin[i]);
            w_updation[i][2] = alpha * (tm_yin[i]);

            // weight updation
            *w1 += w_updation[i][0];
            *w2 += w_updation[i][1];
            *w3 += w_updation[i][2];

            mse = tm_yin[i] * tm_yin[i];
            sumMSE+=mse;

            printf("%2d\t%2d\t%2d\t%6.3f\t  %6.3f\t%6.3f\t%6.3f\t%6.3f\t%.3f\t%.3f\t%.3f\t%.3f\n", inp_vec[i][0], inp_vec[i][1], tar_vec[i], net_inp[i], tm_yin[i], w_updation[i][0], w_updation[i][1], w_updation[i][2], *w1, *w2, *w3, mse);
        }
        printf("Error term for this Epoch: %.3f\n", sumMSE);
        if (sumMSE < threshold) {
            printf("(error < threshold) i.e (%.3f < %.3f) so we stop\n", sumMSE, threshold);
            break;
        } else{
            printf("(error > threshold) i.e (%.3f > %.3f) so train\n", sumMSE, threshold);
        }

        printf("\n");
    }
}

int main(){
    int inp_vec[4][2] = { {1, 1},
                          {1, -1},
                          {-1, 1},
                          {-1, -1}
                                  };

    int tar_vec[4] = {1, 1, 1, -1};

    float w1 = 0.1;
    float w2 = 0.1;
    float w3 = 0.1;

    train(inp_vec, tar_vec, &w1, &w2, &w3);

}