#include "Common.hpp"
#include "Block.hpp"
#include "Parser.hpp"
#include "TinyTestFramework/TinyTestFramework.hpp"

#include <iostream>
#include <sstream>
#include <cassert>

using namespace FASTQ;

void case1(){
	std::stringstream src;
	src <<
		"@EAS54_6_R1_2_1_413_324\n"
		"CCCTTCTTGTCTTCAGCGTTTCTCC\n"
		"+\n"
		";;3;;;;;;;;;;;;7;;;;;;;88\n"
		"@EAS54_6_R1_2_1_540_792\n"
		"TTGGCAGGCCAAGGCCGATGGATCA\n"
		"+\n"
		";;;;;;;;;;;7;;;;;-;;;3;83\n"
		"@EAS54_6_R1_2_1_443_348\n"
		"GTTGCTTCTGGCGTGGGTGGGGGGG\n"
		"+EAS54_6_R1_2_1_443_348\n"
		";;;;;;;;;;;9;7;;.7;393333\n";


	Parser p1(src);
	assert(p1.hasNext());

	const Block b1 = p1.next();
	assert(b1.getSequenceName1() == "EAS54_6_R1_2_1_413_324");
	assert(b1.getSequenceName2() == "");

	const auto &values1 = b1.getSequence();
	assert(values1.size()		== 25);
	assert(values1[0].first		== Common::NucleotideBasis::C);
	assert(values1[0].second	== Common::Quality(';'));
	assert(values1[24].first	== Common::NucleotideBasis::C);
	assert(values1[24].second	== Common::Quality('8'));


	assert(p1.hasNext());

	const Block b2 = p1.next();
	assert(b2.getSequenceName1() == "EAS54_6_R1_2_1_540_792");
	assert(b2.getSequenceName2() == "");

	const auto &values2 = b2.getSequence();
	assert(values2.size()		== 25);
	assert(values2[0].first		== Common::NucleotideBasis::T);
	assert(values2[0].second	== Common::Quality(';'));
	assert(values2[24].first	== Common::NucleotideBasis::A);
	assert(values2[24].second	== Common::Quality('3'));


	assert(p1.hasNext());

	const Block b3 = p1.next();
	assert(b3.getSequenceName1() == "EAS54_6_R1_2_1_443_348");
	assert(b3.getSequenceName2() == "EAS54_6_R1_2_1_443_348");

	const auto &values3 = b3.getSequence();
	assert(values3.size()		== 25);
	assert(values3[0].first		== Common::NucleotideBasis::G);
	assert(values3[0].second	== Common::Quality(';'));
	assert(values3[24].first	== Common::NucleotideBasis::G);
	assert(values3[24].second	== Common::Quality('3'));


	assert(p1.hasNext() == false);

}

int main(){
	TTF_TEST(case1);
}

