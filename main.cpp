// BSCH - Distributed Systems
// Assignment 1

#include <iostream>
#include <fstream>
#include <mpi.h>
#include <string>
#include <cstdlib>

//Global variables
const int arraySize = 400;
int world_size, world_rank; 
int numberArray[arraySize];

//student details
int StudentNumber = 3089448; 
std::string FullName = "Mohamed Fadel Bucharaya El Manssouri"; 


int main(int argc, char** argv) {
    
    // Initializing the MPI environment
    MPI_Init(NULL, NULL);

    //how many processes in the MPI instance
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    //which rank we are in
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    //print student details once, when process 0 starts and stop other processes using MPI barrier
    if (world_rank == 0){
        std::cout << "student name: " << FullName << '\n' <<"student number: "<< StudentNumber << '\n' << "-----------------------------------" << '\n' <<" " <<'\n';
    }
    MPI_Barrier(MPI_COMM_WORLD);





    //sychnorize after work finishes
    MPI_Barrier(MPI_COMM_WORLD);

    //node's benchmark data format:
    //Node [rank] start: [startTime]
    //Node [rank] end: [endTime] 
    //Node [rank] time elapsed: [timeElapsed]

    // my machine's detail: OS, processor model and number of cores, and system memoryin GB.

    //dubugging code
    std::cout << "Process: " <<world_rank << " -of size: " << world_size << " is running "<< std::endl;

    //print debbuging code "its working" only when process 0 starts and stop other processes using MPI barrier
    MPI_Barrier(MPI_COMM_WORLD);
    if (world_rank == 0){
        std::cout << '\n' << "-----------------------------------" << '\n'<< "its working" << std::endl;
    }
    //MPI_Barrier(MPI_COMM_WORLD);

    //Finalizing the MPI environment
    MPI_Finalize();

    //return status 0 to the OS
    return 0;
}