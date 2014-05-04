#include <mpi.h>
#include <stdio.h>
#include "master.h"

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
	meta_init(&meta, 1, 2, 3, 1, 5.0);
	int n_slaves = 3;
	int data_size = 7;
	int max = 9/n_slaves;
	int i;

	for(i = 0; i < n_slaves; i++) {
		master_update_metadata(&meta, &data_size, max);
		meta_print(&meta);
	}

	//End MPI
	MPI_Finalize();
}
