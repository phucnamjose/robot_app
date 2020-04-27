#include "robotcontroll.hpp"

// Constructor
RobotControll::RobotControll(QObject *parent):QSerialPort(parent),
    timeout(new QTimer(this))
{
    connect(this, &QSerialPort::readyRead, this, &RobotControll::readData);
    connect(timeout, &QTimer::timeout, this, &RobotControll::timeOut);
}

// Deconstructor
RobotControll::~RobotControll()
{
    delete timeout;
}

// Pack Command
bool RobotControll::packData(QByteArray &data)
{
    if(data.isNull() || data.isEmpty()) {
        M_DEBUG("data input is empty");
        return false;
    }
    // packing
    QByteArray temp;
    temp.append(data);
//    int len = temp.length();
    temp.push_front((char)START_CHAR);
//    while(len) {
//        int i = temp.length()-len;
//        if (temp.at(i) == (char)0x7D || temp.at(i) == (char)0x7E ||
//                temp.at(i) == (char)0x7F) {
//            char mem = temp.at(i);
//            mem ^= (char)0x02;
//            temp.remove(i, 1);
//            temp.insert(i, mem);
//            temp.insert(i, 0x7D);
//        }
//        len--;
//    }
    temp.push_back((char)END_CHAR);
    data.clear();
    data.append(temp);

    Debug::_delete(temp);
    return true;
}

// Unpack Respond
bool RobotControll::unPackData(QByteArray &data)
{
    if(data.isNull() || data.isEmpty()) {
        M_DEBUG("data input is null");
        return false;
    }
    if(data.at(0) != START_CHAR || data.at(data.length()-1) != END_CHAR) {
        M_DEBUG("begin or end charater wrong");
        return false;
    }
    QByteArray temp;

    temp.append(data);
    temp.remove(0, 1);
    temp.remove(temp.length()-1, 1);
//    int len = temp.length();
//    while(len) {
//        int i = temp.length()-len;
//        if (temp.at(i) == (char)0x7D || temp.at(i) == (char)0x7E ||
//                temp.at(i) == (char)0x7F) {
//            char mem = temp.at(i+1);
//            mem ^= (char)0x02;
//            temp.remove(i, 2);
//            temp.insert(i, mem);
//            len--;
//        }
//        len--;
//    }
    data.clear();
    data.append(temp);

    Debug::_delete(temp);
    return true;
}

string RobotControll::qbyteArray2string(QByteArray &data)
{
    return QString::fromLocal8Bit(data).toStdString().c_str();
}

// Send Command to Robot
bool RobotControll::writeData(QByteArray &data) {
    if(this->isOpen()) {
        // Pack Payload
        if( this->packData(data) == false ) {
            M_DEBUG("pack fail");
            return false;
        }
        this->write(data);
        M_DEBUG(qbyteArray2string(data));
    } else {
        M_DEBUG("no device");
        return false;
    }
    return true;
}

// Read Respond from Robot
void RobotControll::readData() {
    if(this->isOpen()) {
        QByteArray data = this->readAll();
        while(data.lastIndexOf(END_CHAR) != -1) {
            QByteArray temp = data.mid(data.lastIndexOf(START_CHAR));
            data.remove(data.lastIndexOf(START_CHAR), data.length());
            // Send Signal
            emit respondArrived(temp);
            // Unpack Payload
            if( this->unPackData(temp) == false ) {
                M_DEBUG("unpack fail");
                Debug::_delete(temp, data);
                return;
            }

            M_DEBUG(qbyteArray2string(temp));
        }
    } else {
        M_DEBUG("no device");
        return;
    }
}

// When Robot doesn't respond
void RobotControll::timeOut()
{
    emit commandTimeOut();
    timeout->stop();
    istimeout = true;
}

// Intergrate parameters to Command
bool RobotControll::setCommand(robotCommand_t cmd, int time, const QString para) {
    QByteArray command;
    command.clear();
    if(para == "") {
        command.append(tr("%1 %2").arg(QString::number(id_command))
                       .arg(ROBOTCOMMAND[cmd]));
    } else {
        command.append(tr("%1 %2 %3").arg(QString::number(id_command))
                       .arg(ROBOTCOMMAND[cmd]).arg(para));
    }
    if(this->writeData(command) == false) {
        M_DEBUG("write data fail");
        Debug::_delete(command);
        return false;
    }
    emit commandSend(command);    // Set Signal
    id_command++;
//    timeout->start(time);
//    istimeout = false;
    Debug::_delete(command);
    return true;
}

//void RobotControll::updateStatus(QString response) {
//    QStringList listRes = response.split(QRegExp("[:]"),
//                                         QString::SplitBehavior::SkipEmptyParts );
//    QString stt = listRes.at(1);
//    for(int i = 0; i < NumOfStt - 1; i++) {
//        if( stt == ROBOTSTATUS[i]) {
//            robot_stt = static_cast<robotStatus_t>(i);
//            M_DEBUG(ROBOTSTATUS[robot_stt]);
//            return;
//        }
//    }
//    stt.clear();
//    stt.resize(0);
//    listRes.clear();
//}

