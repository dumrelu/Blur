#include <mpi.h>
#include <stdio.h>
#include "metadata.h"
#include "common.h"

int main(int argc, char *argv[]) {
	int world_size, world_rank;

	//Init
  	MPI_Init(NULL, NULL);
  
  	//Get number of procs
  	MPI_Comm_size(MPI_COMM_WORLD, &world_size);
  
  	//Proc rank
  	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

	//Testing METADATA
	pixel pixel;
	MPI_Datatype PIXEL;
	create_pixel_type(&PIXEL);

	if(world_rank == 0) {
		pixel.R = 1; pixel.G = 2; pixel.B = 3;
		MPI_Send(&pixel, 1, PIXEL, 1, 0, MPI_COMM_WORLD);
	} else {
		MPI_Recv(&pixel, 1, PIXEL, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		printf("%d %d %d\n", pixel.R, pixel.G, pixel.B);
	}

	//End MPI
	MPI_Finalize();
}
