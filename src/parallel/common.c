#include "common.h"

void create_pixel_type(MPI_Datatype *type)
{
	//Prepare params
	int count = 1;
	int blocklengths[1] = { 3 };
	int offsets[1] = { 0 };
	MPI_Datatype oldtypes[1] = { MPI_UNSIGNED_CHAR };

	//Create type
	MPI_Type_struct(count, blocklengths, offsets, oldtypes, type);

	//Commit type
	MPI_Type_commit(type);
}
