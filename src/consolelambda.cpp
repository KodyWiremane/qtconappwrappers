// Copyright © 2021 Alexandr "Kody Wiremane" Shohrov
// Released under terms of LGPL v3

#include "consolelambda.h"

namespace KodyWiremane
{

    namespace Qt
    {

        ConsoleLambda::ConsoleLambda(int &argc, char *argv[], ConsoleLambdaFlow flowLambda)
            : ConsoleApplication(argc, argv)
            , flowLambda(flowLambda)
        {}

        int ConsoleLambda::exec(ConsoleLambdaFlow flowLambda)
        {
            this->flowLambda = flowLambda;
            return ConsoleApplication::exec();
        }

        int ConsoleLambda::flow()
        {
            return flowLambda(*this);
        }

    }

}
