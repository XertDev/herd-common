#ifndef HERD_COMMON_STAGE_HPP
#define HERD_COMMON_STAGE_HPP

#include <variant>

#include "herd/common/uuid.hpp"
#include "herd/common/model/circuit/circuit.hpp"


namespace herd::common
{
	enum class Policy
	{
		SEQUENCED,
		PARALLEL,
		PARALLEL_FULL
	};

	struct InputStage
	{
		UUID data_frame_uuid;
	};

	struct MapperStage
	{
		Circuit circuit;
	};

	struct ReduceStage
	{
		Circuit circuit;
		Policy policy = Policy::PARALLEL;
		std::optional<uint32_t> per_node_count = std::nullopt;
	};

	struct OutputStage
	{
		std::optional<std::string> name;
	};

	using stage_t = std::variant<InputStage, OutputStage, MapperStage, ReduceStage>;
}

#endif //HERD_COMMON_STAGE_HPP
