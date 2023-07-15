#ifndef HERD_COMMON_CIRCUIT_HPP
#define HERD_COMMON_CIRCUIT_HPP

#include <vector>
#include <string>

#include "herd/common/dag.hpp"
#include "herd/common/model/data_type.hpp"
#include "herd/common/model/circuit/nodes.hpp"


namespace herd::common
{
	struct Circuit
	{
		struct OutputColumn
		{
			std::string name;
			DataType data_type;

			OutputColumn(std::string column_name, DataType column_data_type)
			: name(std::move(column_name)), data_type(column_data_type)
			{}
		};

		std::vector<DataType> input;
		std::vector<OutputColumn> output;

		common::DAG<node_t> circuit_graph;
	};
}

#endif //HERD_COMMON_CIRCUIT_HPP