//bool RobotControll::setCommandNWait(robotCommand_t cmd, const QString para)
//{
//    if( this->setCommand(cmd, 3000, para) == false) {
//        M_DEBUG("can't set command");
//        return false;
//    }
//    QEventLoop loop;
//    connect( this, &RobotControll::commandWorkDone, &loop, &QEventLoop::quit );
//    connect( this, &RobotControll::commandTimeOut, &loop, &QEventLoop::quit );
//    loop.exec();
//    if(this->isTimeOut()) {
//        M_DEBUG("work haven't done yet");
//        return false;
//    }
//    M_DEBUG("command done");
//    return true;
//}

/* For user */
void RobotControll::robotResetId() {
    id_command = 1;
}

void    RobotControll::robotSetModeInite(robotModeInit_t type) {
    mode_init = type;
}

void    RobotControll::robotSetAccelerate(double factor) {
    factor_accelerate = factor;
}

void    RobotControll::robotSetVelocity(double factor) {
    factor_velocity = factor;
}

void    RobotControll::robotSetTimeTotal(double time) {
    time_total = time;
}

bool RobotControll::robotStop() {
    if(this->setCommand(this->CMD_STOPNOW, 1000, tr("")) == false ) {
        return false;
    }
   return true;
}

bool RobotControll::robotScanLimit() {
    if(this->setCommand(this->CMD_SCAN, 1000, tr("")) == false ) {
        return false;
    }
   return true;
}

bool RobotControll::robotMoveHome() {
    if(this->setCommand(this->CMD_HOME, 1000, tr("")) == false ) {
        return false;
    }
   return true;
}

bool RobotControll::robotMoveLine(double x, double y, double z, double roll){
    double temp;
    if (mode_init == MODE_INIT_QVA) {
        temp = factor_accelerate;
    } else {
        temp = time_total;
    }
    if(this->setCommand(this->CMD_MOVE_LINE, 1000, tr("%1 %2 %3 %4 %5 %6 %7")
                              .arg(x)
                              .arg(y)
                              .arg(z)
                              .arg(roll)
                              .arg(factor_velocity)
                              .arg(int(mode_init))
                              .arg(temp)) == false ){
        return false;
    }
    return true;
}

bool RobotControll::robotMoveCircle(double x, double y, double z, double roll,
                                    double center_x, double center_y, double center_z,
                                    int8_t direction){
    double temp;
    if (mode_init == MODE_INIT_QVA) {
        temp = factor_accelerate;
    } else {
        temp = time_total;
    }
    if(this->setCommand(this->CMD_MOVE_CIRCLE, 1000, tr("%1 %2 %3 %4 %5 %6 %7 %8 %9 %10 %11")
                                              .arg(x)
                                              .arg(y)
                                              .arg(z)
                                              .arg(roll)
                                              .arg(center_x)
                                              .arg(center_y)
                                              .arg(center_z)
                                              .arg(direction)
                                              .arg(factor_velocity)
                                              .arg(int(mode_init))
                                              .arg(temp)) == false ){
        return false;
    }
    return true;
}

bool RobotControll::robotMoveJoint( double x, double y, double z, double roll){
    double temp;
    if (mode_init == MODE_INIT_QVA) {
        temp = factor_accelerate;
    } else {
        temp = time_total;
    }
    if(this->setCommand(this->CMD_MOVE_JOINT, 1000, tr("%1 %2 %3 %4 %5 %6 %7")
                                              .arg(x)
                                              .arg(y)
                                              .arg(z)
                                              .arg(roll)
                                              .arg(factor_velocity)
                                              .arg(int(mode_init))
                                              .arg(temp)) == false ){
        return false;
    }
    return true;
}

bool RobotControll::robotRotateSingleJoint(int joint, double angle) {
    double temp;
    if (mode_init == MODE_INIT_QVA) {
        temp = factor_accelerate;
    } else {
        temp = time_total;
    }
    if(this->setCommand(this->CMD_ROTATE_SINGLE, 1000, tr("%1 %2 %3 %4 %5")
                              .arg(joint)
                              .arg(angle)
                              .arg(factor_velocity)
                              .arg(int(mode_init))
                              .arg(temp)) == false ){
        return false;
    }
    return true;
}


bool RobotControll::robotOutput(bool output){
    int value = 0;
    if(output){ value = 1;}
    if(this->setCommand(this->CMD_OUTPUT, 1000, tr("%1")
                              .arg(value)) == false ){
        return false;
    }
    return true;
}

bool RobotControll::robotReadStatus(){
    if(this->setCommand(this->CMD_READ_STATUS, 1000, tr("")) == false ) {
        return false;
    }
    return true;
}

bool RobotControll::robotReadPosition(){
    if(this->setCommand(this->CMD_READ_POSITION, 1000, tr("")) == false ) {
        return false;
    }
    return true;
}

bool  RobotControll::robotSetting(robotCoordinate_t coordinate, robotTrajectory_t   trajectory) {
    if(this->setCommand(this->CMD_SETTING, 1000, tr("%1 %2")
                                              .arg(int(coordinate))
                                               .arg(int(trajectory))) == false ){
        return false;
    }
    return true;
}

double RobotControll::robotGetX(){
    return x;
}

double RobotControll::robotGetY(){
    return y;
}

double RobotControll::robotGetZ(){
    return z;
}

double RobotControll::robotGetRoll(){
    return z;
}

double RobotControll::robotGetVar1(){
    return var1;
}

double RobotControll::robotGetVar2(){
    return var2;
}

double RobotControll::robotGetVar3(){
    return var3;
}

double RobotControll::robotGetVar4(){
    return var4;
}
