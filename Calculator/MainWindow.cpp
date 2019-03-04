#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QDoubleValidator>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->operatorComboBox->addItem("+");
    ui->operatorComboBox->addItem("-");
    ui->operatorComboBox->addItem("x");
    ui->operatorComboBox->addItem("/");

    QDoubleValidator *validator = new QDoubleValidator(-10000.0, 10000.0, 3, this);
    ui->num1Edit->setValidator(validator);
    ui->num2Edit->setValidator(validator);

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

    double result;

    int currentOption = ui->operatorComboBox->currentIndex();
    switch (currentOption) {
    case 0: // +
        result = num1 + num2;
        break;
    case 1: // -
        result = num1 - num2;
        break;
    case 2: // x
        result = num1 * num2;
        break;
    case 3: // division
        result = num1 / num2;
        break;
    default:
        QMessageBox::critical(this, "Erro!", "Operação Inválida!");
        return;
    }

    QString msg = QString("O resultado de %0 %1 %2 é %3").arg(
        ui->num1Edit->text(), ui->operatorComboBox->currentText(), ui->num2Edit->text(), 
        QString::number(result));


    // Show message box with result
    QMessageBox::information(this, "Resultado", msg);
}
