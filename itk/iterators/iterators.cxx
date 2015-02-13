#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>

#include <itkImage.h>
#include <itkImageRegionIterator.h>
#include <itkImageRegionConstIterator.h>
#include <itkConstNeighborhoodIterator.h>
#include <itkConvolutionImageFilter.h>
#include <itkImageDuplicator.h>

using namespace std;

// Ok, but return the sum of time of all threads
//double
//get_time()
//{
    //struct rusage ru;
    //getrusage(RUSAGE_SELF, &ru);
    //return (double) ru.ru_utime.tv_sec +
           //((double) ru.ru_utime.tv_usec) / 1.0E6;
//}


float* create_image(size_t s);

double get_time()
{
    struct timeval  tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec) + (tv.tv_usec) / 1.0E6;
}

float
compute_x (size_t const ix, size_t const nx)
{
  // x is in [0,1]
  return (float) ix / (float) nx;
}

float
compute_y (size_t const iy, size_t const ny)
{
  // y is in [0,1]
  return (float) iy / (float) ny;
}

float
compute_f(float const x, float const y)
{
  return cos(x)*sin(y);
}

void
itk_iterators(size_t const nx, size_t const ny, size_t const niter,
              bool const verbose)
{
    // Create tmp image.
    typedef float PixelFloat;
    const size_t ImageDimension = 2;
    typedef itk::Image<PixelFloat, ImageDimension> ImageType;
    ImageType::Pointer tmp = ImageType::New();
    ImageType::IndexType index;
    ImageType::SizeType size;
    ImageType::RegionType region;
    index.Fill(0);
    size[0] = nx+2;
    size[1] = ny+2;
    region.SetIndex(index);
    region.SetSize(size);
    tmp->SetRegions(region);
    tmp->Allocate();

    // Create output image.
    ImageType::Pointer output = ImageType::New();
    index.Fill(0);
    size[0] = nx;
    size[1] = ny;
    region.SetIndex(index);
    region.SetSize(size);
    output->SetRegions(region);
    output->Allocate();

    // tmp iterator.
    typedef itk::ImageRegionIterator<ImageType> IteratorType;
    typedef itk::ImageRegionConstIterator<ImageType> ConstIteratorType;
    IteratorType tmpIt(tmp, tmp->GetLargestPossibleRegion());

    // Initialize tmp image.
    for(tmpIt.GoToBegin(); !tmpIt.IsAtEnd(); ++tmpIt) {
      index = tmpIt.GetIndex();
      size_t ix = index[0];
      size_t iy = index[1];
      float x = compute_x(ix,nx+2);
      float y = compute_y(iy,ny+2);
      tmpIt.Set( compute_f(x,y) );
      }

    // Neighbor tmp iterator.
    typedef itk::ConstNeighborhoodIterator<ImageType> ConstNeighborhoodIteratorType;
    ConstNeighborhoodIteratorType::RadiusType radius;
    radius.Fill(1);
    index[0] = 1;
    index[1] = 1;
    size[0] = nx;
    size[1] = ny;
    region.SetIndex(index);
    region.SetSize(size);
    ConstNeighborhoodIteratorType tmpNeighborConstIt(radius, tmp, region);
    tmpNeighborConstIt.NeedToUseBoundaryConditionOff();

    // Neighbor tmp offsets.
    ConstNeighborhoodIteratorType::OffsetType offset1 = {{-1, 0}};
    ConstNeighborhoodIteratorType::OffsetType offset2 = {{ 1, 0}};
    ConstNeighborhoodIteratorType::OffsetType offset3 = {{ 0,-1}};
    ConstNeighborhoodIteratorType::OffsetType offset4 = {{ 0, 1}};

    // output iterator.
    IteratorType outputIt(output, output->GetLargestPossibleRegion());
    ConstIteratorType outputConstIt(output, output->GetLargestPossibleRegion());

    // tmp inner iteration.
    index[0] = 1;
    index[1] = 1;
    size[0] = nx;
    size[1] = ny;
    region.SetIndex(index);
    region.SetSize(size);
    IteratorType tmpInnerIt(tmp, region);

    double t0 = get_time();
    for(size_t iter = 0; iter < niter; iter++) {
        if (iter%10 == 0) cerr << iter << " " << std::flush;

        tmpNeighborConstIt.GoToBegin();
        outputIt.GoToBegin();

        while( !tmpNeighborConstIt.IsAtEnd() ) {
            outputIt.Set((tmpNeighborConstIt.GetPixel(offset1)
                        + tmpNeighborConstIt.GetPixel(offset2)
                        + tmpNeighborConstIt.GetPixel(offset3)
                        + tmpNeighborConstIt.GetPixel(offset4))/4.);
            ++tmpNeighborConstIt;
            ++outputIt;
        }

        tmpInnerIt.GoToBegin();
        outputConstIt.GoToBegin();

        while( !tmpInnerIt.IsAtEnd() ) {
            tmpInnerIt.Set( outputConstIt.Get() );
            ++tmpInnerIt;
            ++outputConstIt;
        }

    }
    cerr << endl;

    double t1 = get_time();
    cout << "itk_iterator " << ny << " " << nx << " " << t1-t0 << endl;

    if (verbose) {
        cerr << "tmp:" << endl;
        for (size_t iy = 0 ; iy < ny+2 ; ++iy) {
            index[1] = iy;
            cerr << iy << ": ";
            for (size_t ix = 0 ; ix < nx+2 ; ++ix) {
                index[0] = ix;
                cerr << tmp->GetPixel(index) << " ";
            }
            cerr << endl;
        }
    }
}

