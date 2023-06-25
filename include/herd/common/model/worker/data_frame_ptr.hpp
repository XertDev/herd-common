#ifndef HERD_COMMON_DATA_FRAME_PTR_HPP
#define HERD_COMMON_DATA_FRAME_PTR_HPP

#include "herd/common/uuid.hpp"


namespace herd::common
{
	struct DataFramePtr
	{
		UUID uuid;
		uint64_t block_id;
	};

	struct InputDataFramePtr
	{
		DataFramePtr pointer;
		uint64_t row_count;
	};
}

#endif //HERD_COMMON_DATA_FRAME_PTR_HPP
