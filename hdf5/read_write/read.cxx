#include <iostream>
 
#include "H5Cpp.h"

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
    DataSet datasety = file.openDataSet("/mesh/y");
    DataSet datasetx = file.openDataSet("/mesh/x");
    DataSet datasetphi = file.openDataSet("/data/phi");

    // Allocate data.
    double *meshy = new double[datasety.getSpace().getSimpleExtentNpoints()];
    double *meshx = new double[datasetx.getSpace().getSimpleExtentNpoints()];
    double *phi = new double[datasetphi.getSpace().getSimpleExtentNpoints()];

    // Read phi and meshes.
    datasety.read(meshy, datasety.getDataType());
    datasetx.read(meshx, datasetx.getDataType());
    datasetphi.read(phi, datasetphi.getDataType());

    // Read dimensions.
    DataSpace dataspace = datasetphi.getSpace();
    int ndim = dataspace.getSimpleExtentNdims();
    hsize_t dims[ndim];
    dataspace.getSimpleExtentDims(dims, NULL);
    hsize_t ny = dims[0];
    hsize_t nx = dims[1];

    // Print data.
    hsize_t iy, ix;
    for (iy=0 ; iy<ny ; iy++)
    {  
        for (ix=0 ; ix<nx ; ix++)
        {  
            cout << meshy[iy] << " " << meshx[ix] << " " << phi[iy*nx + ix] << endl;
        }
        cout << endl;
    }
    return 0;
}
