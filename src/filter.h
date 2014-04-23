#ifndef FILTER_H
#define FILTER_H

#define PI 3.14159265

typedef struct {
	int radius;
	double **matrix;
	char filter_name[30];
} FILTER;

FILTER *filter_create_avg(int radius);

FILTER *filter_create_gauss(int radius, double sigma);

void filter_print(FILTER *filter);

void filter_free(FILTER *filter);

#endif /*FILTER_H*/
