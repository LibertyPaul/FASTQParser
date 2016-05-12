#include "Parser.hpp"
#include "Common.hpp"

#include <sstream>
#include <stdexcept>
#include <cassert>
#include <utility>
#include <iostream>
using namespace FASTQ;

Parser::Parser(std::istream &src):
	src(src),
	currentBlockValid(false)
{
	this->src.exceptions(std::istream::badbit | std::istream::failbit | std::istream::eofbit);

	try{
		this->readNextBlock();
	}
	catch(const std::ios_base::failure &){
		this->currentBlockValid = false;
	}
}

Parser::~Parser(){

}

std::string Parser::readUntil(const char delimiter){
	std::string result;
	std::getline(this->src, result, delimiter);
	return result;
}

void Parser::readNextBlock(){
	const int blockStart = this->src.get();
	if(blockStart != this->blockDelimiter){
		throw std::runtime_error("Incorrect block delimiter");
	}

	const std::string seqname = this->readUntil('\n');
	const std::string sequence = this->readUntil('+');
	const std::string seqname2 = this->readUntil('\n');

	std::string quality;
	quality.reserve(sequence.size());
	for(size_t i = 0; i < sequence.size(); ++i){
		const int t = this->src.get();
		quality.push_back(static_cast<char>(t));
	}

	assert(sequence.size() == quality.size());

	std::vector<std::pair<Common::NucleotideBasis, Common::Quality>> sequenceQualityPairs;
	sequenceQualityPairs.reserve(sequence.size());

	for(size_t i = 0; i < sequence.size(); ++i){
		try{
			const Common::NucleotideBasis nb = Common::fromChar(sequence[i]);
			const Common::Quality qualityValue(quality[i]);
			sequenceQualityPairs.push_back(std::make_pair(nb, qualityValue));
		}
		catch(std::invalid_argument &ex){
			assert(sequence[i] == quality[i]); // if there is a \n symbol in `seq` it should be at same position in `qual`
			continue;
		}

	}

	this->currentBlock = Block(std::move(seqname), std::move(seqname2), std::move(sequenceQualityPairs));
	this->currentBlockValid = true;
}


Block Parser::next(){
	Block result;
	std::swap(result, this->currentBlock);

	try{
		this->readNextBlock();
	}
	catch(const std::ios_base::failure &e){
		this->currentBlockValid = false;
	}

	return result;
}

bool Parser::hasNext(){
	return this->currentBlockValid;
}























