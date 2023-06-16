#ifndef HERD_COMMON_CRYPTO_KEY_PTR_HPP
#define HERD_COMMON_CRYPTO_KEY_PTR_HPP

#include "herd/common/model/schema_type.hpp"
#include "herd/common/uuid.hpp"


namespace herd::common
{
	struct CryptoKeyPtr
	{
		SchemaType schema_type;
	};
}

#endif //HERD_COMMON_CRYPTO_KEY_PTR_HPP
