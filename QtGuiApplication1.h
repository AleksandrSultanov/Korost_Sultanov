#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtGuiApplication1.h"
#include <string>
using namespace std;


class QtGuiApplication1 : public QMainWindow
{
	Q_OBJECT

public:
	QtGuiApplication1(QWidget *parent = Q_NULLPTR);
private:
	Ui::QtGuiApplication1Class ui;
public slots:
	void Main();                                                                   //���������� �������� pushButton, �������� connect �� click, � ���� ����� ����� ���������� ��� ����� �.� �� �������
	void Error();                                                                  //���������� �� Main, ������������ ������ � ������������ ������    
};
