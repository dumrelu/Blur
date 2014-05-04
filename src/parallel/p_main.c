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
	MPI_Datatype META;
	meta_create_type(&META);
	if(world_rank == 0) {
		meta_init(&meta, 1, 2, 10, 3, 4.1);
		meta.height = 123;
		MPI_Send(&meta, 1, META, 1, 0, MPI_COMM_WORLD);
	} else {
		MPI_Recv(&meta, 1, META, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		meta_print(&meta);
	}

	//End MPI
	MPI_Finalize();
}
