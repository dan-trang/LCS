/*******************************************************
 * Daniel Trang
 * CS350: Longest Common Subsequence
 * 
 * This file contains implementation for the LCS algorithm.
 * LCS is used in the diff function as well as being
 * prominently used in bioinformatics.
 * 
 * There are two approaches to the solution: brute-force
 * and dynamic programming. Of course, DP is more efficient
 * in that we can use memoization or tabulation to store
 * solutions of the subproblems that make up the final answer.
 * Both approaches will be tested for worst, best, and average
 * case efficiency.
 * *****************************************************/

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <random>
#include <chrono>
using namespace std;


///// BRUTE FORCE METHOD /////
int LCS(char * A, char * B, int a, int b);
int LCS_dynamic(char * A, char * B, int a, int b);
void populate(char randomString[], int size);

int main(){
    srand(time (NULL));          //seeds random using current time, call once only
    int max_sample_size = 25;    //control variable for test cases
    int i = 10;                 
    int LCS_length = 0;
    
    while (i <= max_sample_size){
        char A[i];           //to contain random string 1
        char B[i];           //to contain random string 2

        populate(A, i);
        populate(B, i);

        auto start = chrono::steady_clock::now();
        LCS_length = LCS(A, B, i, i);               //i used for both A and B
        auto end = chrono::steady_clock::now();

        cout << "LCS length is " << LCS_length << " characters long." << endl;

        cout << "Sample Size [" << i << "] ";
        cout << "Elapsed time in milliseconds: ";
        cout << chrono::duration_cast<chrono::milliseconds>(end - start).count();
        cout << endl;
        
        i += 1;
    }
    return 0;
}

//populate character array with a random characters that make up a string 
void populate(char randomString[], int size){
    int random = rand();
    random_device rd;
    mt19937 gen(rd() * random);                          //best case no random, worst case no match, avg use random
    uniform_int_distribution<> distr(65, 90);   //65-90 is the ASCII for A-Z
    
    for (int i = 0; i < size; i++){
        randomString[i] = distr(gen);     //integer distr(gen) converted --> ASCII
    }

    //display array
    for (int i = 0; i< size; i++){
        cout << randomString[i];
    }
    cout << endl;
    return;
}


//main LCS function to calculate maximum length of common subsequence
int LCS(char * A, char * B, int a, int b){
    if (a == 0 || b == 0){
        return 0;
    }
    if (A[a - 1] == B[b - 1]){
        return 1 + LCS(A, B, a-1, b-1);
    }
    else{
        return max(LCS(A, B, a, b-1), LCS (A, B, a-1, b));
    }
}

int LCS_dynamic(char * A, char * B, int a, int b){
    int C[a+1][b+1];
    for (int i = 0; i < b; i++){    //Initialize first row and column to 0
        C[0][i] = 0;
        C[i][0] = 0;
    }
    for (int i = 0; i < a; i++){
        for (int j = 0; j < b; j++){
            if (A[i] == B[j]){
                C[i][j] = C[i-1][j-1] + 1;
            }
            else if (C[i][j-1] > C[i-1][j]){
                C[i][j] = C[i][j-1];
            }
            else {//if (C[i][j-1] <= C[i-1][j])
                C[i][j] = C[i-1][j];
            }
        }
    }
    return C[a][b];
}