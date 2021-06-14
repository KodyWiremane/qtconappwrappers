#ifndef KODYWIREMANE_QT_CONSOLELAMBDA_H
#define KODYWIREMANE_QT_CONSOLELAMBDA_H

// Copyright © 2021 Alexandr "Kody Wiremane" Shohrov
// Released under terms of LGPL v3

#include <consoleapplication.h>

#include <QCoreApplication>

namespace KodyWiremane
{

    namespace Qt
    {

        typedef std::function<int (QCoreApplication &)> ConsoleLambdaFlow;

        class ConsoleLambda : public ConsoleApplication
        {
        public:
            ConsoleLambda(int &argc, char *argv[], ConsoleLambdaFlow flowLambda = nullptr);
            using ConsoleApplication::exec;
            int exec(ConsoleLambdaFlow flowLambda);
        protected:
            using ConsoleApplication::ConsoleApplication;
            int flow() override;
            ConsoleLambdaFlow flowLambda;
        };

    }

}

#endif // KODYWIREMANE_QT_CONSOLELAMBDA_H
