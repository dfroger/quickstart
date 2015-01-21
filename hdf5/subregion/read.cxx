#include <iostream>
#include "H5Cpp.h"

/*
The following program read in the file written by write.cxx the whole array of
dimension (4,3,2), by iterating 4 times on the first dimension and reading only
an array of dimension (3,2) at the same time.
*/

using namespace std;
using namespace H5;

int main(int argc, char** argv)
{
    // Check command line args.
    if (argc !=2)
    {  
        cout << "Usage: main FILE.H5" << endl;
        return 1;
    }

    // Open file with read-only mode.
    H5File file(argv[1], H5F_ACC_RDONLY);

    // Select dataset.
    DataSet dataset = file.openDataSet("/data/phi");

    // Read dimensions.
    DataSpace dataspace = dataset.getSpace();
    int ndim = dataspace.getSimpleExtentNdims();
    hsize_t dims[ndim];
    dataspace.getSimpleExtentDims(dims, NULL);
    hsize_t nz = dims[0];
    hsize_t ny = dims[1];
    hsize_t nx = dims[2];

    // Phi in memory.
    hsize_t memspace_start[ndim-1];
    memspace_start[0] = 0;
    memspace_start[1] = 0;
    hsize_t memspace_size[ndim-1];
    memspace_size[0] = ny;
    memspace_size[1] = nx;
    hsize_t dimyx[2] = {ny,nx};
    DataSpace memspace(2,dimyx);
    memspace.selectHyperslab(H5S_SELECT_SET,memspace_size,memspace_start);

    // Phi in dataspace (ie, in file).
    hsize_t dataspace_start[ndim];
    dataspace_start[1] = 0;
    dataspace_start[2] = 0;
    hsize_t dataspace_size[ndim];
    dataspace_size[0] = 1;
    dataspace_size[1] = ny;
    dataspace_size[2] = nx;

    // Allocate data.
    double *phi = new double[ny*nx];

    // Read and print phi.
    for (unsigned int iz=0 ; iz<nz ; iz++) {

        // Select phi in dataset (ie, in file).
        dataspace_start[0] = iz;
        dataspace.selectHyperslab(H5S_SELECT_SET,dataspace_size,dataspace_start);

        // Read phi.
        dataset.read(phi, dataset.getDataType(), memspace, dataspace);

        // Print phi.
        for (unsigned int iy=0 ; iy<ny ; iy++) {  
            for (unsigned int ix=0 ; ix<nx ; ix++) {  
                cout << phi[iy*nx + ix] << " ";
            }
            cout << endl;
        }
    }
    delete phi;
    return 0;
}
