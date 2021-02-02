#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"
#include "mpi-ext.h"

int main(int argc, char *argv[]) {
  MPI_Init(&argc, &argv);

  void *sendbuf = malloc(10*sizeof(int));
  int sendcounts[1] = {10};
  int sdispls[1] = {0};
  MPI_Datatype sendtype = MPI_INT;
  void *recvbuf = malloc(10*sizeof(int));
  int recvcounts[1] = {10};
  int rdispls[1] = {0};
  MPI_Datatype recvtype = MPI_INT;
  MPI_Comm comm = MPI_COMM_WORLD;
  MPI_Info info = MPI_INFO_NULL;
  MPI_Request request;

  printf("About to call MPIX_Alltoallv_init\n");
  int ret = MPIX_Alltoallv_init(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, info, &request);
  printf("Done call to MPIX_Alltoallv_init - ret value is %d\n", ret);


  MPI_Finalize();
}
