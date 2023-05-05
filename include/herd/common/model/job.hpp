#ifndef HERD_COMMON_JOB_HPP
#define HERD_COMMON_JOB_HPP

#include <cstdint>


namespace herd::common
{
	enum class JobStatus: uint8_t
	{
		WAITING_FOR_EXECUTION = 0,
		PENDING = 1,
		COMPLETED = 2,
		FAILED = 3
	};
}

#endif //HERD_COMMON_JOB_HPP