void
c_pointers(size_t const nx, size_t const ny, size_t const niter,
           bool const verbose)
{
    // Create tmp image.
    size_t tmp_size = (ny*2) * (nx*2);
    //float* tmp = (float*) malloc(sizeof(float) * tmp_size);
    float* tmp = create_image(tmp_size);
    
    // Initialize tmp image.
    for (size_t iy = 0 ; iy < ny+2 ; ++iy) {
        float y = compute_y(iy,ny+2);
        for (size_t ix = 0 ; ix < nx+2 ; ++ix) {
            float x = compute_x(ix,nx+2);
            tmp[iy*(nx+2) + ix] = compute_f(x,y);
        }
    }

    // Create output image.
    size_t output_size = ny*nx;
    //float* output = (float*) malloc(sizeof(float) * output_size);
    float* output = create_image(output_size);

    // Compute output image.
    double t0 = get_time();
    for(size_t iter = 0; iter < niter; iter++) {
        //if (iter%10 == 0) cerr << iter << " " << std::flush;

        for (size_t iy = 0 ; iy < ny ; ++iy) {
            for (size_t ix = 0 ; ix < ny ; ++ix) {
                output[iy*nx + ix] = ( tmp[ (iy+1 -1)*(nx+2) + ix+1   ]
                                     + tmp[ (iy+1 +1)*(nx+2) + ix+1   ]
                                     + tmp[ (iy+1   )*(nx+2) + ix+1 -1]
                                     + tmp[ (iy+1   )*(nx+2) + ix+1 +1]) / 4.;
            }
        }

        for (size_t iy = 0 ; iy < ny ; ++iy) {
            for (size_t ix = 0 ; ix < ny ; ++ix) {
                tmp[(iy+1)*(nx+2) + ix+1] = output[iy*nx + ix];
            }
        }
    }
    cerr << endl;

    double t1 = get_time();
    cout << "c_pointer " << ny << " " << nx << " " << t1-t0 << endl;

    if (verbose) {
        cerr << "tmp:" << endl;
        for (size_t iy = 0 ; iy < ny+2 ; ++iy) {
            cerr << iy << ": ";
            for (size_t ix = 0 ; ix < nx+2 ; ++ix) {
                cerr << tmp[iy*(nx+2) + ix] << " ";
            }
            cerr << endl;
        }
    }
    
    // Free images.
    free(tmp);
    free(output);
}

