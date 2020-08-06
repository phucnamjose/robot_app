#include "serialport.hpp"

#include <QDebug>

SerialPort::SerialPort(QObject *parent):QSerialPort(parent)
{

}

SerialPort::~SerialPort() {
    qDebug() << "COMPORT CLOSE ";
    this->close();
}
