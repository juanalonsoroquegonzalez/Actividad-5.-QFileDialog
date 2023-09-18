#ifndef MENU_H
#define MENU_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Menu; }
QT_END_NAMESPACE

class Menu : public QMainWindow
{
    Q_OBJECT

public:
    Menu(QWidget *parent = nullptr);
    ~Menu();

private slots:
    void on_buttonAgregar_clicked();

    void on_textNeuronas_textChanged();

    void on_buttonAgregarFinal_clicked();

    void on_buttonSave_clicked();

    void on_buttonRead_clicked();

    void on_buttonClean_clicked();

private:
    Ui::Menu *ui;
};
#endif // MENU_H
