#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <iostream>
#include<QMessageBox>


QString action_after_combo_selection = "";
QString selectedComboItem = "";
QString le_value;
double output;
double pi = 3.142;



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

     ui->setupUi(this);

}

MainWindow::~MainWindow()
{

    delete ui;
}

//warning for discriminant less than 0
//void MainWindow::showWarning()
//{
//      QMessageBox warning;
//      warning.setText("WARNING!\nEmpty Value, Please input values greater than 0");
//      warning.setIcon(QMessageBox::Warning);
//      warning.setWindowTitle("Warning");
//      warning.exec();
//}

//warning for discriminant less than 0
void MainWindow::showWarning()
{
    QMessageBox::warning(this, "WARNING", "Empty Value, Please input values greater than 0");
}


void MainWindow::on_rb_area_clicked()
{
    action_after_combo_selection = "Area";
    calcultation(action_after_combo_selection);
}


void MainWindow::on_rb_perimeter_clicked()
{

    action_after_combo_selection = "Perimeter";
    calcultation(action_after_combo_selection);
}

void MainWindow::calcultation(QString val)
{

     qDebug().noquote() << val;
}


void MainWindow::on_comboBox_currentIndexChanged(int index)
{

    selectedComboItem = ui->comboBox->currentText();
    calcultation(selectedComboItem);
}


void MainWindow::on_btn_calculate_clicked()
{
    //perform calculation
    calcultation(ui->le_value->text());
    le_value = ui->le_value->text();

    if(le_value.isEmpty()){
            showWarning();
    }else if(action_after_combo_selection == "Area"){
        //perform area calculation for the chosen shape
        if(selectedComboItem == "Circle"){
            //perform area calculation for a circle
            output = pi*ui->le_value->text().toDouble()*ui->le_value->text().toDouble();
            ui->le_answer->setText(QString::number(output));

        }else if(selectedComboItem == "Square"){
           //perform area calculation for a square
            output = ui->le_value->text().toDouble()*ui->le_value->text().toDouble();
            ui->le_answer->setText(QString::number(output));
        }

    }else{
        //perform perimeter calculation
        //perform perimeter calculation for the chosen shape
        if(selectedComboItem == "Circle"){
            //perform perimeter calculation for a circle
            output = 2 * pi * ui->le_value->text().toDouble();
            ui->le_answer->setText(QString::number(output));

        }else if(selectedComboItem == "Square"){
           //perform perimeter calculation for a square
            output = 4 * ui->le_value->text().toDouble();
            ui->le_answer->setText(QString::number(output));
        }
    }
}


void MainWindow::on_btn_clear_clicked()
{
    ui->le_answer->clear();
}

