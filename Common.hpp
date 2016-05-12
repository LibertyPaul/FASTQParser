#ifndef COMMON_HPP
#define COMMON_HPP

#include <stdexcept>

namespace FASTQ{

namespace Common{

enum class NucleotideBasis{
	A, T, G, C
};

NucleotideBasis fromChar(const char ch);


}

}

#endif // COMMON_HPP

