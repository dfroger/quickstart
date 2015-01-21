#include "H5Cpp.h"
 
using namespace H5;

int main ()
{
    // Set dimensions.
    const int	ndim = 2;
    const int ny = 3;
    const int nx = 4;

    // Create some data.
    double meshy[ny] = {-1., 0., 1. };
    double meshx[nx] =  {5.1, 5.2, 5.3, 5.4};
    double phi[ny*nx] = { 0., 1., 2., 3., 10.,11.,12.,13., 20.,21.,22.,23.};

    // Open file with write mode, and create two groups in it.
    H5File file("data.h5", H5F_ACC_TRUNC);
    file.createGroup("/mesh");
    file.createGroup("/data");

    // Create a dataset for meshy.
    hsize_t dimy[1] = {ny};
    DataSpace dataspacey(1, dimy);
    DataSet datasety = file.createDataSet("/mesh/y", PredType::NATIVE_DOUBLE, dataspacey);

    // Create a dataset for meshx.
    hsize_t dimx[1] = {nx};
    DataSpace dataspacex(1, dimx);
    DataSet datasetx = file.createDataSet("/mesh/x", PredType::NATIVE_DOUBLE, dataspacex);

    // Create a dataset for phi.
    hsize_t dimphi[2] = {ny,nx};
    DataSpace dataspacephi(2, dimphi);
    DataSet datasetphi = file.createDataSet("/data/phi", PredType::NATIVE_DOUBLE, dataspacephi);
  
    // Write meshes and phi.
    datasety.write(meshy, PredType::NATIVE_DOUBLE);
    datasetx.write(meshx, PredType::NATIVE_DOUBLE);
    datasetphi.write(phi, PredType::NATIVE_DOUBLE);
 
    return 0;
}
