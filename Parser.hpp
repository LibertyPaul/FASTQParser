#ifndef PARSER_HPP
#define PARSER_HPP

#include "Block.hpp"

#include <istream>
#include <string>
#include <regex>


namespace FASTQ{

class Parser{
	std::istream &src;

	static constexpr char blockDelimiter = '@';

	bool currentBlockValid = false;
	Block currentBlock;
	mutable size_t maxStringSize = 0;

	std::string readUntil(const char delimiter);
	void readNextBlock();
public:
	Parser(std::istream &src);
	~Parser();

	bool hasNext();
	Block next();

	double progress() const;
};


}

#endif // PARSER_HPP
