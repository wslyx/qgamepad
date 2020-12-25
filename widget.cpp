#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    m_gamepad = new QGamepad(0, this);

    connect(m_gamepad, &QGamepad::buttonSelectChanged, this, [=](bool pressed){
        showCurrentBtnName(pressed, "buttonSelect");
    });
    connect(m_gamepad, &QGamepad::buttonStartChanged, this, [=](bool pressed){
        showCurrentBtnName(pressed, "buttonStart");
    });
    connect(m_gamepad, &QGamepad::buttonAChanged, this, [=](bool pressed){
        showCurrentBtnName(pressed, "buttonA");
    });
    connect(m_gamepad, &QGamepad::buttonBChanged, this, [=](bool pressed){
        showCurrentBtnName(pressed, "buttonB");
    });
    connect(m_gamepad, &QGamepad::buttonXChanged, this, [=](bool pressed){
        showCurrentBtnName(pressed, "buttonX");
    });
    connect(m_gamepad, &QGamepad::buttonYChanged, this, [=](bool pressed){
        showCurrentBtnName(pressed, "buttonY");
    });
    connect(m_gamepad, &QGamepad::buttonL1Changed, this, [=](bool pressed){
        showCurrentBtnName(pressed, "buttonL1");
    });
    connect(m_gamepad, &QGamepad::buttonR1Changed, this, [=](bool pressed){
        showCurrentBtnName(pressed, "buttonR1");
    });
    connect(m_gamepad, &QGamepad::buttonL2Changed, this, [=](bool pressed){
        showCurrentBtnName(pressed, "buttonL2");
    });
    connect(m_gamepad, &QGamepad::buttonR2Changed, this, [=](bool pressed){
        showCurrentBtnName(pressed, "buttonR2");
    });
    connect(m_gamepad, &QGamepad::buttonL2Changed, this, [=](double value){
        showBtnVaule(1, value);
    });
    connect(m_gamepad, &QGamepad::buttonR2Changed, this, [=](double value){
        showBtnVaule(2, value);
    });
    connect(m_gamepad, &QGamepad::axisLeftXChanged, this, [=](double value){
        showBtnVaule(3, value);
    });
    connect(m_gamepad, &QGamepad::axisLeftYChanged, this, [=](double value){
        showBtnVaule(4, value);
    });
    connect(m_gamepad, &QGamepad::axisRightXChanged, this, [=](double value){
        showBtnVaule(5, value);
    });
    connect(m_gamepad, &QGamepad::axisRightYChanged, this, [=](double value){
        showBtnVaule(6, value);
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::showCurrentBtnName(bool pressed, QString name)
{
    if(pressed)
    {
        ui->leCurrentBtnName->setText(name);
    }
    else
    {
        ui->leCurrentBtnName->clear();
    }
}

void Widget::showBtnVaule(int btnName, double value)
{
    switch (btnName) {
        //buttonL2
    case 1:
        ui->leLt->setText(QString::number(value));
        break;
        //buttoR2
    case 2:
        ui->leRt->setText(QString::number(value));
        break;
        //buttonL3, axisLeftX
    case 3:
        if(value < 0)
        {
            ui->leLeftX1->setText(QString::number(value));
        }
        else if(value > 0)
        {
            ui->leLeftX2->setText(QString::number(value));
        }
        else
        {
            ui->leLeftX1->setText("0");
            ui->leLeftX2->setText("0");
        }
        break;
        //buttonL3, axisLeftY
    case 4:
        if(value < 0)
        {
            ui->leLeftY1->setText(QString::number(value));
        }
        else if(value > 0)
        {
            ui->leLeftY2->setText(QString::number(value));
        }
        else
        {
            ui->leLeftY1->setText("0");
            ui->leLeftY2->setText("0");
        }
        break;
        //buttonR3, axisRightX
    case 5:
        if(value < 0)
        {
            ui->leRightX1->setText(QString::number(value));
        }
        else if(value > 0)
        {
            ui->leRightX2->setText(QString::number(value));
        }
        else
        {
            ui->leRightX1->setText("0");
            ui->leRightX2->setText("0");
        }
        break;
        //buttonR3, axisRightY
    case 6:
        if(value < 0)
        {
            ui->leRightY1->setText(QString::number(value));
        }
        else if(value > 0)
        {
            ui->leRightY2->setText(QString::number(value));
        }
        else
        {
            ui->leRightY1->setText("0");
            ui->leRightY2->setText("0");
        }
        break;
    default:
        break;
    }
}

