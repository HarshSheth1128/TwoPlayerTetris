#include "GridCell.h"

// constructors
GridCell::GridCell(int p_x, int p_y){
	this->x = p_x;
	this->y = p_y;
	this->cellChar = '-';
}

// destructors
GridCell::~GridCell(){
	// neighbours should be deleted by the Grid object to avoid double deletion
}

// methods

int GridCell::getX(){
	return this->x;
}

int GridCell::getY(){
	return this->y;
}

void GridCell::setX(int p_x){
	this->x = p_x;
}

void GridCell::setY(int p_y){
	this->y = p_y;
}

char GridCell::getType(){
	return this->cellChar;
}

void GridCell::setNeighbour(std::string position, GridCell* p_neighbour){
	std::pair<std::string, GridCell*> value(position, p_neighbour);
	(this->neighbours).emplace(value);
}

// io operators

std::ostream& operator<<(std::ostream& out, GridCell& cell){
	out << cell.cellChar;
	return out;
}
