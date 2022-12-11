#include "Saper.h"

Saper::Saper(QWidget* parent)
    : QMainWindow(parent)
{
    topBox = new QLabel(this);
    topBox->setFrameStyle(QFrame::Panel | QFrame::Raised);
    topBox->setLineWidth(2);
    
    middleBox = new QLabel(this);
    middleBox->setFrameStyle(QFrame::Panel | QFrame::Raised);
    middleBox->setLineWidth(2);
    
    bottomBox = new QLabel(this);
    bottomBox->setFrameStyle(QFrame::Panel | QFrame::Raised);
    bottomBox->setLineWidth(2);
    
    time = new QLabel(topBox);
    time->setText("Time 00:00");
    time->setStyleSheet(
        "color:red;font-size: 28px;"
    );
    time->setGeometry(10, 10, 140, 40);

    bombs = new QLabel(topBox);
    bombs->setText("Bombs 10");
    bombs->setStyleSheet(
        "color:red;font-size: 28px;"
    );

    level = new QComboBox(bottomBox);
    level->addItem("Beginner");
    level->addItem("Casual");
    level->addItem("Advanced");
    level->addItem("Expert");
    level->setStyleSheet("QListView::item {                             \
                         border-bottom: 5px solid white; margin:3px; }  \
                         QListView::item:selected {                     \
                         border-bottom: 5px solid black; margin:3px;    \
                         color: black; font-size: 55px;                 \
                        }");
    level->setGeometry(100, 15, 120, 30);

    levelInfo = new QLabel(bottomBox);
    levelInfo->setStyleSheet(
        "color:red;font-size: 28px;"
    );
    levelInfo->setGeometry(20, 15, 80, 30);
    levelInfo->setText("Level:");

    reset = new QPushButton(bottomBox);
    reset->setText("Reset/New Game");
    topBox->setGeometry(20, 10, middleBox->width(), 60);
    connect(reset, &QPushButton::clicked, this, &Saper::resetClick);

    gametime.setHMS(0, 0, 0);
    time->setText("Time " + gametime.toString("mm:ss"));
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, QOverload<>::of(&Saper::updateGametime));
    
    resetClick();
}

Saper::~Saper()
{
    delete engine;
}

void Saper::createButtons(int cols, int rows) {
    for (auto btns : buttons) {
        for (auto btn : btns) {
            delete btn;
        }
        
    }
    buttons.clear();

    for (int i = 0; i < cols; i++) {
        buttons.push_back({});
        for (int k = 0; k < rows; k++) {
            btn = new Block(middleBox, i, k);
            btn->show();
            btn->setGeometry(i * 45, k * 45, 45, 45);
            btn->myIcon("null");
            buttons[i].push_back(btn);
        }
    }

    for (auto row : buttons) {
        for (auto b : row){
            connect(b, &Block::leftClicked, this, [this,b]() {emit Saper::blockClick(b); });
            connect(b, &Block::rightClicked, this, [this, b]() {emit Saper::blockLeftClick(b); });
        }
    }
}

void Saper::setGeometry() {
    topBox->setGeometry(20, 10, middleBox->width(), 60);
    bottomBox->setGeometry(20, 40 + topBox->height() + middleBox->height(), middleBox->width(), 60);
    bombs->setGeometry(topBox->width() - 150, 10, 130, 40);
    reset->setGeometry(bottomBox->width() - 140, 15, 120, 30);
    this->resize(middleBox->width()+40, topBox->height()+ middleBox->height()+bottomBox->height()+50);

}
void Saper::resetClick() {
    this->gamestarted = false;
    currLevel = level->currentText();
    if (currLevel == "Beginner")
    {  
        middleBox->setGeometry(20, 20 + topBox->height(), 45 * 8, 45*8);
        createButtons(8, 8);
        bn = 10;
    }
    else if (currLevel == "Casual")
    {
        middleBox->setGeometry(20, 20 + topBox->height(), 45 * 12, 45 * 12);
        createButtons(12, 12);
        bn = 22;
    }
    else if (currLevel == "Advanced")
    {
        middleBox->setGeometry(20, 20 + topBox->height(), 45 * 16, 45 * 16);
        createButtons(16, 16);
        bn = 40;
    }
    else if (currLevel == "Expert")
    {
        middleBox->setGeometry(20, 20 + topBox->height(), 45 * 30, 45 * 16);
        createButtons(30, 16);
        bn = 99;
    }

    bombs->setText("Bombs " + QString::number(bn));
    time->setText("Time " + gametime.toString("mm:ss"));
    setGeometry();
};


void Saper::blockClick(Block *b) {
    if (this->gamestarted == false) {
        timer->start(1000);
        currLevel = level->currentText();
        if (currLevel == "Beginner")
        {
            engine = new Board(8, 8, 10, b->x, b->y);
        }
        else if (currLevel == "Casual")
        {
            engine = new Board(12, 12, 22, b->x, b->y);
        }
        else if (currLevel == "Advanced")
        {
            engine = new Board(16, 16, 40, b->x, b->y);
        }
        else if (currLevel == "Expert")
        {
            engine = new Board(30, 16, 99, b->x, b->y);
        }
        cn = (engine->h * engine->w) - engine->b - 1;
        this->gamestarted = true;
        if (b->currType == "flag") {
            bn++;
            bombs->setText("Bombs " + QString::number(bn));
        };
        b->myIcon(engine->array[b->x][b->y]);
        b->myShow = true;
        showZeros(b->x, b->y);
        win();
    }

    else if (b->myShow == false) {
        int x = b->x;
        int y = b->y;
        if (engine->array[x][y] != "*") {
            if (b->currType == "flag") {
                bn++;
                bombs->setText("Bombs " + QString::number(bn));
            };
            b->myIcon(engine->array[x][y]);
            b->myShow = true;
            cn--;
            showZeros(x, y);
            win();
        }
        else if (b->myShow == false)
        {
            timer->stop();
            gametime.setHMS(0, 0, 0);
            showAll();
            b->myIcon("clickedBomb");
        }
    }
    
}

