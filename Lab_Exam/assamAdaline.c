//simulate the behaviour of OR gate using Adaline network in for bipolar inputs and targets
//Azzam khan's code
#include <stdio.h>
#include <math.h>
//azzam khan
#define LEARNING_RATE 0.1
#define EPOCHS 150
//azzam khan
//azzam khan
displayEPOCH(int x1,int x2,int target,float DeltaW1,float DeltaW2,float DeltaBias,float w1,float w2,float bias,float yin)
{
    float x=target-yin;
    printf("%2d  %2d  1  %4d  %8.3f  %7.3f  %7.3f  %7.3f  %8.3f  %6.3f  %6.3f  %6.3f  %6.3f",x1,x2,target,yin,x,DeltaW1,DeltaW2,DeltaBias,w1,w2,bias,x*x);
}
//azzam khan
void train(int inputs[4][2], int targets[4], float *w1, float *w2, float *bias) {
    float threshold=2;
    float DeltaW1,DeltaW2,DeltaBias,yin;
    int epoch,i,target,x1,x2;
    for (epoch = 0; epoch < EPOCHS; epoch++) {
        printf("EPOCH-%d\n",epoch+1);
        printf("x1  x2  1  target(t)  Yin    t-yin  deltaW1  deltaW2  deltaBias  w1      w2       b    (t-yin)^2\n");
        float error=0.0;
        for (i = 0; i < 4; i++) {
            x1 = inputs[i][0];
            x2 = inputs[i][1];
            target = targets[i];
            yin=  (*w1) * x1 + (*w2) * x2 + *bias;
            error+=(target-yin)*(target-yin);
            DeltaW1=LEARNING_RATE * (target-yin) * x1;
            DeltaW2=LEARNING_RATE * (target-yin) * x2;
            DeltaBias=LEARNING_RATE * (target-yin);
            *w1 += DeltaW1;
            *w2 +=DeltaW2;
            *bias += DeltaBias;
            displayEPOCH(x1,x2,target,DeltaW1,DeltaW2,DeltaBias,*w1,*w2,*bias,yin);
            printf("\n");
        }
        printf("Error Comes out to be=%.3f\n",error);
        if(error<=threshold)
        {
            printf("error(%.3f)<threshold(%.3f) so we will stop here",error,threshold);
            break;
        }
        else
        printf("error(%.3f)>threshold(%.3f) so another epoch",error,threshold);
        
        printf("\n\n");
    }
}
//azzam khan
//azzam khan
int main() {

    int inputs[4][2] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    int targets[4] = {1, 1, 1, -1};

    float w1 = 0.1;
    float w2 = 0.1;
    float bias =0.1;

    train(inputs, targets, &w1, &w2, &bias);
    //You are successfull in copy-pasting the code
    return 0;
    //azzam khan
}


// ░█████╗░███████╗███████╗░█████╗░███╗░░░███╗     ██╗░░██╗██╗░░██╗░█████╗░███╗░░██╗
// ██╔══██╗╚════██║╚════██║██╔══██╗████╗░████║     ██║░██╔╝██║░░██║██╔══██╗████╗░██║
// ███████║░░███╔═╝░░███╔═╝███████║██╔████╔██║     █████═╝░███████║███████║██╔██╗██║
// ██╔══██║██╔══╝░░██╔══╝░░██╔══██║██║╚██╔╝██║     ██╔═██╗░██╔══██║██╔══██║██║╚████║
// ██║░░██║███████╗███████╗██║░░██║██║░╚═╝░██║     ██║░╚██╗██║░░██║██║░░██║██║░╚███║
// ╚═╝░░╚═╝╚══════╝╚══════╝╚═╝░░╚═╝╚═╝░░░░░╚═╝     ╚═╝░░╚═╝╚═╝░░╚═╝╚═╝░░╚═╝╚═╝░░╚══╝

