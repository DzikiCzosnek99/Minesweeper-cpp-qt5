#include "Block.h"

Block::Block(QWidget* parent, int col, int row) : QPushButton(parent), x(col), y(row) {}
	


void Block::myIcon(std::string type) {
	if (type == "0") {
		path = "textures/zero.PNG";
	}
	else if (type == "1") {
		path="textures/one.PNG";
	}
	else if (type == "2") {
		path = "textures/two.PNG";
	}
	else if (type == "3") {
		path = "textures/three.png";
	}
	else if (type == "4") {
		path = "textures/four.png";
	}
	else if (type == "5") {
		path = "textures/five.png";
	}
	else if (type == "6") {
		path = "textures/six.png";
	}
	else if (type == "7") {
		path = "textures/seven.png";
	}
	else if (type == "8") {
		path = "textures/eight.png";
	}
	else if (type == "flag") {
		path = "textures/flag.png";
	}
	else if (type == "null") {
		path = "textures/null.png";
	}
	else if (type == "*") {
		path = "textures/bomb.png";
	}
	else if (type == "clickedBomb") {
		path = "textures/clickedBomb.png";
	}
	else if (type == "questionmark") {
		path = "textures/questionmark.png";
	}

	QPixmap pixmap(QString::fromStdString(path));
	QIcon ButtonIcon(pixmap);
	this->setIcon(ButtonIcon);
	this->setIconSize(pixmap.rect().size());
	currType = type;
}

void Block::mousePressEvent(QMouseEvent* e) {
	if (e->button()==Qt::RightButton) {
		emit rightClicked();
	}
	else if (e->button() == Qt::LeftButton) {
		emit leftClicked();
	}
}