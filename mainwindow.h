#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_btn_calculate_clicked();
    void on_btn_clear_clicked();

    void on_rb_area_clicked();
    void on_rb_perimeter_clicked();

    void on_comboBox_currentIndexChanged(int index);
    void calcultation(QString val);
    void showWarning();


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
