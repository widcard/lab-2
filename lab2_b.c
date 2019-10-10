#include <stdio.h>
#include <time.h>
#include "mpi.h"

int main(int argc,char *argv[]){
	printf("WRyyyyyyy");

	int rank,size;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	double start = MPI_Wtime();
	printf("Hello cyu004 and World! from #%d of %d!\n",rank,size);
	MPI_Barrier(MPI_COMM_WORLD);
	double end = MPI_Wtime();
	if(rank ==0)
		printf("Time on rank #%d is %f!\n",rank,end-start);
	MPI_Finalize();
	return 0;

}
