#include "Board.h"


Board::Board(int height, int widht, int bombs, int coll, int roww) :h(height), w(widht), b(bombs), c(coll), r(roww) {
	std::srand(std::time(0));
	std::vector<std::string> row;

	for (int n = 0; n < w; n++) {
		row.push_back("0");
	};

	for (int n = 0; n < h; n++) {
		array.push_back(row);
	};

	set_bombs();
	set_values();
};


void Board::set_bombs() {
	std::srand(std::time(0));
	std::vector<std::array<int, 2>> positions = {};
	for (int i = 0; i < h; i++) {
		for (int k = 0; k < w; k++) {
			if ((i != c || k != r) && (i != c + 1 || k != r) && (i != c + 1 || k != r + 1) && (i != c + 1 || k != r + -1) && (i != c || k != r + 1) && (i != c || k != r + -1)
				&& (i != c - 1 || k != r) && (i != c - 1 || k != r + 1) && (i != c - 1 || k != r - 1))
			{
				positions.push_back({ i,k });
			};
			
		};
	};

	int elements = 0;
	int index = 0;
	while (elements != b) {
		index = rand() % positions.size();
		array[positions[index][0]][positions[index][1]] = "*";
		positions.erase(positions.begin() + index);
		elements++;
	};
};

void Board::set_values() {
	for (int i = 0; i < array.size(); i++) {
		for (int k = 0; k < array[0].size(); k++) {
			int bombs = 0;
			if (array[i][k] != "*") {
				if (i + 1 < array.size()) {
					if (array[i + 1][k] == "*") {
						bombs++;
					}
				}
				if (k + 1 < array[0].size()) {
					if (array[i][k+1] == "*") {
						bombs++;
					}
				}
				if ((i + 1 < array.size()) && (k + 1 < array[0].size()) ) {
					if (array[i+1][k+1] == "*") {
						bombs++;
					}
				}
				if (i - 1 >= 0) {
					if (array[i - 1][k] == "*") {
						bombs++;
					}
				}
				if (k - 1 >= 0) {
					if (array[i][k-1] == "*") {
						bombs++;
					}
				}
				if ((i - 1 >= 0) && (k - 1 >= 0)) {
					if (array[i - 1][k-1] == "*") {
						bombs++;
					}
				}
				if ((i + 1 < array.size()) && (k - 1 >= 0)) {
					if (array[i + 1][k - 1] == "*") {
						bombs++;
					}
				}
				if ((i - 1 >= 0) && (k + 1 < array[0].size())) {
					if (array[i - 1][k + 1] == "*") {
						bombs++;
					}
				}
				array[i][k] = std::to_string(bombs);
			}
		}
	}
}