void
itk_convolution(size_t const nx, size_t const ny, size_t const niter,
           bool const verbose)
{
    // Create tmp image.
    typedef float PixelFloat;
    const size_t ImageDimension = 2;
    typedef itk::Image<PixelFloat, ImageDimension> ImageType;
    ImageType::Pointer tmp = ImageType::New();
    ImageType::IndexType index;
    ImageType::SizeType size;
    ImageType::RegionType region;
    index.Fill(0);
    size[0] = nx+2;
    size[1] = ny+2;
    region.SetIndex(index);
    region.SetSize(size);
    tmp->SetRegions(region);
    tmp->Allocate();

    // Initialize tmp image.
    typedef itk::ImageRegionIterator<ImageType> IteratorType;
    typedef itk::ImageRegionConstIterator<ImageType> ConstIteratorType;
    IteratorType tmpIt(tmp, tmp->GetLargestPossibleRegion());
    for(tmpIt.GoToBegin(); !tmpIt.IsAtEnd(); ++tmpIt) {
      index = tmpIt.GetIndex();
      size_t ix = index[0];
      size_t iy = index[1];
      float x = compute_x(ix,nx+2);
      float y = compute_y(iy,ny+2);
      tmpIt.Set( compute_f(x,y) );
      }

    // Create kernel
    ImageType::Pointer kernel = ImageType::New();
    index.Fill(0);
    size[0] = 3;
    size[1] = 3;
    region.SetIndex(index);
    region.SetSize(size);
    kernel->SetRegions(region);
    kernel->Allocate();
    index[0] = 0; index[1] = 0; kernel->SetPixel(index, 0);
    index[0] = 0; index[1] = 1; kernel->SetPixel(index, 0.25);
    index[0] = 0; index[1] = 2; kernel->SetPixel(index, 0);
    index[0] = 1; index[1] = 0; kernel->SetPixel(index, 0.25);
    index[0] = 1; index[1] = 1; kernel->SetPixel(index, 0);
    index[0] = 1; index[1] = 2; kernel->SetPixel(index, 0.25);
    index[0] = 2; index[1] = 0; kernel->SetPixel(index, 0);
    index[0] = 2; index[1] = 1; kernel->SetPixel(index, 0.25);
    index[0] = 2; index[1] = 2; kernel->SetPixel(index, 0);

    // Convolution filter
    typedef itk::ConvolutionImageFilter<ImageType> ConvolutionType;
    ConvolutionType::Pointer convolutionFilter = ConvolutionType::New();
    convolutionFilter->SetKernelImage(kernel);

    // Duplicator filter
    typedef itk::ImageDuplicator<ImageType> DuplicatorType;
    DuplicatorType::Pointer duplicator = DuplicatorType::New();

    if (verbose) {
        cerr << "tmp:" << endl;
        for (size_t iy = 0 ; iy < ny+2 ; ++iy) {
            index[1] = iy;
            cerr << iy << ": ";
            for (size_t ix = 0 ; ix < nx+2 ; ++ix) {
                index[0] = ix;
                cerr << tmp->GetPixel(index) << " ";
            }
            cerr << endl;
        }
    }

    double t0 = get_time();
    for(size_t iter = 0; iter < niter; iter++) {
        if (iter%10 == 0) cerr << iter << " " << std::flush;
        convolutionFilter->SetInput(tmp);
        convolutionFilter->Update();
        duplicator->SetInputImage( convolutionFilter->GetOutput() );
        duplicator->Update();
        tmp = duplicator->GetOutput();
    }
    cerr << endl;

    double t1 = get_time();
    cout << "itk_convolution " << ny << " " << nx << " " << t1-t0 << endl;

    if (verbose) {
        cerr << "tmp:" << endl;
        for (size_t iy = 0 ; iy < ny+2 ; ++iy) {
            index[1] = iy;
            cerr << iy << ": ";
            for (size_t ix = 0 ; ix < nx+2 ; ++ix) {
                index[0] = ix;
                cerr << tmp->GetPixel(index) << " ";
            }
            cerr << endl;
        }
    }

}

