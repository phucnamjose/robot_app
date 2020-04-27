#ifndef ROBOTCONTROLL_H
#define ROBOTCONTROLL_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include <QTimer>
#include <QEventLoop>

#include <stdio.h>
#include <string.h>
#include <sstream>
#include "debug.hpp"

#define  START_CHAR         (0x28)
#define  END_CHAR            (0x29)


using namespace std;

class RobotControll : public QSerialPort
{
    Q_OBJECT

 public:
    explicit RobotControll(QObject *parent = nullptr);
    virtual ~RobotControll();
    string qbyteArray2string(QByteArray &data);

    enum robotCommand_t {
        CMD_STOPNOW = 0,
        CMD_SCAN,
        CMD_HOME,
        CMD_MOVE_LINE,
        CMD_MOVE_CIRCLE,
        CMD_MOVE_JOINT,
        CMD_ROTATE_SINGLE,
        CMD_OUTPUT,
        CMD_READ_STATUS,
        CMD_READ_POSITION,
        CMD_SETTING,
        NUM_OF_CMD, // = 11 CMD
    };

    const char *ROBOTCOMMAND[NUM_OF_CMD] = {
        "STOP",
        "SCAN",
        "HOME",
        "MOVL",
        "MOVC",
        "MOVJ",
        "ROTA",
        "OUTP",
        "READ",
        "POSI",
        "SETT"
    };

    enum robotRespond_t {
        RPD_IDLE = 0,
        RPD_BUSY,
        RPD_START,
        RPD_RUNNING,
        RPD_STOP,
        RPD_DONE,
        RPD_ERROR,
        RPD_OK,
        RPD_POSITION,
        NUM_OF_RPD, // = 9 RPD
    };

    const char *ROBOTRESPOND[NUM_OF_RPD] = {
        "IDLE",
        "BUSY",
        "STAR",
        "RUNN",
        "STOP",
        "DONE",
        "ERRO",
        "OKAY",
        "POSI"
    };

    enum robotCoordinate_t {
          COORDINATES_ABS = 0,  /*!< Absolute position */
          COORDINATES_REL       /*!< Relative position*/
    };

    enum robotTrajectory_t {
          TRAJECTORY_LSPB	= 0,
          TRAJECTORY_SCURVE
    };

    enum robotModeInit_t {
          MODE_INIT_QVA	= 0, /*!< Consume A max, determine T max */
          MODE_INIT_QVT     /*!< Consume T max, determine A max */
    };



  signals:
            void    commandTimeOut();
            void    commandWorkStart();
            void    commandWorkRunning();
            void    commandWorkStop();
            void    commandWorkDone();
            void    commandSend(QByteArray command);
            void    respondArrived(QByteArray repsond);

private:
            bool    packData(QByteArray &data);
            bool    unPackData(QByteArray &data);
            bool    writeData(QByteArray &data);
            void    readData();
            void    timeOut();
            bool   setCommand(robotCommand_t cmd, int time, const QString para = "");
//            bool    setCommandNWait(robotCommand_t cmd, const QString para = "");

 public:
            void    robotResetId();
            void    robotSetModeInite(robotModeInit_t type);
            void    robotSetAccelerate(double factor);
            void    robotSetVelocity(double factor);
            void    robotSetTimeTotal(double time);

            bool    robotStop();
            bool    robotScanLimit();
            bool    robotMoveHome();
            bool    robotMoveLine(double x, double y, double z, double roll);

            bool    robotMoveCircle(double x, double y, double z, double roll,
                                                            double center_x, double center_y, double center_z,
                                                            int8_t direction);

            bool    robotMoveJoint(double x, double y, double z, double roll);
            bool    robotRotateSingleJoint  (int joint, double angle);
            bool    robotOutput(bool output);
            bool    robotReadStatus();
            bool    robotReadPosition();
            bool    robotSetting(robotCoordinate_t coordinate, robotTrajectory_t   trajectory);

            double  robotGetX();
            double  robotGetY();
            double  robotGetZ();
            double  robotGetRoll();
            double  robotGetVar1();
            double  robotGetVar2();
            double  robotGetVar3();
            double  robotGetVar4();

 private:
            QTimer     *timeout;
            robotModeInit_t     mode_init = MODE_INIT_QVA;

            int              id_command  = 1;
            bool          istimeout         = false;
            double     x, y, z, roll;
            double     var1, var2, var3, var4;
            double     factor_accelerate = 0.3;
            double     factor_velocity      = 0.3;
            double     time_total               = 10;
};

#endif // ROBOTCONTROLL_H
