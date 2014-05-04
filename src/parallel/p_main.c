#include <mpi.h>
#include <stdio.h>
#include "metadata.h"

int main(int argc, char *argv[]) {
	int world_size, world_rank;

	//Init
  	MPI_Init(NULL, NULL);
  
  	//Get number of procs
  	MPI_Comm_size(MPI_COMM_WORLD, &world_size);
  
  	//Proc rank
  	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

	//Testing METADATA
	METADATA meta;
	meta_init(&meta, 1, 2, 10, 3, 4.1);
	meta_print(&meta);

	//End MPI
	MPI_Finalize();
}
