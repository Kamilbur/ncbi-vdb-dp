/*===========================================================================
*
*                            PUBLIC DOMAIN NOTICE
*               National Center for Biotechnology Information
*
*  This software/database is a "United States Government Work" under the
*  terms of the United States Copyright Act.  It was written as part of
*  the author's official duties as a United States Government employee and
*  thus cannot be copyrighted.  This software/database is freely available
*  to the public for use. The National Library of Medicine and the U.S.
*  Government have not placed any restriction on its use or reproduction.
*
*  Although all reasonable efforts have been taken to ensure the accuracy
*  and reliability of the software and data, the NLM and the U.S.
*  Government do not and cannot warrant the performance or results that
*  may be obtained by using this software or data. The NLM and the U.S.
*  Government disclaim all warranties, express or implied, including
*  warranties of performance, merchantability or fitness for any particular
*  purpose.
*
*  Please cite the author in any work or product based on this material.
*
* ===========================================================================
*
*/

#ifndef _h_kfs_extern_
#define _h_kfs_extern_

#if ! defined EXPORT_LATCH && defined _LIBRARY
#define KFS_EXTERN LIB_EXPORT
#define EXPORT_LATCH 1
#else
#define KFS_EXTERN LIB_IMPORT
#endif

#ifndef _h_klib_extern_
#include <klib/extern.h>
#endif

//#include <stdio.h>
#include <sys/types.h>
#include <stdint.h>
#define DATAPLUG
#define DPLUGDBG

#ifdef DATAPLUG

extern ssize_t (*s3_pread)(int, void *, size_t, size_t);
extern void * (*s3_mmap)(void *, size_t, int, int, int, off_t);
extern uint64_t (*s3_size)(void);
extern int s3_remote_size;
void register_s3_pread(ssize_t (*)(int, void *, size_t, size_t), 
                        uint64_t (*)(void));
void register_s3_mmap(void * (*)(void *, size_t, int, int, int, off_t));

struct shm_info {
    int fd;
    void *ptr;
    size_t length;
};
extern struct shm_info shm_buf;
extern struct shm_info mmap_buf;
extern struct shm_info pread_buf;
extern size_t dp_sra_size;
extern int dp_mode;
void register_shmem(struct shm_info *, const char *);
void close_shmem(struct shm_info *);

#endif

#endif /* _h_kfs_extern_ */
