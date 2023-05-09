#ifndef HERD_COMMON_EXECUTION_PLAN_HPP
#define HERD_COMMON_EXECUTION_PLAN_HPP

#include <cstdint>
#include <optional>
#include <vector>

#include "herd/common/model/schema_type.hpp"

#include "herd/common/dag.hpp"
#include "herd/common/uuid.hpp"


namespace herd::common
{
	struct ExecutionPlan {
		enum class StageType : uint8_t
		{
			INPUT,
			MAP
		};

		struct Stage {
			StageType operation_type;
			SchemaType schema_type;

			std::optional<UUID> required_data_frame;
		};

		herd::common::DAG<Stage> stages;
	};
} // namespace herd::common

#endif //HERD_COMMON_EXECUTION_PLAN_HPP
