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
		unsigned int field_index;
		unsigned int bit_index;

		InputNode(unsigned int node_tuple_index, unsigned int node_field_index, unsigned int node_bit_index)
		:	tuple_index(node_tuple_index), field_index(node_field_index), bit_index(node_bit_index)
		{}
	};

	struct OutputNode
	{
		unsigned int field_index;
		unsigned int bit_index;

		OutputNode(unsigned int node_field_index, unsigned int node_bit_index)
			:	field_index(node_field_index), bit_index(node_bit_index)
		{}
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
