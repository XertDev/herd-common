#ifndef HERD_COMMON_OPERATION_HPP
#define HERD_COMMON_OPERATION_HPP

#include <cstdint>
#include <array>

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

	constexpr std::array<Operation, 1> UNARY_OPERATIONS = {
			Operation::NOT
	};

	constexpr std::array<Operation, 4> BINARY_OPERATIONS = {
			Operation::AND,
			Operation::OR,
			Operation::XOR,
			Operation::NAND
	};

	constexpr std::array<Operation, 1> TERNARY_OPERATIONS = {
			Operation::MUX
	};
}


#endif //HERD_COMMON_OPERATION_HPP
