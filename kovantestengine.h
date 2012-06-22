#ifndef KOVANTESTENGINE_H
#define KOVANTESTENGINE_H

#include <QObject>
#include <QVector>
#include <QVectorIterator>
#include "kovantest.h"
class KovanTestWindow;
class KovanTestEngineThread;

class KovanTestEngine : public QObject
{
    Q_OBJECT

private:
    QVector<KovanTest *> tests;
    KovanTest *currentTest;
    int currentTestNumber;
    KovanTestWindow *ui;
    KovanTestEngineThread *currentThread;
	int errorCount;
	bool debugMode;

public:
    KovanTestEngine(KovanTestWindow *ui);
	void setDebug(bool on);
	bool loadAllTests();
    bool runAllTests();

	bool runNextTest(int continueOnErrors = 0);

public slots:
    /* 
       @param level - 0 == info, 1 == error, 2 == debug
       @param value - An error code.  0 for success.
       @param message - An informative message to put up.
    */
    void updateTestState(int level, int value, QString *message);
    void cleanupCurrentTest(void);
};

#endif // KOVANTESTENGINE_H
