#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QDoubleValidator>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	QDoubleValidator *validator = new QDoubleValidator(-10000.0, 10000.0, 3, this);
	ui->num1Edit->setValidator(validator);
	ui->num2Edit->setValidator(validator);
	ui->num3Edit->setValidator(validator);

	connect(ui->butao, &QPushButton::clicked, this, &MainWindow::computeResult);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::computeResult()
{
	// Read numbes from fields
	double num1 = ui->num1Edit->text().toDouble();
	double num2 = ui->num2Edit->text().toDouble();
	double num3 = ui->num2Edit->text().toDouble();
	double result = num1 + num2 + num3;
	QString msg = QString("result %0").arg(QString::number(result));
	// Show message box with result
	QMessageBox::information(this, "Result", msg);
}