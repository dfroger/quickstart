#include <stdio.h>

#include "metis.h"

int main() {

    // =====================================
    // Inputs
    // =====================================

    // Number of element in the mesh (15 triangles)
    idx_t ne = 15;

    // Number of node in the mesh (15 points).
    idx_t nn = 15;

    // Triangles point indices.
    idx_t eptr[16] = {0,2,5,8,11,13,16,20,24,28,31,33,36,39,42,44};
    idx_t eind[44] = {1,5,0,2,6,1,3,7,2,4,8,3,9,0,6,10,1,5,7,11,2,
        6,8,12,3,7,9,13,4,8,14,5,11,6,10,12,7,11,13,8,12,14,9,13};

    // All node have equal weight.
    idx_t *vwgt = NULL;

    // All node have equal size.
    idx_t *vsize = NULL;

    // Number of partition.
    idx_t nparts = 4;

    // All partition have equal weight.
    real_t *tpwgts = NULL; 

    // No options.
    idx_t *options = NULL;

    // =====================================
    // Outputs
    // =====================================

    // Total communication volume.
    idx_t objval;

    // Element and node partition vectors.
    idx_t epart[15];
    idx_t npart[15];

    int err = METIS_PartMeshNodal(&ne, &nn, eptr, eind, vwgt, vsize,
            &nparts, tpwgts, options, &objval, epart, npart);

    switch (err)
    {
    case METIS_OK:
        printf("ok\n");
        break;
    case METIS_ERROR_INPUT:
        printf("error input\n");
        break;
    case METIS_ERROR_MEMORY:
        printf("error memory\n");
        break;
    case METIS_ERROR:
        printf("error\n");
        break;
    default:
        printf("Unexpected return value: %d\n", err);
        break;
    }

    printf("objval: %lu\n", objval);

    printf("epart: ");
    idx_t i;
    for (i= 0 ; i < ne ; i++)
        printf("%lu ", epart[i]);
    printf("\n");

    printf("npart: ");
    for (i= 0 ; i < ne ; i++)
        printf("%lu ", npart[i]);
    printf("\n");

    return 0;
}
