/*
Test cases for z85 C code written by Brett Kuskie <fullaxx@gmail.com>
Any code written here may be used under the same LICENSE as the original author's repository
Stanislav Artemkin
https://github.com/artemkin/z85/blob/master/LICENSE
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "z85.h"

int run_test(char *testdata, size_t size)
{
	char *enc;
	char *dec;
	int error;
	size_t bufsize, encbytes, decbytes;

	error = 0;
	bufsize = (size+3)*2;	//For small values, we over-buffer
	enc = malloc(bufsize);
	dec = malloc(bufsize);

	encbytes = Z85_encode_with_padding(testdata, enc, size);
	if(!encbytes) error = 1;
	enc[encbytes] = 0;	//This is a STRING, we should verify NULL
	printf("(%3lu) %s", encbytes, enc);

	if(error) {
		printf(" FAIL!");
	}
	printf("\n");

	decbytes = Z85_decode_with_padding(enc, dec, encbytes);
	if(!decbytes) error = 1;
	dec[decbytes] = 0;	//if STRING and we have enough space to add the NULL
	printf("(%3lu) %s", decbytes, dec);

	if(error) {
		printf(" FAIL!");
	}
	printf("\n");

	if(size != decbytes) {
		printf("DECODE MISMATCH!\n");
	}

	error = memcmp(testdata, dec, size);
	if(error) {
		printf("DECODE MISMATCH!\n");
	}

	free(enc);
	free(dec);

	return error;
}

int main(int argc, char *argv[])
{
	run_test("A", 1);
	run_test("Z", 1);
	run_test("AB", 2);
	run_test("YZ", 2);
	run_test("ABC", 3);
	run_test("XYZ", 3);
	run_test("ABCD", 4);
	run_test("WXYZ", 4);
	run_test("ABCDE", 5);
	run_test("VWXYZ", 5);
	run_test("ABCDEF", 6);
	run_test("UVWXYZ", 6);
	run_test("ABCDEFG", 7);
	run_test("TUVWXYZ", 7);
	run_test("ABCDEFGH", 8);
	run_test("STUVWXYZ", 8);
	run_test("ABCDEFGHI", 9);
	run_test("RSTUVWXYZ", 9);
	run_test("ABCDEFGHIJ", 10);
	run_test("QRSTUVWXYZ", 10);
	run_test("ABCDEFGHIJK", 11);
	run_test("PQRSTUVWXYZ", 11);
	run_test("ABCDEFGHIJKL", 12);
	run_test("OPQRSTUVWXYZ", 12);
	run_test("ABCDEFGHIJKLM", 13);
	run_test("NOPQRSTUVWXYZ", 13);
	run_test("ABCDEFGHIJKLMN", 14);
	run_test("MNOPQRSTUVWXYZ", 14);
	run_test("ABCDEFGHIJKLMNO", 15);
	run_test("LMNOPQRSTUVWXYZ", 15);
	run_test("ABCDEFGHIJKLMNOP", 16);
	run_test("KLMNOPQRSTUVWXYZ", 16);
	run_test("ABCDEFGHIJKLMNOPQ", 17);
	run_test("JKLMNOPQRSTUVWXYZ", 17);

	return 0;
}
