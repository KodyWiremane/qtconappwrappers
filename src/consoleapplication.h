#ifndef KODYWIREMANE_QT_CONSOLEAPPLICATION_H
#define KODYWIREMANE_QT_CONSOLEAPPLICATION_H

// Copyright © 2021 Alexandr "Kody Wiremane" Shohrov
// Released under terms of LGPL v3

#include <QCoreApplication>

namespace KodyWiremane
{

    namespace Qt
    {

        class ConsoleApplication : public QCoreApplication
        {
        public:
            using QCoreApplication::QCoreApplication;
            int exec();
        protected:
            virtual int flow() = 0;
        };

    }

}

#endif // KODYWIREMANE_QT_CONSOLEAPPLICATION_H
