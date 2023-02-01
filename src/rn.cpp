#include "../include/rn.h"
#include <cmath>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>



double single_in_single_out(double input, double weight) 
{
    return (input * weight);
}

double weighted_sum(double * input, double * weight, int LEN)
{
    double output;
    for(int i = 0; i < LEN ; i++)
    {
        output += input[i]*weight[i];
    }
    return output;
}
double multiple_input_single_output(double * input, double * weight, int LEN)
{
    double predicted_value;
    predicted_value = weighted_sum(input , weight, LEN);
    return predicted_value;
}

void elementwise_multiply(double * input_scaler, double * weight_vector, double * output_vector, int LEN)
{
    for(int i = 0; i < LEN; i++)
    {
        output_vector[i] = input_scaler[0] * weight_vector[i];
    }
}

void single_in_multiple_out_nn(double * input_scaler, double * weight_vector, double * output_vector, int LEN)
{
    elementwise_multiply(input_scaler, weight_vector, output_vector, LEN);
}

void matrix_vector_multiply(double *input_vector,
                            int INPUT_LEN,
                            double *output_vector,
                            int OUTPUT_LEN,
                            double weight_matrix[][IN_LEN])
{
    for(int k = 0; k < OUTPUT_LEN; k++)
    {
        for(int i = 0; i < INPUT_LEN; i++)
        {
            output_vector[k] += input_vector[i]*weight_matrix[k][i];
        }
    }
} 

void multiple_input_multiple_output_nn(double * input_vector,
                                       int INPUT_LEN,
                                       double * output_vector,
                                       int OUTPUT_LEN,
                                       double weight_matrix[][IN_LEN])
{
    matrix_vector_multiply(input_vector, INPUT_LEN, output_vector, OUTPUT_LEN, weight_matrix);
}

void hidden_layer_nn(double * input_vector,
                     int INPUT_LEN,
                     int HIDDEN_LEN,
                     double in_to_hid_weights[HID_LEN] [IN_LEN],
                     int OUTPUT_LEN,
                     double hid_to_out_weights[OUT_LEN] [HID_LEN],
                     double * output_vector)
{

    matrix_vector_multiply(input_vector, INPUT_LEN, hidden_pred_vector, OUTPUT_LEN, in_to_hid_weights);
    matrix_vector_multiply(hidden_pred_vector, HIDDEN_LEN, output_vector, OUTPUT_LEN, hid_to_out_weights);
}                     

double find_error(double input, double weight, double expected_value)
{
    return powf(((input * weight) - expected_value),2); 
}

double find_error_simple(double yhat, double y)
{
    return powf((yhat - y),2);
}

void brute_force_learning(double input,
                          double weight,
                          double expected_value,
                          double step_amount,
                          int itr)
{
    double prediction,error;
    double up_prediction, up_error, down_prediction, down_error;
    for(int i = 0; i < itr; i++)
    {
        prediction = input * weight;
        error = powf((prediction - expected_value),2);
        printf("Error : %f Prediction : %f \r\n", error, prediction);
        up_prediction = input * (weight +step_amount);
        up_error = powf((expected_value - up_prediction),2);
        down_prediction = input * (weight - step_amount);
        down_error = powf((expected_value - down_prediction),2);
        if(down_error < up_error)
            weight = weight - step_amount;
        if(down_error > up_error)
            weight = weight + step_amount;    
    }
}        

void normalize_data(double * input_vector, double * output_vector, int LEN)
{
    int i;
    double max = input_vector[0];
    for(i = 1; i < LEN; i++)
    {
        if(input_vector[i] > max)
        {
            max = input_vector[i];
        }
    }
    for(i = 0; i < LEN; i++)
    {
        output_vector[i] = input_vector[i] / max;
    }
}

void weight_random_initialization(int HIDDEN_LEN,
                                  int INPUT_LEN,
                                  double weights_matrix[HID_LEN][IN_LEN])
{
    double d_rand;
    srand(2);
    for(int i = 0; i < HIDDEN_LEN; i++)
    {
        for(int j = 0; j < INPUT_LEN; j++)
        {
            d_rand = (rand()%10);
            d_rand /=10;
            weights_matrix[i][j] = d_rand;
        }
    }
}