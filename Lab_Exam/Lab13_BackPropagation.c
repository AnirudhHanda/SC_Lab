#include<stdio.h>
#include<math.h>

#define E 2.718281828
#define EPOCHS 50

float activateFunc(float x){
    return 1/(1+exp(-x));
}

float diffActivationFun(float x){
    return activateFunc(x) * (1 - activateFunc(x));
}

void train(int inp_vec[4][2], int tar_vec[4],float *w1,float *w2, float*w0,float *v11,float *v12,float *v21,float *v22,float *v01,float *v02){   
    
    float alpha = 0.25;
    float w_change[3];
    float v_change1[3];
    float v_change2[3];

    for(int e = 0; e < 2; e++){
        printf("EPOCH %d\n", e+1);
        printf("x1\tx2\tt\tw1\tw2\tw0\tv11\tv21\tv01\tv12\tv22\tv02\n");
        for(int i = 0; i<4; i++){
            /* ----------- FORWARD PASS ------------*/
            // calculate the net input at hidden layer
            float zin1 = (inp_vec[i][0] * (*v11)) + (inp_vec[i][1] * (*v21)) + (*v01);
            float zin2 = (inp_vec[i][0] * (*v12)) + (inp_vec[i][1] * (*v22)) + (*v02);

            // calculate the output of hidden units
            float z1 = activateFunc(zin1);
            float z2 = activateFunc(zin2); 

            // calculate the net input at output unit
            float yin = (zin1 * (*w1)) + (zin2 * (*w2)) + (*w0);

            // calculate the output at output unit
            float y = activateFunc(yin);

            /* ----------- BACKWARD PASS ------------*/
            // calculate the error correction term at output
            float del1 = (tar_vec[i] - y) * diffActivationFun(yin);

            w_change[0] = alpha * del1 * z1;
            w_change[1] = alpha * del1 * z2;
            w_change[2] = alpha * del1;

            float delin1 = del1 * (*w1);
            float delin2 = del1 * (*w2);
            
            float delj1 = delin1 * diffActivationFun(zin1);
            float delj2 = delin2 * diffActivationFun(zin2);

            // weight changes between input and hidden layer
            v_change1[0] = alpha * inp_vec[i][0] * delj1;
            v_change1[1] = alpha * inp_vec[i][1] * delj1;
            v_change1[2] = alpha * delj1;

            v_change2[0] = alpha * inp_vec[i][0] * delj2;
            v_change2[1] = alpha * inp_vec[i][1] * delj2;
            v_change2[2] = alpha * delj2;

            *w1 += w_change[0];
            *w2 += w_change[1];
            *w0 += w_change[2];

            *v11 += v_change1[0];
            *v21 += v_change1[1];
            *v01 += v_change1[2];

            *v12 += v_change2[0];
            *v22 += v_change2[1];
            *v02 += v_change2[2];

            printf("%2d\t%2d\t%2d\t%6.3f\t%6.3f\t%6.3f\t%6.3f\t%6.3f\t%6.3f\t%6.3f\t%6.3f\t%6.3f\n", inp_vec[i][0], inp_vec[i][1], tar_vec[i], *w1, *w2, *w0, *v11, *v21, *v01, *v12, *v22, *v02);
        }

    }

}


int main(){
    int inp_vec[4][2] = { {1, 1},
                          {1, -1},
                          {-1, 1},
                          {-1, -1}
                                  };
    int tar_vec[4] = {0, 1, 1, 0};

    float w1 = 0.4;
    float w2 = 0.1;
    float w0 = -0.2;

    float v11 = 0.6;
    float v12 = -0.3;
    float v21 = -0.1;
    float v22 = 0.4;
    float v01 = 0.3;
    float v02 = 0.5;


    train(inp_vec, tar_vec, &w1, &w2, &w0, &v11, &v12, &v21, &v22, &v01, &v02);

    return 0;
}
