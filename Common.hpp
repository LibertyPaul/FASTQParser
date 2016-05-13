#ifndef COMMON_HPP
#define COMMON_HPP

#include <stdexcept>

namespace FASTQ{

namespace Common{

enum class NucleotideBasis{
	A, T, G, C, N
};

class Nucleotide{
	NucleotideBasis basis;

public:
	Nucleotide(const NucleotideBasis &basis): basis(basis){}
	Nucleotide(const char ch){
		switch(ch){
		case 'A':
			basis = NucleotideBasis::A;
			break;
		case 'T':
			basis = NucleotideBasis::T;
			break;
		case 'G':
			basis = NucleotideBasis::G;
			break;
		case 'C':
			basis = NucleotideBasis::C;
			break;
		case 'N':
			basis = NucleotideBasis::N;

		default:
			throw std::invalid_argument("Invalid nucleotide basis char");
		}
	}

	size_t toIndex() const{
		size_t res = 0;

		switch(this->basis){
		case NucleotideBasis::C:
			++res;
		case NucleotideBasis::G:
			++res;
		case NucleotideBasis::T:
			++res;
		case NucleotideBasis::A:
			++res;
		case NucleotideBasis::N:
			break;
		}

		return res;
	}

	bool operator==(const Nucleotide &o) const{
		return this->basis == o.basis;
	}
};

}

}

#endif // COMMON_HPP

