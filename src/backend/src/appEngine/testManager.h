// Begin testManager.h
#ifndef QTESTMANAGER_H
#define QTESTMANAGER_H 1

class TestManager {
    public:
        TestManager();
        ~TestManager();

        // Admin/teacher/ creates specific challange
        // [*] testInfo:
        //      > testType   - area of knowledge (education|psychology|funny)
        //      > section    - name of discipline or knowledge area
        //      > subsection - subsection of discipline or knowledge area
        void createChallenge();

        // section
        // subsection
        void runSession();

        void createSession();

};



#endif
// End testManager.h
