#ifndef STCOMPONENTCONST_H
#define STCOMPONENTCONST_H

#include <QObject>

class ST : public QObject {
    Q_OBJECT   //必须有
public:
    enum STErrorId
    {
        STError_Emo = 1,
        STError_InterLock1,
        STError_InterLock2,
        STError_InterLock3,
        STError_InterLock4,
        STError_InterLock5,
        STError_InterLock6,
        STError_WaterLeak1,
        STError_WaterLeak2,
        STError_WaterLeak3,
        STError_WaterLeak4,
        STError_WaterLeak5,
        STError_WaterLeak6,
        STError_WaterLeak7,
        STError_WaterLeak8,
        STError_Smoke1,
        STError_Smoke2,
        STError_Smoke3,
        STError_PWCRFan,
        STError_WSPR1Fan,
        STError_WSPR2Fan,
        STError_ECABTemp,
        STError_PMCRTemp,
        STError_WSPR1Temp,
        STError_WSPR2Temp,
        STError_WHCRTemp
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
