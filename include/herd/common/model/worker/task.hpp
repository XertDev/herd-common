#ifndef HERD_COMMON_TASK_HPP
#define HERD_COMMON_TASK_HPP

#include "herd/common/uuid.hpp"
#include "herd/common/model/worker/data_frame_ptr.hpp"
#include "herd/common/model/worker/crypto_key_ptr.hpp"
#include "herd/common/model/circuit/circuit.hpp"


namespace herd::common
{
	struct Task
	{
		UUID session_uuid;

		DataFramePtr input_data_frame_ptr;
		DataFramePtr output_data_frame_ptr;
		uint64_t row_count;

		CryptoKeyPtr crypto_key_ptr;

		Circuit circuit;
	};
}

#endif //HERD_COMMON_TASK_HPP
