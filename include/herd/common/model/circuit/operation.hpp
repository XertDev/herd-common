#ifndef HERD_COMMON_OPERATION_HPP
#define HERD_COMMON_OPERATION_HPP

#include <cstdint>
#include <vector>

#include "herd/common/model/schema_type.hpp"


namespace herd::common
{
	enum class Operation : uint8_t
	{
		AND,
		OR,
		NOT,
		XOR,
		NAND,
		MUX,
	};
}


#endif //HERD_COMMON_OPERATION_HPP
