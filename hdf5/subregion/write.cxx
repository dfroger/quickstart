#include "H5Cpp.h"
#include <iostream>
/*
A common requirement is to write or read only a part of a file instead of the
whole file.

The following program writes a array of dimensions (4,3,2), but store only in
memory an array of size (3,2), and loops with 4 iterations on the first array
dimension.
*/

using namespace std;
 
using namespace H5;

int main ()
{
    // Set dimensions.
    const unsigned int ndim = 3;
    const unsigned int nz = 4;
    const unsigned int ny = 3;
    const unsigned int nx = 2;

    // Create space for data.
    double phi[ny*nx];

    // Open file with write mode, and create two groups in it.
    H5File file("data.h5", H5F_ACC_TRUNC);
    file.createGroup("/data");

    // Create a dataset for phi.
    hsize_t dimzyx[ndim] = {nz,ny,nx};
    DataSpace dataspace(ndim, dimzyx);
    DataSet dataset = file.createDataSet("/data/phi", PredType::NATIVE_DOUBLE, dataspace);

    // Phi in memory
    hsize_t memspace_start[ndim-1];
    memspace_start[0] = 0;
    memspace_start[1] = 0;
    hsize_t memspace_size[ndim-1];
    memspace_size[0] = ny;
    memspace_size[1] = nx;
    hsize_t dimyx[2] = {ny,nx};
    DataSpace memspace(2,dimyx);
    memspace.selectHyperslab(H5S_SELECT_SET,memspace_size,memspace_start);

    // Phi in dataspace (ie, in file)
    hsize_t dataspace_start[ndim];
    dataspace_start[1] = 0;
    dataspace_start[2] = 0;
    hsize_t dataspace_size[ndim];
    dataspace_size[0] = 1;
    dataspace_size[1] = ny;
    dataspace_size[2] = nx;

    // Compute and write z,phi
    for (unsigned int iz=0 ; iz<nz ; iz++) {

        // Set phi data.
        for (unsigned int iy=0 ; iy<ny ; iy++) {
        for (unsigned int ix=0 ; ix<nx ; ix++) {
            phi[nx*iy + ix] = iz*100 + iy*10 + ix;
        }}

        // Select phi in dataset (ie, in file)
        dataspace_start[0] = iz;
        dataspace.selectHyperslab(H5S_SELECT_SET,dataspace_size,dataspace_start);

        // Write phi
        dataset.write(phi, PredType::NATIVE_DOUBLE, memspace, dataspace);
    }
    return 0;
}
