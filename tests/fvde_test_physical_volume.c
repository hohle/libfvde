/*
 * Library physical_volume type test program
 *
 * Copyright (C) 2011-2022, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <common.h>
#include <file_stream.h>
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include "fvde_test_libcerror.h"
#include "fvde_test_libfvde.h"
#include "fvde_test_macros.h"
#include "fvde_test_memory.h"
#include "fvde_test_unused.h"

#include "../libfvde/libfvde_physical_volume.h"
#include "../libfvde/libfvde_physical_volume_descriptor.h"
#include "../libfvde/libfvde_volume_header.h"

#if defined( __GNUC__ ) && !defined( LIBFVDE_DLL_IMPORT )

/* Tests the libfvde_physical_volume_initialize function
 * Returns 1 if successful or 0 if not
 */
int fvde_test_physical_volume_initialize(
     void )
{
	libcerror_error_t *error                                         = NULL;
	libfvde_physical_volume_t *physical_volume                       = NULL;
	libfvde_physical_volume_descriptor_t *physical_volume_descriptor = NULL;
	libfvde_volume_header_t *volume_header                           = NULL;
	int result                                                       = 0;

#if defined( HAVE_FVDE_TEST_MEMORY )
	int number_of_malloc_fail_tests                                  = 1;
	int number_of_memset_fail_tests                                  = 1;
	int test_number                                                  = 0;
#endif

	/* Initialize test
	 */
	result = libfvde_volume_header_initialize(
	          &volume_header,
	          &error );

	FVDE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVDE_TEST_ASSERT_IS_NOT_NULL(
	 "volume_header",
	 volume_header );

	FVDE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfvde_physical_volume_descriptor_initialize(
	          &physical_volume_descriptor,
	          &error );

	FVDE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVDE_TEST_ASSERT_IS_NOT_NULL(
	 "physical_volume_descriptor",
	 physical_volume_descriptor );

	FVDE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfvde_physical_volume_initialize(
	          &physical_volume,
	          volume_header,
	          physical_volume_descriptor,
	          &error );

	FVDE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVDE_TEST_ASSERT_IS_NOT_NULL(
	 "physical_volume",
	 physical_volume );

	FVDE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfvde_physical_volume_free(
	          &physical_volume,
	          &error );

	FVDE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVDE_TEST_ASSERT_IS_NULL(
	 "physical_volume",
	 physical_volume );

	FVDE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfvde_physical_volume_initialize(
	          NULL,
	          volume_header,
	          physical_volume_descriptor,
	          &error );

	FVDE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVDE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	physical_volume = (libfvde_physical_volume_t *) 0x12345678UL;

	result = libfvde_physical_volume_initialize(
	          &physical_volume,
	          volume_header,
	          physical_volume_descriptor,
	          &error );

	physical_volume = NULL;

	FVDE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVDE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvde_physical_volume_initialize(
	          &physical_volume,
	          NULL,
	          physical_volume_descriptor,
	          &error );

	FVDE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVDE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvde_physical_volume_initialize(
	          &physical_volume,
	          volume_header,
	          NULL,
	          &error );

	FVDE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVDE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

#if defined( HAVE_FVDE_TEST_MEMORY )

	for( test_number = 0;
	     test_number < number_of_malloc_fail_tests;
	     test_number++ )
	{
		/* Test libfvde_physical_volume_initialize with malloc failing
		 */
		fvde_test_malloc_attempts_before_fail = test_number;

		result = libfvde_physical_volume_initialize(
		          &physical_volume,
		          volume_header,
		          physical_volume_descriptor,
		          &error );

		if( fvde_test_malloc_attempts_before_fail != -1 )
		{
			fvde_test_malloc_attempts_before_fail = -1;

			if( physical_volume != NULL )
			{
				libfvde_physical_volume_free(
				 &physical_volume,
				 NULL );
			}
		}
		else
		{
			FVDE_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 -1 );

			FVDE_TEST_ASSERT_IS_NULL(
			 "physical_volume",
			 physical_volume );

			FVDE_TEST_ASSERT_IS_NOT_NULL(
			 "error",
			 error );

			libcerror_error_free(
			 &error );
		}
	}
	for( test_number = 0;
	     test_number < number_of_memset_fail_tests;
	     test_number++ )
	{
		/* Test libfvde_physical_volume_initialize with memset failing
		 */
		fvde_test_memset_attempts_before_fail = test_number;

		result = libfvde_physical_volume_initialize(
		          &physical_volume,
		          volume_header,
		          physical_volume_descriptor,
		          &error );

		if( fvde_test_memset_attempts_before_fail != -1 )
		{
			fvde_test_memset_attempts_before_fail = -1;

			if( physical_volume != NULL )
			{
				libfvde_physical_volume_free(
				 &physical_volume,
				 NULL );
			}
		}
		else
		{
			FVDE_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 -1 );

			FVDE_TEST_ASSERT_IS_NULL(
			 "physical_volume",
			 physical_volume );

			FVDE_TEST_ASSERT_IS_NOT_NULL(
			 "error",
			 error );

			libcerror_error_free(
			 &error );
		}
	}
#endif /* defined( HAVE_FVDE_TEST_MEMORY ) */

	/* Clean up
	 */
	result = libfvde_physical_volume_descriptor_free(
	          &physical_volume_descriptor,
	          &error );

	FVDE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVDE_TEST_ASSERT_IS_NULL(
	 "physical_volume_descriptor",
	 physical_volume_descriptor );

	FVDE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfvde_volume_header_free(
	          &volume_header,
	          &error );

	FVDE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVDE_TEST_ASSERT_IS_NULL(
	 "volume_header",
	 volume_header );

	FVDE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( physical_volume_descriptor != NULL )
	{
		libfvde_physical_volume_descriptor_free(
		 &physical_volume_descriptor,
		 NULL );
	}
	if( volume_header != NULL )
	{
		libfvde_volume_header_free(
		 &volume_header,
		 NULL );
	}
	if( physical_volume != NULL )
	{
		libfvde_physical_volume_free(
		 &physical_volume,
		 NULL );
	}
	return( 0 );
}

#endif /* defined( __GNUC__ ) && !defined( LIBFVDE_DLL_IMPORT ) */

/* Tests the libfvde_physical_volume_free function
 * Returns 1 if successful or 0 if not
 */
int fvde_test_physical_volume_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libfvde_physical_volume_free(
	          NULL,
	          &error );

	FVDE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVDE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* The main program
 */
#if defined( HAVE_WIDE_SYSTEM_CHARACTER )
int wmain(
     int argc FVDE_TEST_ATTRIBUTE_UNUSED,
     wchar_t * const argv[] FVDE_TEST_ATTRIBUTE_UNUSED )
#else
int main(
     int argc FVDE_TEST_ATTRIBUTE_UNUSED,
     char * const argv[] FVDE_TEST_ATTRIBUTE_UNUSED )
#endif
{
	FVDE_TEST_UNREFERENCED_PARAMETER( argc )
	FVDE_TEST_UNREFERENCED_PARAMETER( argv )

#if defined( __GNUC__ ) && !defined( LIBFVDE_DLL_IMPORT )

	FVDE_TEST_RUN(
	 "libfvde_physical_volume_initialize",
	 fvde_test_physical_volume_initialize );

#endif /* defined( __GNUC__ ) && !defined( LIBFVDE_DLL_IMPORT ) */

	FVDE_TEST_RUN(
	 "libfvde_physical_volume_free",
	 fvde_test_physical_volume_free );

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}
