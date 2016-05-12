#ifndef BLOCK_HPP
#define BLOCK_HPP

#include "Common.hpp"
#include "Quality.hpp"

#include <string>
#include <vector>
#include <utility>
#include <stdexcept>

namespace FASTQ{


class Block{
	std::string sequenceName1;
	std::string sequenceName2;
	std::vector<std::pair<Common::NucleotideBasis, Common::Quality>> sequence;

public:
	Block(){}
	Block(std::string &&sequenceName1, std::string &&sequenceName2, std::vector<std::pair<Common::NucleotideBasis, Common::Quality>> &&sequence):
		sequenceName1(sequenceName1),
		sequenceName2(sequenceName2),
		sequence(sequence){}

	Block(const std::string &sequenceName1, const std::string &sequenceName2, const std::vector<std::pair<Common::NucleotideBasis, Common::Quality>> &sequence):
		Block(
			std::move(std::string(sequenceName1)),
			std::move(std::string(sequenceName2)),
			std::move(std::vector<std::pair<Common::NucleotideBasis, Common::Quality>>(sequence))
		){}

	Block(Block &&block):
		Block(
			std::move(block.sequenceName1),
			std::move(block.getSequenceName2()),
			std::move(block.sequence)
		){}

	Block(const Block &block):
		Block(
			std::move(
				Block(
					block.sequenceName1,
					block.sequenceName2,
					block.sequence
				)
			)
		){}

	Block operator=(Block &&block){
		std::swap(this->sequenceName1, block.sequenceName1);
		std::swap(this->sequenceName2, block.sequenceName2);
		std::swap(this->sequence, block.sequence);

		return *this;
	}

	Block operator=(const Block &block){
		return this->operator=(std::move(Block(block)));
	}

	const std::string &getSequenceName1() const{
		return this->sequenceName1;
	}

	const std::string &getSequenceName2() const{
		return this->sequenceName2;
	}

	const std::vector<std::pair<Common::NucleotideBasis, Common::Quality>> &getSequence() const{
		return this->sequence;
	}

	friend void swap(Block &lhs, Block &rhs){
		std::swap(lhs.sequenceName1, rhs.sequenceName1);
		std::swap(lhs.sequenceName2, rhs.sequenceName2);
		std::swap(lhs.sequence, rhs.sequence);
	}
};

}

#endif // BLOCK_HPP
