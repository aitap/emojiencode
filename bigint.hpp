#include <type_traits>
#include <vector>

template <typename T, typename U>
class bigint {
	U base;
	std::vector<T> digits;
public:
	template <typename V>
	bigint(U base_, V num = 0u) :base(base_) {
		static_assert(std::is_unsigned<T>::value, "Digits must be of unsigned integer type");
		static_assert(std::is_unsigned<U>::value, "Base must be of unsigned integer type");
		static_assert(std::is_unsigned<V>::value, "Initial value must be of unsigned integer type");
		while (num) {
			digits.push_back(num % base);
			num /= base;
		}
	}

	template <typename V>
	bigint & operator *= (V mul) {
		static_assert(std::is_unsigned<V>::value, "Multiplier must be of unsigned integer type");
		#error unimplemented
	}

	template <typename V>
	bigint & operator += (V add) {
		static_assert(std::is_unsigned<V>::value, "Summand must be of unsigned integer type");
		#error unimplemented
	}
}
