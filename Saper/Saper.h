#pragma once

#include <QtWidgets/QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <QPushButton>
#include <QMessageBox>
#include <QTime>
#include <QTimer>
#include <vector>
#include "Block.h"
#include "Board.h"

class Saper : public QMainWindow
{
    Q_OBJECT

public:
    Saper(QWidget *parent = nullptr);
    ~Saper();
    
public slots:
    void resetClick();
    void setGeometry();
    void createButtons(int cols, int rows);
    void blockClick(Block *b);
    void blockLeftClick(Block* b);
    void showZeros(int x, int y);
    void showAll();
    void win();
    void updateGametime();
    


private:
    QLabel* topBox, *middleBox, * bottomBox, *time, * bombs, *levelInfo;
    QComboBox* level;
    QPushButton* reset;
    Block* btn;
    QString currLevel;
    QTime gametime;
    QTimer *timer;
    Board* engine;
    std::vector<std::vector<Block*>> buttons;
    bool gamestarted = false;
    int bn = 0;
    int cn = 0;
    
    
};


