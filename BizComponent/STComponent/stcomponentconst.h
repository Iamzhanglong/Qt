#ifndef STCOMPONENTCONST_H
#define STCOMPONENTCONST_H

#include <QObject>

class ST : public QObject {
    Q_OBJECT   //必须有
public:
    enum STErrorId
    {
        STError_Emo = 1,
        STError_InterLock,
        STError_WaterLeak,
        STError_Smoke,
        STError_Fan,
        STError_Temp
    };

    enum STState
    {
        STState_normal = 1,
        STState_error = 2
    };

    enum STCommand
    {
        STCommand_clear = 1,
        STCommand_setRed,
        STCommand_setYellow,
        STCommand_setGreen,
        STCommand_setBlue,
        STCommand_setBuzzer,
        STCommand_setMusic
    };

    enum STSignalTowerStatus
    {
        STStatus_on = 1,
        STStatus_off,
        STStatus_blink,
    };

    Q_ENUM(STErrorId)
    Q_ENUM(STState)
    Q_ENUM(STCommand)
    Q_ENUM(STSignalTowerStatus)
};


#endif // STCOMPONENTCONST_H
