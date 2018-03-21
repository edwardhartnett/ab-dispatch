/**
 * @file
 * This header file contains the prototypes for the AB versions
 * of the netCDF functions.
 *
 * Ed Hartnett
 */
#ifndef _ABDISPATCH_H
#define _ABDISPATCH_H

#include "config.h"
#include <stddef.h> /* size_t, ptrdiff_t */
#include <netcdf.h>
#include <ncdispatch.h>

/* This is the metadata we need to keep track of for each
   netcdf-4/HDF5 file. */
typedef struct  AB_FILE_INFO
{
   FILE *a_file;
   FILE *b_file;
} AB_FILE_INFO_T;


#if defined(__cplusplus)
extern "C" {
#endif

   extern int AB_open(const char *path, int mode, int basepe, size_t *chunksizehintp,
                      int use_parallel, void* parameters, NC_Dispatch*, NC*);

   extern int AB_close(int ncid);

   extern int AB_inq_format(int ncid, int *formatp);

   extern int AB_inq_format_extended(int ncid, int *formatp, int *modep);

   extern int AB_get_vara(int ncid, int varid, const size_t *start, const size_t *count,
                          void *value, nc_type);

   extern int ab_set_log_level(int new_level);
   
#if defined(__cplusplus)
}
#endif

#endif /*_ABDISPATCH_H */
