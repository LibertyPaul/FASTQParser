#include "Block.hpp"

#include <iostream>

using namespace FASTQ;

int main(){

	std::string name = "name";
	std::vector<std::pair<Common::NucleotideBasis, Quality>> seq{
		{Common::NucleotideBasis::A, 1},
		{Common::NucleotideBasis::T, 10},
		{Common::NucleotideBasis::T, 100},
		{Common::NucleotideBasis::G, 10},
		{Common::NucleotideBasis::C, 1}
	};

	const std::string &nameRef = name;
	const std::vector<std::pair<Common::NucleotideBasis, Quality>> &seqRef = seq;


	Block b(nameRef, seqRef);


}

