/**
 * @file bblas_sflops.c
 *
 * @brief BBLAS flop computation for float_Complex routines.
 *
 * BBLAS is a software package provided by Univ. of Manchester,
 * Univ. of Tennessee.
 *
 * @version 1.0.0
 * @author  Samuel  D. Relton
 * @author  Pedro   V. Lara
 * @author  Mawussi Zounon
 * @date    2016-02-20
 *
 **/

#ifndef DOXYGEN_SHOULD_SKIP_THIS
/**
 * Code generation
 * @generated from bblas_zflops.c normal z -> s, Mon Jun  6 09:44:13 2016
 **/
#endif

#include "bblas_common.h"
#include "flops.h"

#define REAL

/**
 * Computes theoretical number of flops required for the batch operation.
 **/

void bblas_sflops(bblas_stest_t *test)
{

    int batch_iter, first_index=0;

    /*Initialize test->flops */
    test->flops =0.;

    if( test->batch_opts == BBLAS_FIXED )
    {
	switch(test->routine)
	{

	    case BBLAS_GEMM:
		test->flops = test->batch_count*FLOPS_SGEMM(test->M[first_index],test->N[first_index],test->K[first_index]);
		break;

	    case BBLAS_HEMM:
		test->flops = test->batch_count*FLOPS_SSYMM(test->side[first_index], test->M[first_index],test->N[first_index]);
		break;

	    case BBLAS_SYMM:
		test->flops = test->batch_count*FLOPS_SSYMM(test->side[first_index], test->M[first_index],test->N[first_index]);
		break;

	    case BBLAS_HERK:
		test->flops = test->batch_count*FLOPS_SSYRK(test->K[first_index],test->N[first_index]);
		break;

	    case BBLAS_SYRK:
		test->flops = test->batch_count*FLOPS_SSYRK(test->K[first_index],test->N[first_index]);
		break;

	    case BBLAS_HER2K:
		test->flops = test->batch_count*FLOPS_SSYR2K(test->K[first_index],test->N[first_index]);
		break;

	    case BBLAS_SYR2K:
		test->flops = test->batch_count*FLOPS_SSYR2K(test->K[first_index],test->N[first_index]);
		break;

	    case BBLAS_TRMM:
		test->flops = test->batch_count*FLOPS_STRMM(test->side[first_index], test->M[first_index],test->N[first_index]);
		break;

	    case BBLAS_TRSM:
		test->flops = test->batch_count*FLOPS_STRSM(test->side[first_index], test->M[first_index],test->N[first_index]);
		break;

	    default:
		printf("In  bblas_sflops(): routine not defined.\n");
		exit(EXIT_FAILURE);
	}
    }else
    {
	switch(test->routine)
	{

	    case BBLAS_GEMM:
		for( batch_iter =0; batch_iter < test->batch_count; batch_iter++)
		{
		    test->flops += FLOPS_SGEMM(test->M[batch_iter],test->N[batch_iter],test->K[batch_iter]);
		}
		break;

	    case BBLAS_HEMM:
		for( batch_iter = 0; batch_iter < test->batch_count; batch_iter++)
		{
		    test->flops += FLOPS_SSYMM(test->side[batch_iter], test->M[batch_iter],test->N[batch_iter]);
		}
		break;

	    case BBLAS_SYMM:
		for( batch_iter =0; batch_iter < test->batch_count; batch_iter++)
		{
		    test->flops += FLOPS_SSYMM(test->side[batch_iter], test->M[batch_iter],test->N[batch_iter]);
		}
		break;

	    case BBLAS_HERK:
		for( batch_iter =0; batch_iter < test->batch_count; batch_iter++)
		{
		    test->flops  += FLOPS_SSYRK(test->K[batch_iter],test->N[batch_iter]);
		}
		break;

	    case BBLAS_SYRK:
		for( batch_iter =0; batch_iter < test->batch_count; batch_iter++)
		{
		    test->flops += FLOPS_SSYRK(test->K[batch_iter],test->N[batch_iter]);
		}
		break;

	    case BBLAS_HER2K:
		for( batch_iter =0; batch_iter < test->batch_count; batch_iter++)
		{
		    test->flops += FLOPS_SSYR2K(test->K[batch_iter],test->N[batch_iter]);
		}
		break;

	    case BBLAS_SYR2K:
		for( batch_iter =0; batch_iter < test->batch_count; batch_iter++)
		{
		    test->flops += FLOPS_SSYR2K(test->K[batch_iter],test->N[batch_iter]);
		}
		break;

	    case BBLAS_TRMM:
		for( batch_iter =0; batch_iter < test->batch_count; batch_iter++)
		{
		    test->flops += FLOPS_STRMM(test->side[batch_iter], test->M[batch_iter],test->N[batch_iter]);
		}
		break;

	    case BBLAS_TRSM:
		for( batch_iter =0; batch_iter < test->batch_count; batch_iter++)
		{
		    test->flops += FLOPS_STRSM(test->side[batch_iter], test->M[batch_iter],test->N[batch_iter]);
		}
		break;

	    default:
		printf("In  bblas_sflops(): routine not defined.\n");
		exit(EXIT_FAILURE);
	}
    }
}
#undef REAL
