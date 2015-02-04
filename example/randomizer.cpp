// Copyright Akira Takahashi 2015
// Use, modification and distribution is subject to the Boost Software License,
// Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#include <iostream>
#include <string>
#include <map>
#include <spae/randomizer.hpp>

enum class color {
    blue,
    yellow,
    red,
    range_min = blue,
    range_max = red
};

std::string as_string(color c)
{
    const std::map<color, std::string> dict = {
        {color::blue,   "blue"},
        {color::yellow, "yellow"},
        {color::red,    "red"}
    };
    return dict.at(c);
}

int main()
{
	// roll dice
	int number_of_roll = spae::default_randomizer().generate_int(1, 6);
	std::cout << number_of_roll << std::endl;

	// generate random enum value
    const color random_color = spae::default_randomizer().generate_integer(
              	              	color::range_min,
                            	color::range_max);
    std::cout << as_string(random_color) << std::endl;

	// select random index
	const std::vector<std::string> candidates = {
		"Awesome!!",
		"Great!",
		"Good",
		"Bad"
	};
	const std::size_t random_index = spae::default_randomizer().select(candidates);
	std::cout << candidates.at(random_index) << std::endl;
}
