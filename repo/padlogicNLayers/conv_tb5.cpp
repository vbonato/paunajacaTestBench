#include <cstdio>
#include <cstdlib>

#include "conv_tb5.h"
#include "conv5.h"

int main(void) {
    type_t *I1 = (type_t *) malloc(C1 * H1 * H1 * sizeof(type_t));
    type_t *W1 = (type_t *) malloc(M1 * C1 * R1 * R1 * sizeof(type_t));
    type_t *OL1 = (type_t *) calloc(M1 * E1 * E1, sizeof(type_t));
    type_t *I2 = (type_t *) malloc(C2 * H2 * H2 * sizeof(type_t));
    type_t *W2 = (type_t *) malloc(M2 * C2 * R2 * R2 * sizeof(type_t));
    type_t *OL2 = (type_t *) calloc(M2 * E2 * E2, sizeof(type_t));
    type_t *I3 = (type_t *) malloc(C3 * H3 * H3 * sizeof(type_t));
    type_t *W3 = (type_t *) malloc(M3 * C3 * R3 * R3 * sizeof(type_t));
    type_t *OL3 = (type_t *) calloc(M3 * E3 * E3, sizeof(type_t));
    type_t *I4 = (type_t *) malloc(C4 * H4 * H4 * sizeof(type_t));
    type_t *W4 = (type_t *) malloc(M4 * C4 * R4 * R4 * sizeof(type_t));
    type_t *OL4 = (type_t *) calloc(M4 * E4 * E4, sizeof(type_t));
    type_t *I5 = (type_t *) malloc(C5 * H5 * H5 * sizeof(type_t));
    type_t *W5 = (type_t *) malloc(M5 * C5 * R5 * R5 * sizeof(type_t));
    type_t *OL5 = (type_t *) calloc(M5 * E5 * E5, sizeof(type_t));

    srand(1);
    for(unsigned j = 0; j < C1 * H1 * H1; j++)
        I1[j] = rand() % RANDROOF;
    for(unsigned j = 0; j < C2 * H2 * H2; j++)
        I2[j] = rand() % RANDROOF;
    for(unsigned j = 0; j < C3 * H3 * H3; j++)
        I3[j] = rand() % RANDROOF;
    for(unsigned j = 0; j < C4 * H4 * H4; j++)
        I4[j] = rand() % RANDROOF;
    for(unsigned j = 0; j < C5 * H5 * H5; j++)
        I5[j] = rand() % RANDROOF;
    for(unsigned j = 0; j < M1 * C1 * R1 * R1; j++)
        W1[j] = rand() % RANDROOF;
    for(unsigned j = 0; j < M2 * C2 * R2 * R2; j++)
        W2[j] = rand() % RANDROOF;
    for(unsigned j = 0; j < M3 * C3 * R3 * R3; j++)
        W3[j] = rand() % RANDROOF;
    for(unsigned j = 0; j < M4 * C4 * R4 * R4; j++)
        W4[j] = rand() % RANDROOF;
    for(unsigned j = 0; j < M5 * C5 * R5 * R5; j++)
        W5[j] = rand() % RANDROOF;

    // Perform convolutions
    conv1(I1, W1, OL1);
    conv2(I2, W2, OL2);
    conv3(I3, W3, OL3);
    conv4(I4, W4, OL4);
    conv5(I5, W5, OL5);

    // Output results
    for(int j = 0; j < M5 * E5 * E5; j++) {
        printf("%x ", OL5[j]);
    }

    // Write output to files
    FILE *opf1 = fopen("output1.bin", "wb");
    fwrite(OL1, sizeof(type_t), M1 * E1 * E1, opf1);
    fclose(opf1);
    FILE *opf2 = fopen("output2.bin", "wb");
    fwrite(OL2, sizeof(type_t), M2 * E2 * E2, opf2);
    fclose(opf2);
    FILE *opf3 = fopen("output3.bin", "wb");
    fwrite(OL3, sizeof(type_t), M3 * E3 * E3, opf3);
    fclose(opf3);
    FILE *opf4 = fopen("output4.bin", "wb");
    fwrite(OL4, sizeof(type_t), M4 * E4 * E4, opf4);
    fclose(opf4);
    FILE *opf5 = fopen("output5.bin", "wb");
    fwrite(OL5, sizeof(type_t), M5 * E5 * E5, opf5);
    fclose(opf5);

    // Free allocated memory
    if(I1) free(I1);
    if(W1) free(W1);
    if(OL1) free(OL1);
    if(I2) free(I2);
    if(W2) free(W2);
    if(OL2) free(OL2);
    if(I3) free(I3);
    if(W3) free(W3);
    if(OL3) free(OL3);
    if(I4) free(I4);
    if(W4) free(W4);
    if(OL4) free(OL4);
    if(I5) free(I5);
    if(W5) free(W5);
    if(OL5) free(OL5);

    return EXIT_SUCCESS;
}