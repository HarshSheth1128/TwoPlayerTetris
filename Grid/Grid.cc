#include "Grid.h"

// Constructors

/* Currently, the position strings can be top, right, left, bottom
   top-right, top-left, bottom-right and bottom-left*/

Grid::Grid(int p_width, int p_height): width{p_width}, height{p_height}{
	for(int w = 0; w < p_width; w++){
		std::vector<GridCell> grid_row; // creates a row
		for(int h = 0; h < p_height; h++){
			grid_row.emplace_back(GridCell(w, h)); // places the new GridCells in the row
		}
		this->cells.emplace_back(grid_row);
	}

	// Loop through again to set neighbours
	// Must be done on the second run because previous grid cells may have
	// been reallocated to new spaces in memory
	for(int w = 0; w < p_width; w++){
		std::vector<GridCell> grid_row; // creates a row
		for(int h = 0; h < p_height; h++){
			if(w > 0){ // set left cell
				this->cells.at(w).at(h).setNeighbour("left", &(this->cells.at(w - 1).at(h)));
				this->cells.at(w - 1).at(h).setNeighbour("right", &(this->cells.at(w).at(h)));
			}

			if(h > 0 && w > 0){// set top-left cell
				this->cells.at(w).at(h).setNeighbour("top-left", &(this->cells.at(w - 1).at(h - 1)));
				this->cells.at(w - 1).at(h - 1).setNeighbour("bottom-right", &(this->cells.at(w).at(h)));
			}

			if(h > 0){// set top cell
				this->cells.at(w).at(h).setNeighbour("top", &(this->cells.at(w).at(h - 1)));
				this->cells.at(w).at(h - 1).setNeighbour("bottom", &(this->cells.at(w).at(h)));
			}

			if(h > 0 && w < p_width - 1){// set top-right cell
				this->cells.at(w).at(h).setNeighbour("top-right", &(this->cells.at(w + 1).at(h - 1)));
				this->cells.at(w + 1).at(h - 1).setNeighbour("bottom-left", &(this->cells.at(w).at(h)));
			}
		}
	}
}

// Methods

std::vector<GridCell> Grid::getRow(int i){
	return this->cells.at(i);
}

int Grid::getWidth(){
	return this->width;
}

int Grid::getHeight(){
	return this->height;
}
