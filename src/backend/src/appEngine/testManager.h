// Begin testManager.h
#ifndef QTESTMANAGER_H
#define QTESTMANAGER_H 1

#include "./../appDataORM/appDataManager.h"
#include <QString>

class TestManager {
    public:
        ~TestManager();
        // Pattern singletone
        static TestManager* getInstance();

        // Admin/teacher/ creates specific challenge
        // [*] testInfo:
        //      > testType   - area of knowledge (education|psychology|funny)
        //      > section    - name of discipline or knowledge area
        //      > subsection - subsection of discipline or knowledge area
        void createChallenge();

        // section
        // subsection
        void runSession();
        bool createSession(const QString&);

    private:
        // Pattern singletone
        static TestManager* p_instance;
        TestManager();
        DataManager* mDataManager;
};



#endif
// End testManager.h
