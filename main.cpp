// BSCH - Distributed Systems
// Assignment 1
//mohamed fadel bucharaya el manssouri
//SN: 3089448

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

    //identifying the remainder of question 1. To use it in an if statment to output error incase remainder!=0
    //int count = arraySize / world_rank;
    int devisionRemainder = arraySize % world_size;

    //print student details once, when process 0 starts and stop other processes using MPI barrier
    if (world_rank == 0){
        std::cout << "student name: " << FullName << '\n' <<"student number: "<< StudentNumber << '\n'<<'\n';
    }
    MPI_Barrier(MPI_COMM_WORLD);



    //console error if array size can't be evenly divided between processes
    if (devisionRemainder != 0 && world_rank == 0){
        std::cout << '\n' << "ERROR: can't evenly devid array size on " << world_size << " processes." << '\n';
        MPI_Abort(MPI_COMM_WORLD, 1);
    }

    //deviding array size evenly to processes
    //for(int i=world_rank; i<arraySize; i+=world_size){
    //    a[i] = DO_SOME_WORK 
    //}
    
    //assigning even array size to every process
    int count = arraySize / world_size;
    int startindex = world_rank * count;
    int endindex = startindex + count;  //process 0--->start=0*100=0--->end=0+100=100 //process 2--->start=2*100=200--->end=200+100=300 ...for np=4
    //debugging code:
    std::cout << '\n' <<"process: " << world_rank << " has chunk of array from index " << startindex << " to index " << endindex - 1 << '\n';








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
        std::cout <<'\n'<< "its working" << std::endl;
    }
    //MPI_Barrier(MPI_COMM_WORLD);

    //Finalizing the MPI environment
    MPI_Finalize();

    //return status 0 to the OS
    return 0;
}