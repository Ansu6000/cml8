#ifndef _NN_H
#define _NN_H
#define IN_LEN  3
#define OUT_LEN 3
#define HID_LEN 3

#include <stdio.h>
double single_in_single_out(double input, double weight);
double multiple_input_single_output(double * input, double * weight, int LEN);
void single_in_multiple_out_nn(double * input_scaler, double * weight_vector, double * output_vector, int LEN);
void multiple_input_multiple_output_nn(double * input_vector,
                                       int INPUT_LEN,
                                       double * output_vector,
                                       int OUTPUT_LEN,
                                       double weight_matrix[][IN_LEN]);

double hidden_pred_vector[HID_LEN];                                      

void hidden_layer_nn(double * input_vector,
                     int INPUT_LEN,
                     int HIDDEN_LEN,
                     double in_to_hid_weights[HID_LEN] [IN_LEN],
                     int OUTPUT_LEN,
                     double hid_to_out_weights[OUT_LEN] [HID_LEN],
                     double * output_vector); 

double find_error(double input, double weight, double expected_value);
double find_error_simple(double yhat, double y); 
void brute_force_learning(double input,
                          double weight,
                          double expected_value,
                          double step_amount,
                          int itr);   

void normalize_data(double * input_vector, double * output_vector, int LEN);

void weight_random_initialization(int HIDDEN_LEN,
                                  int INPUT_LEN,
                                  double weights_matrix[HID_LEN][IN_LEN]);

#endif
