#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QPushButton>

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
    void on_actionNew_triggered();
    void on_actionRectangle_triggered();
    void on_toolButton_next_clicked();
    void on_toolButton_prev_clicked();

    void button_clicked(QPushButton*);

private:
    Ui::MainWindow *ui;
    int m_current_slide = 0;
    QVBoxLayout *lay = new QVBoxLayout(this);
};
#endif // MAINWINDOW_H
