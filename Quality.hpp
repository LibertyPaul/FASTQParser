#ifndef QUALITY_HPP
#define QUALITY_HPP

#include <stdexcept>


namespace FASTQ{

namespace Common{

class Quality{
	size_t value;

	static constexpr char rangeStart	= '!';
	static constexpr char rangeEnd		= '~';

public:
	Quality(const char ch): value(ch - rangeStart){
		if(ch < rangeStart || ch > rangeEnd){
			throw std::invalid_argument("Quality is out of range");
		}
	}

	size_t getValue() const{
		return this->value;
	}

	bool operator==(const Quality &quality) const{
		return this->value == quality.value;
	}

	Quality &operator=(const Quality &o){
		this->value = o.value;
		return *this;
	}
};

}

}

#endif // QUALITY_HPP

