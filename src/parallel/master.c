#include "master.h"


void master_run(int world_size) 
{
	//Info to be read
	char image_src_name[IMAGE_NAME_LENGHT], image_dest_name[IMAGE_NAME_LENGHT];
	int radius, type;
	double sigma;

	//Read info
	printf("Source image name: "); scanf("%s", image_src_name);
	printf("Destination image name: "); scanf("%s", image_dest_name);
	printf("Radius: "); scanf("%d", &radius);
	printf("Type: "); scanf("%d", &type);
	printf("Sigma: "); scanf("%lf", &sigma);

	//Load image from file
	printf("Loading image \"%s\"...\n", image_src_name);
	IMAGE *src = image_load(image_src_name);

	//Send metadata to the slaves
	master_send_metadata(src, radius, type, sigma, world_size-1);

	//Free memory
	image_free(src);

	//Master finished the work
	printf("DONE!\n");
}

int master_send_metadata(IMAGE *image, int type, int radius, double sigma, int n_slaves)
{
	//Init metadata
	METADATA meta;
	meta_init(&meta, image->width, image->height, type, radius, sigma);
	
	//
	int data_size = image->height - 2*radius;
}

int master_update_metadata(METADATA *meta, int *data_size, int max_size)
{
	if(*data_size == 0) {
		meta->height = 0;
		return 0;
	}

	//Calculate send data lenght and update remaining data
	int actual_data = max_size;
	if(actual_data > *data_size) {
		actual_data = *data_size;
		*data_size = 0;
	} else {
		(*data_size) -= actual_data;
	}

	//The total data length to be sent
	int send_data = actual_data + 2*meta->radius;

	//Update metadata
	meta->height = send_data;

	return *data_size;
}
