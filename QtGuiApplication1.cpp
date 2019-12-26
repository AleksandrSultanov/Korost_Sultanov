#include "QtGuiApplication1.h"
#include <QMessageBox>
#include <list>
#include <QString>

QtGuiApplication1::QtGuiApplication1(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton, SIGNAL(returnPressed()), this, SLOT(Main()));
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(Main()));
}

class Tickets
{
private:
	list<string> Tic;
public:
	void Input();
	void Add(string, string, string, string, string, string, string, string);
	void Show();
};

void QtGuiApplication1::Main()
{
	QString Destination = ui.lineEdit->text();
	QString FlightNumber = ui.lineEdit_2->text();
	QString FullName = ui.lineEdit_3->text();
	int minute = ui.timeEdit->time().minute();
	int hour = ui.timeEdit->time().hour();
	int day = ui.dateEdit->date().day();
	int month = ui.dateEdit->date().month();
	int year = ui.dateEdit->date().year();

	if ((FlightNumber > 0) && (day > 0) && (month > 0) && (year > 0) &&
		(Destination != 0) && (Destination.size() > 0) && (FullName != 0) && (FullName.size() > 0))
	{
		Tickets a;
		a.Add(Destination.toLocal8Bit().constData(), FlightNumber.toLocal8Bit().constData(), FullName.toLocal8Bit().constData(), QString::number(minute).toLocal8Bit().constData(), QString::number(hour).toLocal8Bit().constData(), QString::number(day).toLocal8Bit().constData(), QString::number(month).toLocal8Bit().constData(), QString::number(year).toLocal8Bit().constData());
		a.Show();
	}
	else Error();
}

void Tickets::Add(string Destination, string FlightNumber, string FullName, string minute, string hour, string day, string month, string year)
{
	string str = Destination + " " + FlightNumber + " " + FullName + " " + minute + ":" + hour + " " + day + "." + month + "." + year;
	Tic.push_back(str);
}

void QtGuiApplication1::Error()
{
	QMessageBox msgbox;
	msgbox.setWindowTitle("Error");
	msgbox.setText("Check the accuracy of the data entered!");
	msgbox.exec();
}

void Tickets::Show()
{
	string  str = Tic.back();
	//string str1 = *str;
	//string str = Tic[];
	QMessageBox msgbox;
	msgbox.setWindowTitle("Ticket information");
	msgbox.setText(QString::fromStdString(str));
	msgbox.exec();
}