/*
 * BriefLZ  -  small fast Lempel-Ziv
 *
 * C/C++ dll header file
 *
 * Copyright (c) 2002-2015 by Joergen Ibsen / Jibz
 * All Rights Reserved
 *
 * http://www.ibsensoftware.com/
 */

#ifndef BRIEFLZ_H_INCLUDED
#define BRIEFLZ_H_INCLUDED

/* calling convention */
#ifndef BLZCC
# define BLZCC __stdcall
#endif

#ifndef DllSpec
# ifdef BLZ_DLL_BUILD
#  define DllSpec __declspec( dllexport )
# else
#  define DllSpec __declspec( dllimport )
# endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifndef BLZ_ERROR
# define BLZ_ERROR (-1)
#endif

/**
 * Compress data.
 * @param source - pointer to data.
 * @param destination - where to store the compressed data.
 * @param length - the length in bytes of the data.
 * @param workmem - pointer to memory for temporary use.
 * @return the length of the compressed data.
 */
DllSpec
unsigned int BLZCC blz_pack(const void *source,
                            void *destination,
                            unsigned int length,
                            void *workmem);


/**
 * Decompress data.
 * @param source - pointer to the compressed data.
 * @param destination - where to store the decompressed data.
 * @param depacked_length - the length of the decompressed data.
 * @return the length of the decompressed data.
 */
DllSpec
unsigned int BLZCC blz_depack(const void *source,
                              void *destination,
                              unsigned int depacked_length);


/**
 * Decompress data safely.
 * @param source - pointer to the compressed data.
 * @param srclen - the size of the source buffer in bytes.
 * @param destination - where to store the decompressed data.
 * @param depacked_length - the length of the decompressed data.
 * @return the length of the decompressed data, or BLZ_ERROR on error.
 * @note This functions reads at most srclen bytes from source[], and
 * writes at most depacked_length bytes to destination[].
 */
DllSpec
unsigned int BLZCC blz_depack_safe(const void *source,
                                   unsigned int srclen,
                                   void *destination,
                                   unsigned int depacked_length);


/**
 * Get the required size of the workmem buffer.
 * @param length - the length in bytes of the data.
 * @return required size in bytes of the workmem buffer.
 */
DllSpec
unsigned int BLZCC blz_workmem_size(unsigned int length);


/**
 * Get the maximum output size produced on uncompressible data.
 * @param length - the length in bytes of the data.
 * @return maximum required size in bytes of the output buffer.
 */
DllSpec
unsigned int BLZCC blz_max_packed_size(unsigned int length);


/**
 * Compute the CRC32 of a buffer.
 * @param source - pointer to the data.
 * @param length - the number of bytes to process.
 * @param initial_crc32 - the current CRC32 value (pass 0 for first block).
 * @return the CRC32 of the data.
 */
DllSpec
unsigned int BLZCC blz_crc32(const void *source,
                             unsigned int length,
                             unsigned int initial_crc32);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* BRIEFLZ_H_INCLUDED */
