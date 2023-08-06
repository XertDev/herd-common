#ifndef HERD_COMMON_UUID_HPP
#define HERD_COMMON_UUID_HPP


#ifdef __linux__
	#include <uuid/uuid.h>
#else
	#error "System not supported"
#endif

#include <compare>
#include <ranges>
#include <string>
#include <cstdint>

namespace herd::common
{
	class UUID
	{
	public:
		UUID();
		explicit UUID(const std::string& uuid_string);

		[[nodiscard]] std::string as_string() const;
		[[nodiscard]] std::array<uint8_t, 16> as_bytes() const;

		friend bool operator==(const UUID& lhs, const UUID& rhs);
		friend std::strong_ordering operator<=>(const UUID& lhs, const UUID& rhs);

	private:
		uuid_t uuid_{};
	};
}

namespace std
{
	template<>
	struct hash<herd::common::UUID>
	{
		size_t operator()(const herd::common::UUID& uuid) const;
	};
}

#endif //HERD_COMMON_UUID_HPP
