#ifndef STCOMPONENTCONST_H
#define STCOMPONENTCONST_H

#include <QObject>

class ST : public QObject {
    Q_OBJECT   //必须有
public:
    enum STErrorId
    {
        STError_Override = 1,
        STError_WarterLeak = 2,
        STError_AirLeak = 3
    };

    enum STState
    {
        STState_normal = 1,
        STState_error = 2
    };

    enum STCommand
    {
        STCommand_setRed,
        STCommand_setBlue,
        STCommand_setYellow
    };

    Q_ENUM(STErrorId)
    Q_ENUM(STState)
    Q_ENUM(STCommand)
};


#endif // STCOMPONENTCONST_H
