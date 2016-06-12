#ifndef COMMON_HPP
#define COMMON_HPP

#include <stdexcept>
#include <bitset>

namespace FASTQ{

namespace Common{

enum class NucleotideBasis{
	A = 0, T, G, C, N
};


class Nucleotide{
	NucleotideBasis index;
public:
	typedef NucleotideBasis value_type;
	typedef size_t index_t;
	static constexpr size_t alphabetSize = 5;
	static constexpr size_t binarySize = 3; // 3 bit per item.
	static constexpr value_type min_value = value_type::A;
	static constexpr value_type max_value = value_type::N;

	explicit Nucleotide(const value_type index): index(index){}

	size_t toIndex() const{
		return static_cast<size_t>(index);
	}

	static Nucleotide fromIndex(const size_t index){
		if(index > static_cast<size_t>(max_value)){
			throw std::overflow_error("");
		}

		return Nucleotide(static_cast<value_type>(index));
	}

	char toSymbol() const{
		switch(this->index){
		case NucleotideBasis::A:
			return 'A';
		case NucleotideBasis::T:
			return 'T';
		case NucleotideBasis::G:
			return 'G';
		case NucleotideBasis::C:
			return 'C';
		case NucleotideBasis::N:
			return 'N';


		default:
			throw std::invalid_argument("Invalid nucleotide basis char");
		}
	}

	static Nucleotide fromSymbol(const char symbol){
		value_type basis;
		switch(symbol){
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
			break;

		default:
			throw std::invalid_argument("Invalid nucleotide basis char");
		}

		return Nucleotide(basis);
	}

	std::bitset<binarySize> toBitset() const{
		return std::bitset<binarySize>(this->toIndex());
	}

	static Nucleotide fromBitset(const std::bitset<binarySize> &bitset){
		return Nucleotide::fromIndex(bitset.to_ullong());
	}

	Nucleotide &operator=(const Nucleotide &o){
		this->index = o.index;
		return *this;
	}

	bool operator==(const NucleotideBasis &alphabet) const{
		return this->index == alphabet;
	}

	bool operator==(const Nucleotide &o) const{
		return *this == o.index;
	}

	bool operator!=(const Nucleotide &o) const{
		return !(*this == o);
	}

	bool operator<(const Nucleotide &o) const{
		return this->index < o.index;
	}

	Nucleotide &operator++(){
		*this = Nucleotide::fromIndex(this->toIndex() + 1);
		return *this;
	}
};

}

}

#endif // COMMON_HPP

