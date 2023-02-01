#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include "../include/rn.h"
#include "./rn.cpp"


#define NUM_OF_FEATURES 3
#define NUM_OF_EXAMPLE 3
#define NUM_OF_HID_NODES 3
#define NUM_OF_OUT_NODES 1

// Hours of Workout data //
double x1[NUM_OF_EXAMPLE] = {2,5,1};
double _x1[NUM_OF_EXAMPLE];

// Hours of rest data //
double x2[NUM_OF_EXAMPLE] = {8,5,8};
double _x2[NUM_OF_EXAMPLE];

// Muscle gain data //
double y[NUM_OF_EXAMPLE] = {200,90,190};
double _y[NUM_OF_EXAMPLE];


double syn0[NUM_OF_HID_NODES][NUM_OF_FEATURES];
double syn1[NUM_OF_OUT_NODES][NUM_OF_HID_NODES];

int main()
{
    

    weight_random_initialization(NUM_OF_HID_NODES,NUM_OF_FEATURES,syn0);
    weight_random_initialization(NUM_OF_OUT_NODES,NUM_OF_HID_NODES,syn1);
    
    printf("Synapse 0 weights : \n\r");
    for(int i = 0; i < NUM_OF_HID_NODES; i++)
    {
        for(int j = 0; j < NUM_OF_FEATURES; j++)
        {
            printf(" %f ",syn0[i][j]);
        }
        printf("\n\r");
        printf("\n\r");
    }
    
    printf("Synapse 1 weights : \n\r");
    for(int i = 0; i < NUM_OF_OUT_NODES; i++)
    {
        for(int j = 0; j < NUM_OF_FEATURES; j++)
        {
            printf(" %f ",syn1[i][j]);
        }
        printf("\n\r");
        printf("\n\r");
    }
    return 0;
}