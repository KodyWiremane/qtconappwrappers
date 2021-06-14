// Copyright © 2021 Alexandr "Kody Wiremane" Shohrov
// Released under terms of LGPL v3

#include "consoleapplication.h"

#include <QTimer>

namespace KodyWiremane
{

    namespace Qt
    {

        int ConsoleApplication::exec()
        {
            QTimer::singleShot(0, this, [this](){exit(flow());});
            return QCoreApplication::exec();
        }

    }

}
