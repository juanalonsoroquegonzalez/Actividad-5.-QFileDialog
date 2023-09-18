#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <list>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

#include "menu.h"
#include "./ui_menu.h"

Menu::Menu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Menu)
{
    ui->setupUi(this);
}

Menu::~Menu()
{
    delete ui;
}

class Neurona
{
private:
    int id;
    float voltaje;
    int posicion_x;
    int posicion_y;
    int red;
    int green;
    int blue;

public:
    Neurona(int _id, float _voltaje, int _posicion_x, int _posicion_y, int _red, int _green, int _blue)
        : id(_id), voltaje(_voltaje), posicion_x(_posicion_x), posicion_y(_posicion_y), red(_red), green(_green), blue(_blue){
    }
    int getID() const{
        return id;
    }
    float getVoltaje() const{
        return voltaje;
    }
    int getPosicion_x() const{
        return posicion_x;
    }
    int getPosicion_y() const{
        return posicion_y;
    }
    int getRed() const{
        return red;
    }
    int getGreen() const{
        return green;
    }
    int getBlue() const{
        return blue;
    }
    void print() const {
        std::cout << "ID: " << id << std::endl;
        std::cout << "Voltaje: " << voltaje << std::endl;
        std::cout << "Posici�n X: " << posicion_x << std::endl;
                std::cout << "Posici�n Y: " << posicion_y << std::endl;
                         std::cout << "Red: " << red << std::endl;
        std::cout << "Green: " << green << std::endl;
        std::cout << "Blue: " << blue << std::endl;
    }
};

class AdministradorNeuronas {
private:
    std::list<Neurona> listaNeuronas;

public:
    void agregarInicio(const Neurona& neurona) {
        listaNeuronas.push_front(neurona);
    }

    void agregarFinal(const Neurona& neurona) {
        listaNeuronas.push_back(neurona);
    }

    void mostrar() {
        for (const Neurona& neurona : listaNeuronas) {
            neurona.print();
            std::cout << "-------------------" << std::endl;
        }
    }
};

void agregarNeurona()
{

}

void Menu::on_buttonAgregar_clicked()
{
    if(ui->lineID->text().isEmpty() || ui->lineVoltaje->text().isEmpty() || ui->lineX->text().isEmpty() || ui->lineY->text().isEmpty() || ui->lineRed->text().isEmpty() || ui->lineGreen->text().isEmpty() || ui->lineBlue->text().isEmpty()){
        ui->labelVerificar->setText("Datos incompletos");
    }
    else {
        ui->labelVerificar->setText("");
        AdministradorNeuronas administrador;

        QString id = ui->lineID->text();
        QString voltaje = ui->lineVoltaje->text();
        QString x = ui->lineX->text();
        QString y = ui->lineY->text();
        QString red = ui->lineRed->text();
        QString green = ui->lineGreen->text();
        QString blue = ui->lineBlue->text();

        Neurona neuronas(id.toInt(), voltaje.toInt(), x.toInt(), y.toInt(), red.toInt(), green.toInt(), blue.toInt());

        administrador.agregarInicio(neuronas);

        // Formatear la información de las neuronas en una cadena de texto
        QString infoNeurona = "---------------------------\nID: " + id + "\n"
                              + "Voltaje: " + voltaje + "\n"
                              + "Posición X: " + x + "\n"
                              + "Posición Y: " + y + "\n"
                              + "Red: " + red + "\n"
                              + "Green: " + green + "\n"
                              + "Blue: " + blue + "\n"
                              + "---------------------------\n";


        agregarNeurona();
        ui->textNeuronas->moveCursor(QTextCursor::Start);
        ui->textNeuronas->insertPlainText(infoNeurona);

        QMessageBox::warning(nullptr, "Valido!", "Neurona agregada");

        ui->lineID->setText("");
        ui->lineVoltaje->setText("");
        ui->lineX->setText("");
        ui->lineY->setText("");
        ui->lineRed->setText("");
        ui->lineGreen->setText("");
        ui->lineBlue->setText("");

        std::cout << "Neuronas: \n";
        administrador.mostrar();
    }
}





