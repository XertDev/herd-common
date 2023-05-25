#ifndef HERD_COMMON_STAGE_HPP
#define HERD_COMMON_STAGE_HPP

#include <variant>

#include "herd/common/uuid.hpp"
#include "herd/common/model/circuit/circuit.hpp"


namespace herd::common
{
	struct InputStage
	{
		UUID data_frame_uuid;
	};

	struct MapperStage
	{
		Circuit circuit;
	};

	struct OutputStage
	{
		std::optional<std::string> name;
	};

	using stage_t = std::variant<InputStage, OutputStage, MapperStage>;
}

#endif //HERD_COMMON_STAGE_HPP
