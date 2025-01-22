#include <QApplication>
#include <QWidget>
#include <QIcon>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTimer>
#include <QMessageBox>

QPushButton* button;
QLabel* timerLabel;
int count {0};
int timeLeft {60};
QTimer* timer;
bool isFirstClick {true};

void onButtonClicked();
void updateTimer();

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QWidget* widget = new QWidget();
    widget->setWindowTitle("Click counter");
    widget->setMinimumSize(300, 200);
    widget->setWindowIcon(QIcon("Click.png"));

    QLabel* label = new QLabel("Applications for counting mouse clicks", widget);
    label->setMinimumSize(75, 25);

    button = new QPushButton("Click me!", widget);
    button->setMinimumSize(75, 50);
    button->setIcon(QIcon("ButtonLeftClick.png"));

    timerLabel = new QLabel("Time left: 60 seconds", widget);
    timerLabel->setMinimumSize(75, 25);

    QVBoxLayout* layout = new QVBoxLayout();

    widget->setLayout(layout);
    layout->addWidget(label);
    layout->addWidget(timerLabel);
    layout->addWidget(button);

    QObject::connect(button, &QPushButton::clicked, onButtonClicked);

    timer = new QTimer(widget);
    QObject::connect(timer, &QTimer::timeout, updateTimer);

    widget->show();

    return a.exec();
}

void onButtonClicked() {
    if (isFirstClick) {
        timer->start(1000);
        isFirstClick = false;
    }

    if (timeLeft > 0) {
        button->setText("Clicks done: " + QString::number(++count));
    }
}

void updateTimer() {
    if (timeLeft > 0) {
        timeLeft--;
        timerLabel->setText("Time left: " + QString::number(timeLeft) + " seconds");
    } else {
        timer->stop();
        QMessageBox::information(nullptr, "Time's up!", "Your score: " + QString::number(count));
        button->setEnabled(false);
    }
}