void
itk_get_buffer_pointer(size_t const nx, size_t const ny, size_t const niter,
              bool const verbose)
{
    // Create tmp image.
    typedef float PixelFloat;
    const size_t ImageDimension = 2;
    typedef itk::Image<PixelFloat, ImageDimension> ImageType;
    ImageType::Pointer tmp = ImageType::New();
    ImageType::IndexType index;
    ImageType::SizeType size;
    ImageType::RegionType region;
    index.Fill(0);
    size[0] = nx+2;
    size[1] = ny+2;
    region.SetIndex(index);
    region.SetSize(size);
    tmp->SetRegions(region);
    tmp->Allocate();

    // Create output image.
    ImageType::Pointer output = ImageType::New();
    index.Fill(0);
    size[0] = nx;
    size[1] = ny;
    region.SetIndex(index);
    region.SetSize(size);
    output->SetRegions(region);
    output->Allocate();

    // tmp iterator.
    typedef itk::ImageRegionIterator<ImageType> IteratorType;
    typedef itk::ImageRegionConstIterator<ImageType> ConstIteratorType;
    IteratorType tmpIt(tmp, tmp->GetLargestPossibleRegion());

    // Initialize tmp image.
    for(tmpIt.GoToBegin(); !tmpIt.IsAtEnd(); ++tmpIt) {
      index = tmpIt.GetIndex();
      size_t ix = index[0];
      size_t iy = index[1];
      float x = compute_x(ix,nx+2);
      float y = compute_y(iy,ny+2);
      tmpIt.Set( compute_f(x,y) );
      }

    float* const outputPt = (float* const) output->GetBufferPointer();
    float* const tmpPt = (float* const) tmp->GetBufferPointer();

    double t0 = get_time();
    for(size_t iter = 0; iter < niter; iter++) {
        //if (iter%10 == 0) cerr << iter << " " << std::flush;

        for (size_t iy = 0 ; iy < ny ; ++iy) {
            for (size_t ix = 0 ; ix < ny ; ++ix) {
                outputPt[iy*nx + ix] = ( tmpPt[ (iy+1 -1)*(nx+2) + ix+1   ]
                                     + tmpPt[ (iy+1 +1)*(nx+2) + ix+1   ]
                                     + tmpPt[ (iy+1   )*(nx+2) + ix+1 -1]
                                     + tmpPt[ (iy+1   )*(nx+2) + ix+1 +1]) / 4.;
            }
        }

        for (size_t iy = 0 ; iy < ny ; ++iy) {
            for (size_t ix = 0 ; ix < ny ; ++ix) {
                tmpPt[(iy+1)*(nx+2) + ix+1] = outputPt[iy*nx + ix];
            }
        }
    }
    cerr << endl;

    double t1 = get_time();
    cout << "itk_get_buffer_pointer " << ny << " " << nx << " " << t1-t0 << endl;

    if (verbose) {
        cerr << "tmp:" << endl;
        for (size_t iy = 0 ; iy < ny+2 ; ++iy) {
            index[1] = iy;
            cerr << iy << ": ";
            for (size_t ix = 0 ; ix < nx+2 ; ++ix) {
                index[0] = ix;
                cerr << tmp->GetPixel(index) << " ";
            }
            cerr << endl;
        }
    }
}
 
int main(int argc, char** argv)
{
    if (argc != 5) {
        cerr << "Usage: " << argv[0] << " NX NY NITER VERBOSE" << endl;
        return 1;
    }

    size_t nx = atoi(argv[1]);
    size_t ny = atoi(argv[2]);
    size_t niter = atoi(argv[3]);

    bool verbose = atoi(argv[4]);

    cerr << "ITK get buffer pointer" << endl;
    itk_get_buffer_pointer(nx,ny,niter,verbose);

    cerr << "C pointers:" << endl;
    c_pointers(nx,ny,niter,verbose);

    //cerr << "ITK iterators:" << endl;
    //itk_iterators(nx,ny,niter,verbose);

    //cerr << "ITK convolution:" << endl;
    //itk_convolution(nx,ny,niter,verbose);

    return 0;
}
