#include "viterbi.h"
#include "viterbi_wrapper.h"
#include <cstring>

extern "C" {
    void decode(int constraint, int polynomials[], char* bits, char* decoded_bits_char) {
        int num_polynomials = sizeof(polynomials) / sizeof(polynomials[0]);
        std::vector<int> polynomials_vector(polynomials, polynomials + num_polynomials);
        ViterbiCodec codec(constraint, polynomials_vector);
        std::string bitString(bits);
        const std::string decoded_bits = codec.Decode(bitString);
        strcpy(decoded_bits_char, decoded_bits.c_str());
    }

    void encode(int constraint, int polynomials[], char* bits, char* encoded_bits_char) {
        int num_polynomials = sizeof(polynomials) / sizeof(polynomials[0]);
        std::vector<int> polynomials_vector(polynomials, polynomials + num_polynomials);
        ViterbiCodec codec(constraint, polynomials_vector);
        std::string bitString(bits);
        const std::string encoded_bits = codec.Encode(bitString);
        strcpy(encoded_bits_char, encoded_bits.c_str());
    }
}