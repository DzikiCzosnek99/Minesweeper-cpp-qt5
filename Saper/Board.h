#include <string>
#include <vector>
#include <cstdlib>
#include <array>
#include <ctime>


class Board
{
public:
	Board(int height, int widht, int bombs, int coll, int roww);
	int h{}, w{}, b{}, c{}, r{};
	std::string bomb = "*";
	std::vector<std::vector<std::string>> array;

	void set_bombs();
	void set_values();
};

