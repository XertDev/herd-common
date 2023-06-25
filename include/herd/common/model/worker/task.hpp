#ifndef HERD_COMMON_TASK_HPP
#define HERD_COMMON_TASK_HPP

#include "herd/common/uuid.hpp"
#include "herd/common/model/worker/data_frame_ptr.hpp"
#include "herd/common/model/worker/crypto_key_ptr.hpp"
#include "herd/common/model/circuit/circuit.hpp"


namespace herd::common
{
	struct MapTask {
		UUID session_uuid;

		InputDataFramePtr input_data_frame_ptr;
		DataFramePtr output_data_frame_ptr;

		CryptoKeyPtr crypto_key_ptr;

		Circuit circuit;
	};

	struct ReduceTask {
		UUID session_uuid;

		std::vector<InputDataFramePtr> input_data_frame_ptrs;
		DataFramePtr output_data_frame_ptr;

		CryptoKeyPtr crypto_key_ptr;

		Circuit circuit;
	};
}

#endif //HERD_COMMON_TASK_HPP
