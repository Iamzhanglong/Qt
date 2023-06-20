#ifndef STCOMPONENTCONST_H
#define STCOMPONENTCONST_H

#include <QObject>

class STError : public QObject {
    Q_OBJECT   //必须有
public:
    enum STErrorId
    {
        STError_Override = 1,
        STError_WarterLeak = 2,
        STError_AirLeak = 3
    };

    Q_ENUM(STErrorId)
};


#endif // STCOMPONENTCONST_H
