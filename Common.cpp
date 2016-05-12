#include "Common.hpp"

FASTQ::Common::NucleotideBasis FASTQ::Common::fromChar(const char ch){
	switch(ch){
	case 'A':
		return NucleotideBasis::A;
	case 'T':
		return NucleotideBasis::T;
	case 'G':
		return NucleotideBasis::G;
	case 'C':
		return NucleotideBasis::C;

	default:
		throw std::invalid_argument("Invalid nucleotide basis char");
	}
}