void Saper::blockLeftClick(Block* b) {
    if (b->myShow == false) {
        if (b->currType == "null") {
            b->myIcon("flag");
            bn--;
            bombs->setText("Bombs " + QString::number(bn));
        }
        else if (b->currType == "flag") {
            b->myIcon("questionmark");
            bn++;
            bombs->setText("Bombs " + QString::number(bn));
        }
        else if (b->currType == "questionmark") {
            b->myIcon("null");  
        }

    }
}

void Saper::showZeros(int x, int y) {
    if (engine->array[x][y] == "0") {
        if (x + 1 < engine->array.size()) {
            if (buttons[x + 1][y]->myShow == false) {
                if (buttons[x + 1][y]->currType == "flag") {
                    bn++;
                    bombs->setText("Bombs " + QString::number(bn));
                }
                buttons[x + 1][y]->myIcon(engine->array[x + 1][y]);
                buttons[x + 1][y]->myShow = true;
                cn--;
                showZeros(x + 1, y);
            }  
        }
        if (y + 1 < engine->array[0].size()) {
            if (buttons[x][y + 1]->myShow == false) {
                if (buttons[x][y + 1]->currType == "flag") {
                    bn++;
                    bombs->setText("Bombs " + QString::number(bn));
                }
                buttons[x][y + 1]->myIcon(engine->array[x][y + 1]);
                buttons[x][y + 1]->myShow = true;
                cn--;
                showZeros(x, y + 1);
            }
        }
        if (x + 1 < engine->array.size() && y + 1 < engine->array[0].size()) {
            if (buttons[x + 1][y + 1]->myShow == false) {
                if (buttons[x + 1][y + 1]->currType == "flag") {
                    bn++;
                    bombs->setText("Bombs " + QString::number(bn));
                }
                buttons[x + 1][y + 1]->myIcon(engine->array[x + 1][y + 1]);
                buttons[x + 1][y + 1]->myShow = true;
                cn--;
                showZeros(x + 1, y + 1);
            }
        }
        if (x - 1 >= 0) {
            if (buttons[x - 1][y]->myShow == false) {
                if (buttons[x - 1][y]->currType == "flag") {
                    bn++;
                    bombs->setText("Bombs " + QString::number(bn));
                }
                buttons[x - 1][y]->myIcon(engine->array[x - 1][y]);
                buttons[x - 1][y]->myShow = true;
                cn--;
                showZeros(x - 1, y);
            }
        }
        if (y - 1 >= 0) {
            if (buttons[x][y - 1]->myShow == false) {
                if (buttons[x][y - 1]->currType == "flag") {
                    bn++;
                    bombs->setText("Bombs " + QString::number(bn));
                }
                buttons[x][y - 1]->myIcon(engine->array[x][y - 1]);
                buttons[x][y - 1]->myShow = true;
                cn--;
                showZeros(x, y - 1);
            }
        }
        if (y - 1 >= 0 && x + 1 < engine->array.size()) {
            if (buttons[x + 1][y - 1]->myShow == false) {
                if (buttons[x + 1][y - 1]->currType == "flag") {
                    bn++;
                    bombs->setText("Bombs " + QString::number(bn));
                }
                buttons[x + 1][y - 1]->myIcon(engine->array[x + 1][y - 1]);
                buttons[x + 1][y - 1]->myShow = true;
                cn--;
                showZeros(x + 1, y - 1);
            }
        }
        if (x - 1 >= 0 && y + 1 < engine->array[0].size()) {
            if (buttons[x - 1][y + 1]->myShow == false) {
                if (buttons[x - 1][y + 1]->currType == "flag") {
                    bn++;
                    bombs->setText("Bombs " + QString::number(bn));
                }
                buttons[x - 1][y + 1]->myIcon(engine->array[x - 1][y + 1]);
                buttons[x - 1][y + 1]->myShow = true;
                cn--;
                showZeros(x - 1,y + 1);
            }
        }
        if (x - 1 >= 0 && y - 1 >= 0) {
            if (buttons[x - 1][y - 1]->myShow == false) {
                if (buttons[x - 1][y - 1]->currType == "flag") {
                    bn++;
                    bombs->setText("Bombs " + QString::number(bn));
                }
                buttons[x - 1][y - 1]->myIcon(engine->array[x - 1][y - 1]);
                buttons[x - 1][y - 1]->myShow = true;
                cn--;
                showZeros(x - 1, y - 1);
            }
        }

    }
}

void Saper::showAll() {
    for (int i = 0; i < buttons.size(); i++) {
        for (int k = 0; k < buttons[0].size(); k++) {
            buttons[i][k]->myIcon(engine->array[i][k]);
            buttons[i][k]->myShow = true;
        }
    }
}

void Saper::win() {
    if (cn == 0) {
        timer->stop();
        int ret = QMessageBox::information(this, "You Win!!", "You win on level " + currLevel +"\nYour time is " + gametime.toString("mm:ss"));
        for (auto i : buttons) {
            for (auto k : i) {
                k->myShow = true;
            }
        }
        gametime.setHMS(0, 0, 0);

    }
}

void Saper::updateGametime() {
    gametime = gametime.addSecs(1);
    time->setText("Time " + gametime.toString("mm:ss"));
}