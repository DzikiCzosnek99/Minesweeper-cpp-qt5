#include <QPushButton>
#include <QObject>
#include <QWidget>
#include <QMouseEvent>

class Block: public QPushButton
{
	Q_OBJECT
public:
	explicit Block(QWidget* parent, int col, int row);
	int x{};
	int y{};
	bool myShow = false;
	std::string path = "";
	std::string currType = "0";

	void myIcon(std::string type);


private slots:
	void mousePressEvent(QMouseEvent* e);
signals:
	void rightClicked();
	void leftClicked();
};