void Menu::on_textNeuronas_textChanged()
{

}


void Menu::on_buttonAgregarFinal_clicked()
{
    if(ui->lineID->text().isEmpty() || ui->lineVoltaje->text().isEmpty() || ui->lineX->text().isEmpty() || ui->lineY->text().isEmpty() || ui->lineRed->text().isEmpty() || ui->lineGreen->text().isEmpty() || ui->lineBlue->text().isEmpty()){
        ui->labelVerificar->setText("Datos incompletos");
    }
    else {
        ui->labelVerificar->setText("");
        AdministradorNeuronas administrador;

        QString id = ui->lineID->text();
        QString voltaje = ui->lineVoltaje->text();
        QString x = ui->lineX->text();
        QString y = ui->lineY->text();
        QString red = ui->lineRed->text();
        QString green = ui->lineGreen->text();
        QString blue = ui->lineBlue->text();

        Neurona neuronas(id.toInt(), voltaje.toInt(), x.toInt(), y.toInt(), red.toInt(), green.toInt(), blue.toInt());

        administrador.agregarInicio(neuronas);

        // Formatear la información de las neuronas en una cadena de texto
        QString infoNeurona = "---------------------------\nID: " + id + "\n"
                              + "Voltaje: " + voltaje + "\n"
                              + "Posición X: " + x + "\n"
                              + "Posición Y: " + y + "\n"
                              + "Red: " + red + "\n"
                              + "Green: " + green + "\n"
                              + "Blue: " + blue + "\n"
                              + "---------------------------\n";


        agregarNeurona();
        ui->textNeuronas->append(infoNeurona);

        QMessageBox::warning(nullptr, "Valido!", "Neurona agregada");

        ui->lineID->setText("");
        ui->lineVoltaje->setText("");
        ui->lineX->setText("");
        ui->lineY->setText("");
        ui->lineRed->setText("");
        ui->lineGreen->setText("");
        ui->lineBlue->setText("");

        std::cout << "Neuronas: \n";
        administrador.mostrar();
    }
}


void Menu::on_buttonSave_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Guardar archivo de texto"), "", tr("Archivos de Texto (*.txt);;Todos los archivos (*)"));

    if (fileName.isEmpty()) {
        // El usuario canceló la selección del archivo
        return;
    }

    // Abre el archivo en modo escritura
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, tr("Error"), tr("No se pudo abrir el archivo para escritura."));
        return;
    }

    // Obtiene el contenido del QTextEdit
    QString contenido = ui->textNeuronas->toPlainText();

    // Escribe el contenido en el archivo
    QTextStream out(&file);
    out << contenido;

    ui->textNeuronas->clear();

    // Cierra el archivo
    file.close();

    QMessageBox::information(this, tr("Guardado"), tr("El contenido se ha guardado en el archivo correctamente."));
}


void Menu::on_buttonRead_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Cargar archivo de texto"), "", tr("Archivos de Texto (*.txt);;Todos los archivos (*)"));

    if (fileName.isEmpty()) {
        // El usuario canceló la selección del archivo
        return;
    }

    // Abre el archivo en modo lectura
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, tr("Error"), tr("No se pudo abrir el archivo para lectura."));
        return;
    }

    // Lee el contenido del archivo
    QTextStream in(&file);
    QString contenido = in.readAll();

    // Cierra el archivo
    file.close();

    // Coloca el contenido en el QTextEdit
    ui->textNeuronas->clear();
    ui->textNeuronas->setPlainText(contenido);

    QMessageBox::information(this, tr("Cargado"), tr("El contenido se ha cargado desde el archivo correctamente."));
}


void Menu::on_buttonClean_clicked()
{
    ui->textNeuronas->clear();
}

