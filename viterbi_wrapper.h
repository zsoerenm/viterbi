#ifndef __MYWRAPPER_H
#define __MYWRAPPER_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ViterbiCodec ViterbiCodec;

void decode(int constraint, int polynomials[], char* bits, char* decoded_bits_char);

void encode(int constraint, int polynomials[], char* bits, char* encoded_bits_char);

#ifdef __cplusplus
}
#endif
#endif