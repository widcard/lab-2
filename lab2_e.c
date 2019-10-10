#include <stdio.h>
#include <time.h>
#include "mpi.h"
int main(int argc,char *argv[]){
	int rank,size,type;
	char m1[32],m2[32];
	MPI_Status status;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	double start = MPI_Wtime();	
	sprintf(m2,"Hello, konodia from #%2d!\n",rank);
	if(rank ==0){
		MPI_Send(m2,32,MPI_CHAR,1,type,MPI_COMM_WORLD);
		MPI_Recv(m1,32,MPI_CHAR,size-1,type,MPI_COMM_WORLD,&status);
		printf("Message at proc #%2d %.31s!\n",rank,m1);
	}else{
		
		MPI_Recv(m1,32,MPI_CHAR,rank-1,type,MPI_COMM_WORLD,&status);

		printf("Message at proc #%2d %.31s!\n",rank,m1);
		MPI_Send(m2,32,MPI_CHAR,(rank+1)%size,type,MPI_COMM_WORLD);
		
	
	}
	

	
	
	double end = MPI_Wtime();
	if(rank == 0){
		
		printf("Time elapsed is %f\n",end-start);
}	
	MPI_Finalize();
	return 0;

}
	