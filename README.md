# Qt Console Application Wrappers
Released under terms of **LGPL v3**.

The classes here incapsulate a boilerplate code required to execute a routine under Qt's `QCoreApplication`, inside the event loop.

Solutions I've seen use `QTimer` to trigger execution when the event loop starts. So here I do the same, but wrapped into these classes.

As my path as a programmer is pretty short, do not expect this code to be all pro and clever. It is just a laboratory research of mine.

## KW::Qt::ConsoleApplication

`ConsoleApplication` is suitable with bigger applications where you want to make a good use of various class members. It derives from `QCoreApplication`, and calls `ConsoleApplication::flow()` after the event loop starts. Derive from `ConsoleApplication`, and override the `flow()` method. Return value of `flow()` becomes the exit code of the application.

```c++
// myapplication.h
#include "consoleapplication.h"

namespace KW = KodyWiremane::Qt;

class MyApplication : public KW::ConsoleApplication
{
public:
    using KW::ConsoleApplication::ConsoleApplication;
protected:
    int flow() override;
};
```

```c++
// myapplication.cpp
#include "myapplication.h"

#include <QTextStream>

int MyApplication::flow() {
    QTextStream(stdout) << "Hello, world!" << Qt::endl;
    return 0;
}
```

```c++
// main.cpp
#include "myapplication.h"

int main(int argc, char *argv[])
{
    MyApplication app(argc, argv);

    return app.exec();
}
```

## KW::Qt::ConsoleLambda

ConsoleLambda is for supposedly shorter routines which are passed to the class as lambdas:

```c++
// main.cpp
#include "consolelambda.h"

#include <QTextStream>

namespace KW = KodyWiremane::Qt;

int main(int argc, char *argv[])
{
    KW::ConsoleLambda clapp(argc, argv, [](QCoreApplication &app){
        QTextStream(stdout) << app.arguments().at(0) << Qt::endl;
        return 0;
    });

    return clapp.exec();
}
```

Alternatively,

```c++
// main.cpp
// …

int main(int argc, char *argv[])
{
    KW::ConsoleLambda clapp(argc, argv);

    return clapp.exec([](QCoreApplication &app){
        QTextStream(stdout) << app.arguments().at(0) << Qt::endl;
        return 0;
    });
}
```

## std::bad_function_call

Failing to pass a valid lambda either on construction or on `exec(…)` call will lead to throwing `std::bad_function_call` exception.
