#ifndef HERD_COMMON_CIRCUIT_HPP
#define HERD_COMMON_CIRCUIT_HPP

#include <vector>

#include "herd/common/dag.hpp"
#include "herd/common/model/data_type.hpp"
#include "herd/common/model/circuit/nodes.hpp"


namespace herd::common
{
	struct Circuit
	{
		std::vector<unsigned int> input;
		std::vector<unsigned int> output;

		common::DAG<node_t> circuit_graph;
	};
}

#endif //HERD_COMMON_CIRCUIT_HPP
