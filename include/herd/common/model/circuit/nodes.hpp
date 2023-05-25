#ifndef HERD_COMMON_NODES_HPP
#define HERD_COMMON_NODES_HPP

#include <cstdint>
#include <variant>

#include "herd/common/model/circuit/operation.hpp"


namespace herd::common
{
	struct InputNode
	{
		unsigned int tuple_index;
		unsigned int bit_index;
	};

	struct OutputNode
	{
		unsigned int tuple_index;
		unsigned int bit_index;
	};

	struct ConstantNode
	{
		bool value;
	};

	struct OperationNode
	{
		common::Operation type;
	};

	using node_t = std::variant<InputNode, OutputNode, ConstantNode, OperationNode>;
}

#endif //HERD_COMMON_NODES_HPP
