#ifndef SPAE_RANDOMIZER_INCLUDE
#define SPAE_RANDOMIZER_INCLUDE

// Copyright Akira Takahashi 2015
// Use, modification and distribution is subject to the Boost Software License,
// Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <random>
#include <cstdint>
#include <cstddef>

namespace spae {

class randomizer {
    std::mt19937 engine_;
    std::uniform_int_distribution<std::intmax_t> uniform_int_;
public:
    randomizer()
        : engine_(std::random_device()()) {}

    template <class Integer>
    Integer generate_integer(Integer min_inclusive, Integer max_inclusive)
    {
        decltype(uniform_int_)::param_type param {
            static_cast<std::intmax_t>(min_inclusive),
            static_cast<std::intmax_t>(max_inclusive)
        };

        Integer result = static_cast<Integer>(uniform_int_(engine_, param));
        return result;
    }

    int generate_int(int min_inclusive, int max_inclusive)
    {
        return generate_integer<int>(min_inclusive, max_inclusive);
    }

    std::int32_t generate_int32(std::int32_t min_inclusive, std::int32_t max_inclusive)
    {
        return generate_integer<std::int32_t>(min_inclusive, max_inclusive);
    }

    std::int64_t generate_int64(std::int64_t min_inclusive, std::int64_t max_inclusive)
    {
        return generate_integer<std::int64_t>(min_inclusive, max_inclusive);
    }

    std::size_t generate_size(std::size_t min_inclusive, std::int32_t max_inclusive)
    {
        return generate_integer<std::size_t>(min_inclusive, max_inclusive);
    }

    template <class NonEmptyRange>
    std::size_t select(const NonEmptyRange& r)
    {
        if (r.empty()) {
            throw std::invalid_argument(
                "spae::randomizer::select() : argument range must be not empty");
        }
        return generate_size(0, r.size() - 1);
    }
};

inline randomizer& default_randomizer()
{
    static randomizer instance;
    return instance;
}

} // namespace spae

#endif // SPAE_RANDOMIZER_INCLUDE

