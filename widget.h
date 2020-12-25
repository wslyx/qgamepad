#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QGamepad>
#include <QGamepadManager>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    QGamepad *m_gamepad;

    void showCurrentBtnName(bool pressed, QString name);
    void showBtnVaule(int btnName, double value);
};

#endif // WIDGET_H
