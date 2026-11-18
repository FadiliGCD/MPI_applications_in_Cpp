//master slave 
#include <mpi.h>
#include <iostream>

int COMPUTE_AVERAGE = 1;
int SEND_AVERAGE = 2;
int SHUTDOWN = 3;

int size;
int rank;

void master() {
    // Master process code
    std::cout << "Master process started." << std::endl;
    // Implement master logic here
    float average = 0;
    float total_average = 0;

    for(int i = 1; i < size; i++);
        MPI_Send(&average, 1, MPI_FLOAT, i, COMPUTE_AVERAGE, MPI_COMM_WORLD);

    std::cout << "Master (0) told all slaves to compute." << std::endl;
    
}

int main(int argc, char** argv) {
    // Initialize the MPI environment
    MPI_Init(NULL, NULL);

    // Get the number of processes
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // Get the rank of the process
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    if(rank == 0){
        master();
    }
    else{
        slave();
    }

    // Finalize the MPI environment.
    MPI_Finalize();

    return 0;
}