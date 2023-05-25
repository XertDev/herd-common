#ifndef HERD_COMMON_EXECUTION_PLAN_HPP
#define HERD_COMMON_EXECUTION_PLAN_HPP

#include "herd/common/dag.hpp"
#include "herd/common/model/executor/stage.hpp"

namespace herd::common
{
	struct ExecutionPlan
	{
		common::DAG<stage_t> execution_graph;
		common::SchemaType schema_type;
	};
}

#endif //HERD_COMMON_EXECUTION_PLAN_HPP
