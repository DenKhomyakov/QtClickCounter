#include <QApplication>
#include <QWidget>
#include <QIcon>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

QPushButton* button;
int count {0};

void onButtonClicked();

int main(int argc, char *argv[])
{
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

    QVBoxLayout* layout = new QVBoxLayout();

    widget->setLayout(layout);
    layout->addWidget(label);
    layout->addWidget(button);

    QObject::connect(button, &QPushButton::clicked, onButtonClicked);

    widget->show();

    return a.exec();
}

void onButtonClicked() {
    button->setText("Clicks done: " + QString::number(++count));
}
