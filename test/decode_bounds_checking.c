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

int main(int argc, char *argv[])
{
	size_t i, bufsize;
	char s[2] = {'0', 0};

	for(i = 1; i < 6; i++) {
		bufsize = Z85_decode_with_padding_bound(s, i);
		printf("%s, %lu: %lu\n", s, i, bufsize);
	}
	printf("\n");

	s[0] = '1';
	for(i = 1; i < 6; i++) {
		bufsize = Z85_decode_with_padding_bound(s, i);
		printf("%s, %lu: %lu\n", s, i, bufsize);
	}
	printf("\n");

	s[0] = '2';
	for(i = 1; i < 6; i++) {
		bufsize = Z85_decode_with_padding_bound(s, i);
		printf("%s, %lu: %lu\n", s, i, bufsize);
	}
	printf("\n");

	s[0] = '3';
	for(i = 1; i < 6; i++) {
		bufsize = Z85_decode_with_padding_bound(s, i);
		printf("%s, %lu: %lu\n", s, i, bufsize);
	}
	printf("\n");

	s[0] = '4';
	for(i = 1; i < 6; i++) {
		bufsize = Z85_decode_with_padding_bound(s, i);
		printf("%s, %lu: %lu\n", s, i, bufsize);
	}
	printf("\n");

	return 0;
}
