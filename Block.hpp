#ifndef BLOCK_HPP
#define BLOCK_HPP

#include "Common.hpp"

#include <string>
#include <vector>
#include <utility>

namespace FASTQ{

typedef uint8_t Quality;

class Block{
	const std::string sequenceName;
	const std::vector<std::pair<Common::NucleotideBasis, Quality>> sequence;

public:
	Block(std::string &&sequenceName, std::vector<std::pair<Common::NucleotideBasis, Quality>> &&sequence): sequenceName(sequenceName), sequence(sequence){}
	Block(const std::string &sequenceName, const std::vector<std::pair<Common::NucleotideBasis, Quality>> &sequence):
		Block(
			std::move(std::string(sequenceName)),
			std::move(std::vector<std::pair<Common::NucleotideBasis, Quality>>(sequence))
		)
	{

	}

	const std::string &getSequenceName() const{
		return this->sequenceName;
	}

	const std::vector<std::pair<Common::NucleotideBasis, Quality>> &getSequence() const{
		return this->sequence;
	}
};


}
#endif // BLOCK_HPP
