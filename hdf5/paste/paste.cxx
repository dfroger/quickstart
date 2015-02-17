#include <iostream>

#include "H5Cpp.h"

using namespace std;
using namespace H5;

/* Open an existing HDF5 file, and override (paste) a region in it,
 * without reading the whole file.
 *
 * Create input data first:
 *     cd quickstart/hdf5/read_write/
 *     make
 *     cd quickstart/hdf5/paste
 *     ../read_write/write # create data.h5
 *
 * Then paste values in the existing file:
 *     ./paste data.h5
 */

int main(int argc, char* argv[])
{
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " data.h5" << endl;
        return 1;
    }

    char* filename = argv[1];

    // Set dimensions.
    const unsigned int ndim = 2;
    const unsigned int ny = 3;
    const unsigned int nx = 4;

    // Create space for data.
    double phi[nx];

    // Open exiting file with read/write mode.
    H5File file;
    file.openFile(filename,H5F_ACC_RDWR);

    // Select dataset.
    DataSet dataset = file.openDataSet("/data/phi");
    DataSpace dataspace = dataset.getSpace();
  
    // Phi in memory
    hsize_t memspace_start[ndim-1];
    memspace_start[0] = 0;
    hsize_t memspace_size[ndim-1];
    memspace_size[0] = nx;
    hsize_t dimx[2] = {nx};
    DataSpace memspace(1,dimx);
    memspace.selectHyperslab(H5S_SELECT_SET,memspace_size,memspace_start);

    // Phi in dataspace (ie, in file)
    unsigned int iy = 1;
    hsize_t dataspace_start[ndim];
    dataspace_start[0] = iy;
    dataspace_start[1] = 0;
    hsize_t dataspace_size[ndim];
    dataspace_size[0] = 1;
    dataspace_size[1] = nx;
    dataspace.selectHyperslab(H5S_SELECT_SET,dataspace_size,dataspace_start);

    // Set phi data.
    for (unsigned int ix=0 ; ix<nx ; ix++) {
        phi[ix] = 99;
    }

    // Write phi
    dataset.write(phi, PredType::NATIVE_DOUBLE, memspace, dataspace);
 
    return 0;
}

