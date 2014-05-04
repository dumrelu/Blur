#include "metadata.h"

void meta_init(METADATA *meta, int width, int height, filter_type type, int radius, double sigma)
{
        //Set info
        meta->width = width;
        meta->height = height;
	meta->type = type;
        meta->radius = radius;
        meta->sigma = sigma;
}

void meta_print(METADATA *meta)
{
	printf("Metadata:\n");
	printf("\t->width=%d\n", meta->width);
	printf("\t->height=%d\n", meta->height);
	printf("\t->type=%d\n", meta->type);
	printf("\t->radius=%d\n", meta->radius);
	printf("\tsigma->=%lf\n", meta->sigma);
}
